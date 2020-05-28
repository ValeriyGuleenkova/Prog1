class CVector0 : public CVector
{
public:
	CVector0(string FileName1, int length1, double *num1);
	CVector0();
	void output();
	using CVector::operator =;
	CVector0(const CVector& other);
};
