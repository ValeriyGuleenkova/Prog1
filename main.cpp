#include "CVector.hpp"
#include "CVector0.hpp"
#include "CVector1.hpp"
#include "functions.hpp"
#include "autotests.hpp"

int main()
{
	autotest1();
	autotest2();
	autotest3();
	autotest4();
	CVector** arr = ReadFile();
	cout << "done final" << endl;
	return 0;
}
