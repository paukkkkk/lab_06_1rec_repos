#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_06_1.1/lab06_1.1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

bool Check(const int value);
int Count(int* x, const int size, int i);
int Sum(int* x, const int size, int i);
void ZeroOut(int* x, const int size, int i);

namespace UnitTest0611
{
	TEST_CLASS(UnitTest0611)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(Check(-4));

			// -12 НЕ підходить (ділиться на 3 націло)
			Assert::IsFalse(Check(-12));

			// 5 додатне — не підходить
			Assert::IsFalse(Check(5));

			// 0 — не підходить
			Assert::IsFalse(Check(0));
		}
		// 2. Тест для перевірки підрахунку кількості (Count) та суми (Sum)
		TEST_METHOD(TestMethod_CountAndSum)
		{
			const int size = 5;
			int x[size] = { -4, 10, -12, -7, 3 };
			// Аналіз елементів за критерієм (-17 ... 53, від'ємні, не кратні 3):
			// -4  -> підходить (1)
			// 10  -> додатне (ні)
			// -12 -> кратне 3 (ні)
			// -7  -> підходить (2)
			// 3   -> додатне, кратне 3 (ні)
			// Очікувана кількість: 2
			// Очікувана сума: -4 + (-7) = -11

			int actualCount = Count(x, size, 0);
			int actualSum = Sum(x, size, 0);

			Assert::AreEqual(2, actualCount);
			Assert::AreEqual(-11, actualSum);
		}

		// 3. Тест для перевірки заміни нулями (ZeroOut)
		TEST_METHOD(TestMethod_ZeroOut)
		{
			const int size = 3;
			int x[size] = { -4, -12, 5 };
			// -4 задовольняє критерію -> стане 0
			// -12 кратне 3 -> не зміниться
			// 5 додатне -> не зміниться

			ZeroOut(x, size, 0);

			Assert::AreEqual(0, x[0]);
			Assert::AreEqual(-12, x[1]);
			Assert::AreEqual(5, x[2]);
		}
	};
}
