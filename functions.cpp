#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"
#include "functions.hpp"
#include "CVectorfactory.hpp"
#include "CVector0factory.hpp"
#include "CVector1factory.hpp"

CVector0 operator- (const CVector& first, const CVector& second)
{
	CVector0 res;
	res.num = first.num;
	res.length = first.length;
	res.FileName = first.FileName;
	for (int i = 0; i < first.length; i++)
	{
		res.num = new double[first.length];
	}
	if (first.length != second.length)
	{
		cout << "+ ERROR: WRONG LENGTHS" << endl;
	}
	else
	{
		for (int i = 0; i < first.length; i++)
		{
			res.num[i] = first.num[i] - second.num[i];
		}
	}
	return res;
}

CVector0 operator+ (const CVector& first, const CVector& second)
{

	CVector0 res;
	res.num = first.num;
	res.length = first.length;
	res.FileName = first.FileName;
	for (int i = 0; i < first.length; i++)
	{
		res.num = new double[first.length];
	}
	if (first.length != second.length)
	{
		cout << "+ ERROR: WRONG LENGTHS" << endl;
	}
	else
	{
		for (int i = 0; i < first.length; i++)
		{
			res.num[i] = first.num[i] + second.num[i];
		}
	}
	return res;
}

CVector** ReadFile(){

	int flag = 0;
	CVector0Factory Hori;
	CVector1Factory Vert;
	map<string, Factory*> factories_ = { {"Hori",&Hori},{"Vert",&Vert} };
	ifstream in("input.txt");
	if (!in)
	{
		cout << "FILE ERROR!" << endl;
		flag = 1;
	}
	CVector **arr;
	arr = new CVector*[256];
	if (flag == 0)
	{
		double m;
		string I;
		int length;
		string str;
		while (!in.eof())
		{
			double* num;
			in >> I;
			in >> str;
			in >> length;
			num = new double[length];
			for (int i = 0; i < length; i++)
			{
				in >> m;
				num[i] = m;
			}
			auto resFactory = factories_[I];
			auto newVector = resFactory->Create();
			newVector->num = num;
			newVector->length = length;
			newVector->FileName = str;
			for (int i = 0; i < 255; i++)
			{
				arr[i] = newVector;
			}
			for (int i = 0; i < length; i++)
			{
				arr[i]->output();
			}
			delete[] num;
			
		}
	}
	return arr;
}