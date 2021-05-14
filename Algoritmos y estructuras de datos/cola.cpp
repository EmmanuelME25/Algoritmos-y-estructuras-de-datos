/*
Emmanuel Medina Espinosa
Sistemas Computacionales 	2CM1
Karina Rodriguéz Mejia 
Algoritmos y estructuras de datos
Práctica 05
*/

#include <iostream>
#define MAX 50
#include <string.h>

using namespace std;

class Cola
{
private:
    char array[MAX];
    int Tope;
    int aux;
public:
    void ingresar(char[50]);
    int sacar();
    bool vacia();
    bool llena();
    void imprimir();
    int etope();
    Cola();
    ~Cola();
};

Cola::Cola()
{
    Tope=-1;
    aux=-1;
}

void Cola::ingresar(char Dato[50])
{
        if (llena()==true)
    {
        cout<<"Cola llena"<<endl;
    }
    else
    {
    	for (int i=0;i<strlen(Dato);i++)
    {
    	Tope=Tope+1;//Tope++;
        array[Tope]=Dato[i];        
		
    }

    }
}

bool Cola::llena()
{
    if (Tope==MAX-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Cola::vacia()
{
    if (Tope==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Cola::imprimir()
{
    if (vacia()==true)
    {
        cout<<"La cola esta vacia"<<endl;
    }
    else
    {
        for(int i=Tope;i>=0;i--)
        {
            cout<<"| "<<array[i]<<"|"<<endl;
            cout<<"______________"<<endl;
        }
    }
}

int Cola::sacar()
{
    int Dato;
    if (vacia()==true)
    {
        cout<<"La cola no tiene datos"<<endl;
    }
    if(aux>=Tope)
    {
    	cout<<"Cola vacia"<<endl;
    	aux=Tope;
	}
    else
    {
    	aux++;
        array[aux]=NULL;
        return Dato;
    }
}

int Cola::etope()
{
    if (vacia()==true)
    {
        cout<<"La cola no tiene datos"<<endl;
    }
    else
    {
        return array[Tope];
    }
}


Cola::~Cola()
{
int T=Tope;
	for (int i=0; i<=T;i++)
	{
		sacar();
	}
}

int main()
{
    int Opc;
    char Dat[50];
    Cola Obj1;

    do
    {
        cout<<"Ingresar cola ---------> 1"<<endl;
        cout<<"Sacar cola ------------> 2"<<endl;
        cout<<"Imprimir cola ---------> 3"<<endl;
        cout<<"Elemento tope ---------> 4"<<endl;
        cout<<"Salir -----------------> 5"<<endl;
        cout<<"Elige un opcion: ";
        cin>>Opc;
        switch (Opc)
        {
        case 1:
            {
                cout<<"Dato a ingresar"<<endl;
                cin>>Dat;
                Obj1.ingresar(Dat);
            }
            break;
        case 2:
            {
            	Obj1.sacar();
            }
            break;
        case 3:
            {
                Obj1.imprimir();
            }
            break;
        case 4:
            {

            }
            break;
        case 5:
            {
                cout<<"Adios"<<endl;
            }
            break;
        default:
            {
                cout<<"No es una opcion valida"<<endl;
            }
        }
    }
    while (Opc!=5);
    return 0;
}
