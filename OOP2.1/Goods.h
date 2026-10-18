
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Goods
{
private:
    double first;
    unsigned int second;

public:
    Goods();
    Goods(double price, unsigned int quantity);
    Goods(const Goods& other);

    bool setFirst(double value);
    bool setSecond(unsigned int value);

    double getFirst() const;
    unsigned int getSecond() const;

    bool Init(double price, unsigned int quantity);
    void Read();
    void Display() const;

    double cost() const;

    Goods& operator=(const Goods& other);
    operator string() const;

    Goods& operator++();
    Goods& operator--();

    Goods operator++(int);
    Goods operator--(int);

    friend istream& operator>>(istream& in, Goods& goods);
    friend ostream& operator<<(ostream& out, const Goods& goods);
};

Goods makeGoods(double price, unsigned int quantity);

