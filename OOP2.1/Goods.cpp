
#include "Goods.h"
#include <sstream>
#include <cstdlib>

Goods::Goods()
{
    first = 1.0;
    second = 1;
}

Goods::Goods(double price, unsigned int quantity)
{
    first = 1.0;
    second = 1;
    Init(price, quantity);
}

Goods::Goods(const Goods& other)
{
    first = other.first;
    second = other.second;
}

bool Goods::setFirst(double value)
{
    if (value > 0)
    {
        first = value;
        return true;
    }
    return false;
}

bool Goods::setSecond(unsigned int value)
{
    if (value > 0)
    {
        second = value;
        return true;
    }
    return false;
}

double Goods::getFirst() const
{
    return first;
}

unsigned int Goods::getSecond() const
{
    return second;
}

bool Goods::Init(double price, unsigned int quantity)
{
    if (price <= 0 || quantity == 0)
        return false;

    first = price;
    second = quantity;
    return true;
}

void Goods::Read()
{
    cin >> *this;
}

void Goods::Display() const
{
    cout << *this;
}

double Goods::cost() const
{
    return first * second;
}

Goods& Goods::operator=(const Goods& other)
{
    if (this != &other)
    {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Goods::operator string() const
{
    stringstream ss;
    ss << "Price = " << first << '\n';
    ss << "Quantity = " << second << '\n';
    ss << "Cost = " << cost() << '\n';
    return ss.str();
}

// Префіксний інкремент змінює first
Goods& Goods::operator++()
{
    first += 1.0;
    return *this;
}

// Префіксний декремент змінює first
Goods& Goods::operator--()
{
    if (first > 1.0)
        first -= 1.0;

    return *this;
}

// Постфіксний інкремент змінює second
Goods Goods::operator++(int)
{
    Goods temp(*this);
    ++second;
    return temp;
}

// Постфіксний декремент змінює second
Goods Goods::operator--(int)
{
    Goods temp(*this);

    if (second > 1)
        --second;

    return temp;
}

istream& operator>>(istream& in, Goods& goods)
{
    double price;
    int quantity;

    cout << "Price = ";
    in >> price;

    cout << "Quantity = ";
    in >> quantity;

    if (in && price > 0 && quantity > 0)
    {
        goods.first = price;
        goods.second = static_cast<unsigned int>(quantity);
    }
    else if (in)
    {
        in.setstate(ios::failbit);
    }

    return in;
}

ostream& operator<<(ostream& out, const Goods& goods)
{
    out << string(goods);
    return out;
}

Goods makeGoods(double price, unsigned int quantity)
{
    Goods goods;

    if (!goods.Init(price, quantity))
    {
        cerr << "Wrong arguments to makeGoods!" << endl;
        exit(1);
    }

    return goods;
}

