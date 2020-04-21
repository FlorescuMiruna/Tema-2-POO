#include "Deque.h"

Deque::Deque(int dim_maxima) :Coada(dim_maxima)
{

}
Deque::Deque(Nod *prim,Nod *ultim, int dim_maxima): Coada(prim,ultim,dim_maxima)
{

}
Deque::Deque(const Deque& other) :Coada(other)
{
   // cout<<"Deque CC\n";
}
Deque::~Deque()
{
    //cout<<"Distruge Deque\n";
}
Nod* Deque::top(bool unde)
{
    if(unde==0)
        return prim;
    else
        return ultim;
}
void Deque::insert(string cuvant,bool unde)
{
    if(unde == 1)
        Coada::insert(cuvant,1);
    if(unde == 0)
    {

        Nod *p;
        p = new Nod(cuvant,NULL);
        if (isEmpty())
        {
            prim=ultim=p;
        }
        else
        {
            p->next = prim;
            prim = p;
        }


    }
}

void Deque::pop(bool unde)
{
    if(unde==0)
        Coada::pop(0);
    if(unde==1)
    {
        Nod *p = prim;
        while(p->next != ultim)
        {
            p=p->next;
        }

        ultim = p;
        p = p->next;
        delete p;
        ultim->next = NULL;


    }
}


