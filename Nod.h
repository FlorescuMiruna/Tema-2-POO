#include<iostream>
#pragma once

using namespace std;
class Coada;
class Deque;
class Nod
{
    string info;
    Nod *next;
public:
    Nod();
    Nod(string ,Nod *);
    Nod(const Nod&);
    virtual ~Nod();

    friend class Coada;
    friend class Deque;
    friend istream& operator>>(istream& input, Nod&);
    friend ostream& operator<<(ostream& output, Nod&);

    bool operator==(const Nod& ) const;
    Nod& operator = (const Nod&);


    string getInfo();
    Nod *getNext();


};


