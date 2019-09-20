#include <stdlib.h>
#include <conio.h>
#include "Pila.cpp"

using namespace std;

bool validarNumero(string);

int main()
{
	string ingreso;
	Pila expresion=Pila();
	cout<<"Ingrese expresion algebraica: ";
	cin>>ingreso;
	string temp;
	string avance="";
	int x=0;
	
	for(int x=0;x<ingreso.size();x++)
	{
		temp=ingreso[x];
		
		
		if(validarNumero(temp))
		{
			avance=avance+temp;
		}
		else if(temp=="-")
		{
			if(avance.size()!=0)
			{
				expresion.push(avance);
				avance=temp;
			}
			else
				avance=temp;
		}
		else
		{
			if(avance.size()!=0)
			{
				expresion.push(avance);
				avance="";
			}
			expresion.push(temp);
		}
		if(x==ingreso.size()-1)
		{
			expresion.push(avance);
		}
	}
	
	
	int n1,n2;
	string operador;
	
	
	
	while(!expresion.isEmpty())
	{
		operador="";
		if(validarNumero(expresion.top()->getValor()))
		{
			n1=atoi(expresion.pop()->getValor().c_str());
		}
		else if(expresion.top()->getValor().at(0)=='-')
		{
			string temp2="";
			string i=expresion.pop()->getValor();
			for(int y=1;y<i.size();y++)
			{
				temp2=temp2+i.at(y);
			}
			n1=0-atoi(temp2.c_str());
			
		}
		
		
		
		if(!validarNumero(expresion.top()->getValor()))
			if(expresion.top()->getValor().at(0)!='-')
				operador=expresion.pop()->getValor();
		
		
		
		if(validarNumero(expresion.top()->getValor()))
		{
			n2=atoi(expresion.pop()->getValor().c_str());
		}
		else if(expresion.top()->getValor().at(0)=='-')
		{
			
			string temp2="";
			string i=expresion.pop()->getValor();
			for(int y=1;y<i.size();y++)
			{
				
				temp2=temp2+i.at(y);
				
			}
			n2=0-atoi(temp2.c_str());
		}
		
		
		
		char temp[10];
		if(operador=="*")
			itoa(n1*n2,temp,10);
		else if(operador=="/")
			itoa(n1/n2,temp,10);
		else
			itoa(n1+n2,temp,10);
		string num=temp;
		expresion.push(num);
		
		cout<<expresion.top()->getValor()<<endl;
		getch();
		
		if(expresion.top()->getSiguienteNodo()==NULL)
			break;

	}
	
	
	return 0;
}

bool validarNumero(string entrada)
{
	for(int x=0;x<entrada.size();x++)
	{
		if(entrada[x]!='0')
			if(entrada[x]!='1')
				if(entrada[x]!='2')
					if(entrada[x]!='3')
						if(entrada[x]!='4')
							if(entrada[x]!='5')
								if(entrada[x]!='6')
									if(entrada[x]!='7')
										if(entrada[x]!='8')
											if(entrada[x]!='9')
												return false;
				
	}
	return true;
}
