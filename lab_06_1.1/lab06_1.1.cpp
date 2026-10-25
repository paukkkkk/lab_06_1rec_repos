#include <iostream>
#include <time.h>
#include <iomanip> 

using namespace std;
void Create(int* x, const int size, const int Low, const int High, int i);
void Print(int* x, const int size, int i);
bool Check(const int value);
int Count(int* x, const int size, int i);
int Sum(int* x, const int size, int i);
void ZeroOut(int* x, const int size, int i);


int main()
{
	srand((unsigned)time(NULL)); 

	const int n = 24;
	int x[n];

	int Low = -17;
	int High = 53;

	Create(x, n, Low, High, 0);
	Print(x, n, 0);

	cout << "amount= " << Count(x, n, 0) << endl;
	cout << "sum= " << Sum(x, n, 0) << endl;

	ZeroOut(x, n, 0);
	cout << "changed massive" << endl;
	Print(x, n, 0);

	return 0;
}


void Create(int *x, const int size, const int Low, const int High, int i)
{
	x[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(x, size, Low, High, i + 1);
}


void Print(int *x, const int size, int i)
{
	cout << "x[" << setw(2) << i << "] = " << setw(4) << x[i] << endl;
	if (i < size - 1)
		Print(x, size, i + 1);
	else
		cout << endl;
}

bool Check(const int value)
{
	return value < 0 && value % 3 != 0;
}

int Count(int* x, const int size, int i)
{
	if (i < size)
	{
		if (Check(x[i]))
			return 1 + Count(x, size, i + 1);
		else
			return Count(x, size, i + 1);
	}
	else
		return 0;
}

int Sum(int* x, const int size, int i)
{
	if (i < size)
	{
		if (Check(x[i]))
			return x[i] + Sum(x, size, i + 1);
		else
			return Sum(x, size, i + 1);
	}
	else
		return 0;
}

void ZeroOut(int* x, const int size, int i)
{
	if (i < size)
	{
		if (Check(x[i]))
			x[i] = 0;
		ZeroOut(x, size, i + 1);
	}
}