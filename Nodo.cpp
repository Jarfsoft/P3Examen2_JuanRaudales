#include <iostream>

#ifndef NODO_CPP
#define NODO_CPP

using namespace std;

class Nodo
{
	private:
		string valor;
		Nodo *siguienteNodo;
		
	public:
		Nodo(){}
		void setValor(string x)
		{
			valor= x;
		}
		void setSiguienteNodo(Nodo* x)
		{
			siguienteNodo=x;
		}
		Nodo* getSiguienteNodo()
		{
			return siguienteNodo;
		}
		string getValor()
		{
			return valor;
		}
};

#endif
