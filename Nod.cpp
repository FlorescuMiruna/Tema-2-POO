#include "Nod.h"
#pragma once

Nod::Nod()
{
    next = NULL;
    info = "";
}

Nod::Nod(string info,Nod * next)
{
    this->info = info;
    this->next = next;
}

Nod::~Nod()
{

    info = "";
    next = NULL;
    delete next;

}
Nod::Nod(const Nod &other)
{
    info = other.info;
    next = other.next;

}
istream& operator >>(istream& input, Nod& ob)
{
    input>>ob.info;
    return input;
}
ostream& operator <<(ostream& output, Nod& ob)
{
    output<<ob.info;
    return output;
}
bool Nod::operator == (const Nod& ob) const
{
    return info == ob.info && next == ob.next;


}

Nod& Nod::operator = (const Nod& ob)
{
   this->info = ob.info;
   this->next = ob.next;

   return *this;


}

string Nod::getInfo()
{
    return this->info;
}

Nod* Nod::getNext()
{
    return next;
}
