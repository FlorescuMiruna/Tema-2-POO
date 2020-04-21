#include <iostream>
#include<fstream>
#include<Nod.h>
#include<Coada.h>
#include<Deque.h>
#include<Exceptie.h>
#include<vector>
using namespace std;
ifstream fin1 ("coada.in");
ifstream fin2 ("deque.in");
int nr_cozi,dim,nr_deques;
int main()
{
    cout<<"NOD\n";

    Nod n("Ana",NULL);
    Nod m("Ana",NULL);

    if(n==m)  ///operatorul ==
        cout<<"Nodurile sunt egale.\n";
    else
        cout<<"Nodurile nu sunt egale.\n";

    Nod mm(m); ///CC
    Nod mmm = m; ///operatorul =

    cout<<m<<" "<<mm<<" "<<mmm<<"\n";



    cout<<"\n\nVECTOR COZI\n";
    vector<Coada*> cozi;
    fin1>>nr_cozi;

    for(int i=0; i<nr_cozi; i++)
    {
        fin1>>dim;
        Coada* c;
        c = new Coada(dim);
        fin1>>*c;
        cozi.push_back(c);
    }
    for(int i=0; i<cozi.size(); i++)
    {
        cout<<*cozi[i];
    }

    if(*cozi[0] == *cozi[1])
        cout<<"Primele doua cozi sunt egale.\n";
    else
        cout<<"Primele doua cozi nu sunt egale.\n";

    cout<<"\n\nCOADA\n";
    Coada coada(NULL,NULL,5);

    fin1>>coada;
    cout<<coada;

    Coada coada1=coada;    ///operatorul =
    cout<<coada1;

    Coada coada2(coada); ///CC
    cout<<coada2;

    cout<<"top(0): "<<*coada.top(0)<<endl;
    cout<<"top(1): ";
    try
    {
        coada.top(1);
    }
    catch (exception& e)
    {
        cout << e.what() << "\n";
    }

    cout<<"insert('Ana',1)"<<endl;
    coada.insert("Ana",1);
    cout<<coada;

    cout<<"pop(1)\n";
    try
    {
        coada.pop(1);
    }
    catch (exception& e)
    {
        cout << e.what() << "\n";
    }

    cout<<coada;

    cout<<"pop(0)\n";
    coada.pop(0);
    cout<<coada;

    cout<<"pop(0)\n";
    coada.pop(0);
    cout<<coada;

    cout<<"empty()\n";
    coada.empty();
    cout<<coada;

    cout<<"insert('Cosmin',1)"<<endl;
    cout<<"insert('Adrian',1)"<<endl;

    coada.insert("Cosmin",1);
    coada.insert("Adrian",1);
    cout<<coada;
    cout<<"insert(Alex,0)\n";
    try
    {
        coada.insert("Alex",0);
    }

    catch (exception& e)
    {
        cout << e.what() << "\n";
    }


    cout<<"\n\nVECTOR DEQUE-URI\n";

    vector<Deque*> deques;
    fin2>>nr_deques;


    for(int i=0; i<nr_deques; i++)
    {
        fin2>>dim;
        Deque* d;
        d = new Deque(dim);
        fin2>>*d;
        deques.push_back(d);
    }
    for(int i=0; i<deques.size(); i++)
    {
        cout<<*deques[i];
    }
    if(*deques[1]==*deques[2])
        cout<<"Ultimele doua Deque-uri sunt egale.\n";
    else
        cout<<"Ultimele doua Deque-uri nu sunt egale.\n";

    cout<<"\n\nDEQUE\n";


    Deque dequee(6);
    fin2>>dequee;
    cout<<dequee;

    Deque dequee1 = dequee; ///Operatorul =
    cout<<dequee1;

    Deque dequee2(dequee); ///CC
    cout<<dequee2;

    cout<<"top(0): "<<dequee.top(0)->getInfo()<<"\n";
    cout<<"top(1): "<<dequee.top(1)->getInfo()<<"\n";



    cout<<"pop(0)\n";
    dequee.pop(0);
    cout<<dequee;


    cout<<"pop(1)\n";
    dequee.pop(1);
    cout<<dequee;

    cout<<"insert('ananas',1)\n";
    dequee.insert("ananas",1);
    cout<<dequee;

    cout<<"insert('rosii',0)\n";
    dequee.insert("rosii",0);
    cout<<dequee;

    cout<<"empty()\n";
    dequee.empty();
    cout<<dequee;


    cout<<"RUN-TIME POLYMORPHISM \n";

    Coada *c;
    c = new Coada(4);
    Deque d(4);
    fin2>>d;
    cout<<d;
    c = &d;

    c->pop(1);
    cout<<*c<<endl;




}
