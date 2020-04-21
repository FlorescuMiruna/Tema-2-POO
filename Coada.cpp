#include "Coada.h"
#include <Exceptie.h>

using namespace std;
Coada::Coada(int dim_maxima)
{
    this->dim_maxima = dim_maxima;
    prim=ultim=NULL;
}
Coada::Coada(Nod* prim,Nod* ultim,int dim_maxima)
{
    this->dim_maxima = dim_maxima;
    this->prim = prim;
    this->ultim = ultim;
}

Coada::~Coada()
{
    Nod *p=prim;
    Nod *q;
    while(p!=NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }

    prim=ultim = NULL;
    //cout<<"Distruge Coada\n";
}

Coada::Coada(const Coada &other)
{
    dim_maxima = other.dim_maxima;
    prim = other.prim;

    if(isEmpty())
        ultim = other.ultim;
    else
    {
        Nod *p = other.prim;
        while(p!=NULL)
        {

            p = p->next;
        }
    }



    // cout<<"Coada CC\n";
}


bool Coada::isEmpty()
{
    return prim==NULL;
}

void Coada::insert(string cuvant,bool unde)
{
    if (unde == 0)
    {

        throw(Exceptie("In coada nu putem adauga elemente la inceput."));
    }
    else
    {
        Nod *p;
        p = new Nod(cuvant,NULL);
        if (isEmpty())
        {
            prim=ultim=p;
        }
        else
        {
            ultim->next = p;
            ultim = p;
        }
    }

}

Nod *Coada::top(bool unde)
{
    if(unde == 1)
    {
        throw(Exceptie("Primul cuvant din coada nu poate fi luat de la final."));
    }
    else
        return prim;
}


void Coada::pop(bool unde)
{
    if (unde == 1)
    {

        throw(Exceptie("In coada nu putem sterge un element de la final."));
    }
    else
    {
        if(!isEmpty())
        {
            Nod *p = prim;
            prim = prim->next;
            delete p;

        }
    }

}
void Coada::empty()
{

    Nod *p=prim;
    Nod *q;
    while(p!=NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    prim=ultim = NULL;


}


istream& operator>>(istream& input,Coada& ob )
{
    string cuvant;

    for(int i=0; i<ob.dim_maxima; i++)
    {
        input>>cuvant;
        ob.insert(cuvant,1);
    }

    return input;
}

ostream& operator << (ostream& output,Coada & ob)
{

    Nod *p=ob.prim;

    while(p!=NULL)
    {
        output<<p->getInfo()<<" ";
        p=p->getNext();

    }
    output<<"\n";
    return output;
}

bool Coada::operator==(const Coada &ob) const
{
    if ( prim->getInfo()!= ob.prim->getInfo() )
        return false;
    Nod  *p = prim;
    Nod  *x = ob.prim;
    while(p or x)
    {
        if(p->info != x->info)
            return false;

        p=p->next;
        x=x->next;

    }
    return true;


}

Coada& Coada::operator = (const Coada& ob)
{
    this->dim_maxima = ob.dim_maxima;
    this->prim = ob.prim;

    if(isEmpty())
        this->ultim = ob.ultim;
    else
    {
        Nod *p = ob.prim;
        while(p!=NULL)
        {

            p = p->next;
        }
    }
    return *this;

}
