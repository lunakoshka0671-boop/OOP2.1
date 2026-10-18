
#include <iostream>
#include <string>
#include "Goods.h"

using namespace std;

struct GoodsLayout
{
    double first;
    unsigned int second;
};

#pragma pack(push, 1)
struct GoodsPackedLayout
{
    double first;
    unsigned int second;
};
#pragma pack(pop)

int main()
{
    // Конструктор без аргументів
    Goods g1;
    cout << "g1:\n" << g1;

    // Конструктор ініціалізації
    Goods g2(10.5, 3);
    cout << "\ng2:\n" << g2;

    // Конструктор копіювання
    Goods g3(g2);
    cout << "\ng3 (copy of g2):\n" << g3;

    // Функція створення об'єкта
    Goods g4 = makeGoods(20.0, 5);
    cout << "\ng4:\n" << g4;

    // Присвоєння
    g1 = g2;
    cout << "\ng1 after assignment:\n" << g1;

    // Методи доступу
    cout << "\nGetters:\n";
    cout << "Price = " << g2.getFirst() << endl;
    cout << "Quantity = " << g2.getSecond() << endl;

    // Методи запису
    g2.setFirst(12.0);
    g2.setSecond(6);
    cout << "\nAfter setters:\n";
    g2.Display();

    // Init()
    g2.Init(15.0, 2);
    cout << "\nAfter Init():\n";
    g2.Display();

    // Перетворення в string
    string s = static_cast<string>(g2);
    cout << "\nString conversion:\n" << s;

    // Префіксний інкремент
    cout << "\n++g2:\n";
    ++g2;
    cout << g2;

    // Префіксний декремент
    cout << "\n--g2:\n";
    --g2;
    cout << g2;

    // Постфіксний інкремент
    cout << "\ng2++:\n";
    g2++;
    cout << g2;

    // Постфіксний декремент
    cout << "\ng2--:\n";
    g2--;
    cout << g2;

    // Введення з клавіатури
    Goods g5;
    cout << "\nEnter goods data:\n";
    g5.Read();

    cout << "\nEntered goods:\n";
    g5.Display();

    // Масив об'єктів
    Goods arr[3] = {
        Goods(5.0, 2),
        Goods(7.5, 4),
        Goods(g3)
    };

    cout << "\nArray of Goods:\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\nObject " << i + 1 << ":\n";
        cout << arr[i];
    }

    // Розміри структур із двома полями
    cout << "\nSize without packing: "
        << sizeof(GoodsLayout) << " bytes\n";

    cout << "Size with #pragma pack(1): "
        << sizeof(GoodsPackedLayout) << " bytes\n";

    cout << "Actual sizeof(Goods): "
        << sizeof(Goods) << " bytes\n";

    return 0;
}

