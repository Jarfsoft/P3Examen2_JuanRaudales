#include "Nodo.cpp"

#ifndef PILA_CPP
#define PILA_CPP

using namespace std;

class Pila
{
	private:
		Nodo* tope;
	public:
		Pila()
		{
			tope=NULL;
		}
		void push(string x)
		{
			Nodo* nuevo = new Nodo();
			nuevo->setValor(x);
			nuevo->setSiguienteNodo(tope);
			tope=nuevo;
		}
		Nodo* pop()
		{
			Nodo* retorno=tope;
			tope=tope->getSiguienteNodo();
			return retorno;
		}
		Nodo* top()
		{
			return tope;
		}
		bool isEmpty()
		{
			if(tope==NULL)
				return true;
			else
				return false;
		}
		
};

#endif
