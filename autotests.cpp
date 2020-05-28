#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"
#include "functions.hpp"

void autotest1()
{
	double* num1;
	double* num2;
	num1 = new double[5];
	num2 = new double[5];
	for (int i = 0; i < 5; i++)
	{
		num1[i]=1.4;
		num2[i]=1.1;
	}
	string str1 = "str1.txt";
	string str2 = "str2.txt";
	int flag = 0;
	CVector1 a(str1, 5, num1);
	CVector1 b(str2, 5, num2);
	CVector0 c;
	c = a - b;
	for (int i = 0; i < c.length; i++) if (abs(c.num[i] - 0.3) < std::numeric_limits<double>::epsilon()) 
	{
		flag++;
	};

	if (flag == 5) printf("Test 1 complete!\n");
	else printf("Test 1 fail!\n");

	return;
}

void autotest2()
{
	double* num1;
	double* num2;
	num1 = new double[5];
	num2 = new double[5];
	num1[0] = 1.5; num1[1] = 2.5; num1[2] = 3.5; num1[3] = 4.5; num1[4] = 5.5;
	num2[0] = 8.5; num2[1] = 7.5; num2[2] = 6.5; num2[3] = 5.5; num2[4] = 4.5;
	string str1 = "str1.txt";
	string str2 = "str2.txt";
	int flag = 0;

	CVector0 a(str1, 5, num1);
	CVector0 b(str2, 5, num2);
	CVector1 c = a + b;

	for (int i = 0; i < c.length; i++) if (abs(c.num[i] - 10.0) < std::numeric_limits<double>::epsilon()) {
		flag++;
	}
	else {
		//cout << c.num[i] << endl;
	};
	if (flag == 5) printf("Test 2 complete!\n");
	else printf("Test 2 fail!\n");

	return;
}

void autotest3()
{
	double* num1;
	double* num2;
	num1 = new double[5];
	num2 = new double[5];
	num1[0] = 1.0; num1[1] = 1.0; num1[2] = 1.0; num1[3] = 1.0; num1[4] = 1.0;
	num2[0] = 6.0; num2[1] = 6.0; num2[2] = 1.0; num2[3] = 9.0; num2[4] = 3.0;
	string str1 = "str1.txt";
	string str2 = "str2.txt";

	CVector1 a(str1, 5, num1);
	CVector0 b(str2, 5, num2);
	double c = a * b;

	if (abs(c - 25.0) < std::numeric_limits<double>::epsilon()) printf("Test 3 complete!\n");
	else printf("Test 3 fail!\n");

	return;
}

void autotest4()
{
	double* num1;
	double* num2;
	num1 = new double[5];
	num2 = new double[5];
	num1[0] = 1; num1[1] = 2; num1[2] = 3; num1[3] = 4; num1[4] = 5;
	num2[0] = 6; num2[1] = 6; num2[2] = 1; num2[3] = 9; num2[4] = 3;
	string str1 = "str1.txt";
	string str2 = "str2.txt";

	CVector1 a(str1, 5, num1);
	CVector0 b(str2, 5, num2);
	CVector0 c = a + b;

	if (c.FileName == "str1.txt") { printf("Test 4 complete!\n"); }
	else printf("Test 4 fail!\n");

	return;
}