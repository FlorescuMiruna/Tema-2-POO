#include<Nod.h>

#pragma once

using namespace std;
class Coada
{
protected:

    Nod *prim,*ultim;
    int dim_maxima;

public:

    Coada(int dim_maxima);
    Coada(Nod *prim,Nod *ultim, int dim_maxima);
    Coada(const Coada&);
    virtual ~Coada();



    friend istream& operator>>(istream& input,Coada& );
    friend ostream& operator<<(ostream& output, Coada&);
    bool operator == (const Coada&) const;
    Coada& operator = (const Coada&);


    bool isEmpty();

    virtual void insert(string,bool unde); ///unde=0 - insereaza la inceput, unde=1-insereaza la sfarsit
    virtual void pop(bool);
    virtual Nod  *top(bool unde);
    virtual void empty();

    friend class Nod;



};


