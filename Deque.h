#pragma once
#include<Coada.h>

class Deque:public Coada
{

public:
    Deque(int dim_maxima);
    Deque(Nod *prim,Nod *ultim, int dim_maxima);
    Deque(const Deque&);
    virtual ~Deque();

    void insert(string,bool unde);///unde=0 - inserez la inceput; unde=1 - inserez la sfarsit
    Nod  *top(bool unde);
    void pop(bool unde);



};


