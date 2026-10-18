
#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP2.1/Goods.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GoodsUnitTests
{
    TEST_CLASS(GoodsTests)
    {
    public:

        // Перевірка конструктора без аргументів
        TEST_METHOD(TestDefaultConstructor)
        {
            Goods g;

            Assert::AreEqual(1.0, g.getFirst());
            Assert::AreEqual(1u, g.getSecond());
        }

        // Перевірка конструктора ініціалізації
        TEST_METHOD(TestInitializationConstructor)
        {
            Goods g(10.5, 3);

            Assert::AreEqual(10.5, g.getFirst());
            Assert::AreEqual(3u, g.getSecond());
        }

        // Перевірка конструктора копіювання
        TEST_METHOD(TestCopyConstructor)
        {
            Goods g1(15.0, 4);
            Goods g2(g1);

            Assert::AreEqual(g1.getFirst(), g2.getFirst());
            Assert::AreEqual(g1.getSecond(), g2.getSecond());
        }

        // Перевірка коректного встановлення ціни
        TEST_METHOD(TestSetFirstValid)
        {
            Goods g;

            Assert::IsTrue(g.setFirst(25.0));
            Assert::AreEqual(25.0, g.getFirst());
        }

        // Некоректна ціна не повинна змінювати поле
        TEST_METHOD(TestSetFirstInvalid)
        {
            Goods g(10.0, 2);

            Assert::IsFalse(g.setFirst(-5.0));
            Assert::AreEqual(10.0, g.getFirst());
        }

        // Перевірка коректного встановлення кількості
        TEST_METHOD(TestSetSecondValid)
        {
            Goods g;

            Assert::IsTrue(g.setSecond(5));
            Assert::AreEqual(5u, g.getSecond());
        }

        // Нульова кількість не повинна змінювати поле
        TEST_METHOD(TestSetSecondInvalid)
        {
            Goods g(10.0, 2);

            Assert::IsFalse(g.setSecond(0));
            Assert::AreEqual(2u, g.getSecond());
        }

        // Перевірка Init()
        TEST_METHOD(TestInit)
        {
            Goods g;

            Assert::IsTrue(g.Init(12.5, 4));
            Assert::AreEqual(12.5, g.getFirst());
            Assert::AreEqual(4u, g.getSecond());
        }

        // Некоректний Init() не змінює поля
        TEST_METHOD(TestInitInvalid)
        {
            Goods g(10.0, 3);

            Assert::IsFalse(g.Init(-1.0, 5));
            Assert::AreEqual(10.0, g.getFirst());
            Assert::AreEqual(3u, g.getSecond());
        }

        // Перевірка обчислення вартості
        TEST_METHOD(TestCost)
        {
            Goods g(12.5, 4);

            Assert::AreEqual(50.0, g.cost());
        }

        // Перевірка оператора присвоєння
        TEST_METHOD(TestAssignment)
        {
            Goods g1(20.0, 5);
            Goods g2;

            g2 = g1;

            Assert::AreEqual(20.0, g2.getFirst());
            Assert::AreEqual(5u, g2.getSecond());
        }

        // Префіксний інкремент змінює first
        TEST_METHOD(TestPrefixIncrement)
        {
            Goods g(10.0, 3);

            ++g;

            Assert::AreEqual(11.0, g.getFirst());
            Assert::AreEqual(3u, g.getSecond());
        }

        // Префіксний декремент змінює first
        TEST_METHOD(TestPrefixDecrement)
        {
            Goods g(10.0, 3);

            --g;

            Assert::AreEqual(9.0, g.getFirst());
            Assert::AreEqual(3u, g.getSecond());
        }

        // Постфіксний інкремент змінює second
        TEST_METHOD(TestPostfixIncrement)
        {
            Goods g(10.0, 3);

            Goods old = g++;

            Assert::AreEqual(10.0, old.getFirst());
            Assert::AreEqual(3u, old.getSecond());
            Assert::AreEqual(10.0, g.getFirst());
            Assert::AreEqual(4u, g.getSecond());
        }

        // Постфіксний декремент змінює second
        TEST_METHOD(TestPostfixDecrement)
        {
            Goods g(10.0, 3);

            Goods old = g--;

            Assert::AreEqual(10.0, old.getFirst());
            Assert::AreEqual(3u, old.getSecond());
            Assert::AreEqual(10.0, g.getFirst());
            Assert::AreEqual(2u, g.getSecond());
        }

        // Перевірка перетворення у string
        TEST_METHOD(TestStringConversion)
        {
            Goods g(10.0, 2);

            string s = static_cast<string>(g);

            Assert::IsTrue(s.find("Price") != string::npos);
            Assert::IsTrue(s.find("Quantity") != string::npos);
            Assert::IsTrue(s.find("Cost") != string::npos);
        }

        // Перевірка зовнішньої функції makeGoods()
        TEST_METHOD(TestMakeGoods)
        {
            Goods g = makeGoods(8.0, 6);

            Assert::AreEqual(8.0, g.getFirst());
            Assert::AreEqual(6u, g.getSecond());
        }
    };
}
