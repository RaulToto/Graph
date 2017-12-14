#define FibonacciHeap_H
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;
///------------------------------------------
template <class T>
class FibonacciNode
{
    public:
        FibonacciNode(T d)
        {
            this->valor=d;
            this->padre=0;
            this->marcado=false;
        }
        int getGrado()
        {
            return this->hijos.size();
        }
        virtual ~FibonacciNode(){}
    protected:
    public:
        T valor;
        FibonacciNode<T>* padre;
        std::list<FibonacciNode<T>* > hijos;
        bool marcado;


};
//----------------------------------------------------
template <class T>
class FibonacciHeap
{
    typedef FibonacciNode<T>* Fnodo;
    typedef std::list<Fnodo> Flista;
    typedef typename Flista::iterator Fiterator;

    public:
        FibonacciHeap() { }
        void insertar(T);
        void unir_raices(Fnodo&, Fnodo&);
        void actualizar_min();
        void borrar(FibonacciNode<T>*&);
        void unir(FibonacciHeap<T>);
        Flista getRaices()
        {
            return this->raices;
        }
        T getmin()
        {
            return (*minimo)->valor;
        }
        void mostrar();
        void decrease_key(Fnodo&, T);
        void compactar();
        void split(Fiterator,int);
        void eliminar_min();
        void Graph();
        virtual ~FibonacciHeap(){}
    protected:
    public:
        Flista raices;
        Fiterator minimo;

};

template <class T>
void FibonacciHeap<T>::split(Fiterator it, int n)
{
    if (!(*it) ) return;
    for (int i=0;i<n;i++)
        std::cout<<"  ";
    std::cout<<"la raiz es --> "<<(*it)->valor<<std::endl;
    for (int i=0;i<n;i++)
        std::cout<<"  ";
    std::cout<<"los hijos de -->"<<(*it)->valor<<" son :  ";
    imprimir_lista((*it)->hijos);
    Fiterator it2=(*it)->hijos.begin();
    split(it2,n+1);
    split(++it2,n+1);
}

template <class T>
void FibonacciHeap<T>::mostrar()
{
    Fiterator it=raices.begin();
    while (it!=raices.end())
    {
        split(it,0);
        it++;
        std::cout<<"--"<<std::endl;
    }

}

template <class T>
void FibonacciHeap<T>::unir(FibonacciHeap<T> otro)
{
    if ((*otro.minimo)->valor < (*minimo)->valor)
    {
        this->minimo=otro.minimo;
    }
    this->raices.merge(otro.raices);
}

template <class T>
void FibonacciHeap<T>::borrar(FibonacciNode<T>*& a)
{
    decrease_key(a,-12321);
    eliminar_min();

}


template <class T>
void FibonacciHeap<T>::actualizar_min()
{
    Fiterator vmini=raices.begin();
    for (Fiterator mini=raices.begin();mini!=raices.end();mini++)
    {
        if ((*vmini)->valor>(*mini)->valor)
            vmini=mini;
        (*mini)->marcado=false;
    }
    this->minimo=vmini;
}

template <class T>
void FibonacciHeap<T>::decrease_key(FibonacciNode<T>*& a, T d)
{
    a->valor=d;

    if (a->valor<a->padre->valor)
    {
        if (!a->padre->marcado)
        {
            a->padre->marcado=true;
            a->padre=0;
            a->padre->hijos.remove(a);
            a->marcado=false;
            raices.push_front(a);
        }
        else
        {
            while (a->padre || a->padre->marcado)
            {
                a->marcado=false;
                a->padre=0;
                a->padre.hijos.remove(a);
                raices.push_front(a);
                a=a->padre;
            }
        }

    }
    actualizar_min();
}


template <class T>
void FibonacciHeap<T>::compactar()
{
    int a=raices.size();
    std::vector<FibonacciNode<T>*> v;
    for (int i=0;i<10;i++)
    {
        v.push_back(0);
    }
    Fiterator it=raices.begin();
    FibonacciNode<T>* aux=*it;
    while (it!=raices.end())
    {
        int grado=(*it)->getGrado();
        if (!v.at(grado))
        {
            v.at(grado)=*it;
            it++;
        }
        else
        {
            Fiterator itaux=it;
            if ((v.at(grado))->valor<(*it)->valor)
            {
                Fiterator itaux=find(raices.begin(),raices.end(),v.at(grado));
                unir_raices(v.at(grado),(*it));
                it=itaux;
                int ngrado= (*it)->getGrado();
                if (!v.at(ngrado))
                {
                    v.at(grado)=0;
                    v.at(ngrado)=(*it);
                    it++;
                }
                else
                {
                    v.at(grado)=0;
                }


            }
            else
            {
                unir_raices(*it,v.at(grado));

                int ngrado=(*it)->getGrado();
                if (!v.at(ngrado))
                {
                    v.at(grado)=0;
                    v.at(ngrado)=(*it);
                    it++;
                }
            }
        }
    }
}


template <class T>
void FibonacciHeap<T>::eliminar_min()
{
    Fnodo aux=*minimo;
    raices.remove(aux);
    if (!aux->hijos.empty())
    {
        for (auto i: aux->hijos)
        {
            raices.push_back(i);
            aux->hijos.remove(i);
            i->padre=0;
        }
    }
    actualizar_min();
    compactar();
}



template <class T>
void FibonacciHeap<T>::unir_raices(FibonacciNode<T>*& a, FibonacciNode<T>*& b)
{
    if ((a->valor)<(b->valor))
    {
        raices.remove(b);
        a->hijos.push_front(b);
        b->padre=a;

    }
}

template <class T>
void FibonacciHeap<T>::insertar(T d)
{
    Fnodo nuevo=new FibonacciNode<T>(d);
    if (raices.empty())
    {
        raices.push_back(nuevo);
        minimo=raices.begin();
    }
    else
    {
        raices.insert(minimo,nuevo);
        if ((*minimo)->valor>=d) minimo--;
    }
    compactar();
}


#endif // FibonacciHeap_H
