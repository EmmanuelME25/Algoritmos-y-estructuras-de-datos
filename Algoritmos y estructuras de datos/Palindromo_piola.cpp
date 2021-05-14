#include <iostream>
#define MAX 50
#include <string.h>

using namespace std;

class CPila
{
private:
    char Pila[MAX];
    int Tope;
public:
    void ingresar(char);
    char sacar();
    bool vacia();
    bool llena();
    void imprimir();
    char etope();
    bool espalindromo(char[50]);
    CPila();
    ~CPila();
};

CPila::CPila()
{
    Tope=-1;
}

void CPila::ingresar(char Dato)
{
    if (llena()==true)
    {
        cout<<"La pila esta llena"<<endl;
    }
    else
    {
        Tope=Tope+1;//Tope++;
        Pila[Tope]=Dato;
        cout<<"El dato se guardo correctamente"<<endl;
    }
}

bool CPila::llena()
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

bool CPila::vacia()
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

void CPila::imprimir()
{
    if (vacia()==true)
    {
        cout<<"La pila esta vacia"<<endl;
    }
    else
    {
        for(int i=Tope;i>=0;i--)
        {
            cout<<"| "<<Pila[i]<<"|"<<endl;
            cout<<"______________"<<endl;
        }
    }
}

char CPila::sacar()
{
    char Dato;
    if (vacia()==true)
    {
        cout<<"La pila no tiene datos"<<endl;
        return NULL;
    }
    else
    {
        Dato=Pila[Tope];
        Tope=Tope-1;//Tope--;
        return Dato;
    }
}

char CPila::etope()
{
    if (vacia()==true)
    {
        cout<<"La pila no tiene datos"<<endl;
        return NULL;
    }
    else
    {
        return Pila[Tope];
    }
}

bool CPila::espalindromo(char Cad[20])
{
    for (int i=0;i<strlen(Cad);i++)
    {
    	
        ingresar(Cad[i]);
    }

    //Somos
    int i = 0;
    char Tope= etope();
    while ((Tope==Cad[i]) && (i<strlen(Cad)))
    {
        sacar();
        i++;
        //0-4 i=5
        if (i<strlen(Cad))
        	Tope=etope();
    }
    if (vacia()==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}


CPila::~CPila()
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
    char Dat,Cad[20];
    CPila Obj1;

    do
    {
        cout<<"Ingresar pila ---------> 1"<<endl;
        cout<<"Sacar pila ------------> 2"<<endl;
        cout<<"Imprimir pila ---------> 3"<<endl;
        cout<<"Elemento tope ---------> 4"<<endl;
        cout<<"Palindromo ------------> 5"<<endl;
        cout<<"Salir -----------------> 6"<<endl;
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
                Dat=Obj1.sacar();
                if (Dat!=NULL)
                    cout<<"El elemento que se saco es: "<<Dat<<endl;
            }
            break;
        case 3:
            {
                Obj1.imprimir();
            }
            break;
        case 4:
            {
                Dat=Obj1.etope();
                if (Dat!=NULL)
                    cout<<"El elemento en la cima es: "<<Dat<<endl;
            }
            break;
        case 5:
            {
                cout<<"Cadena a validar"<<endl;
                cin>>Cad;
                if (Obj1.espalindromo(Cad)==true)
                {
                    cout<<"La palabra es palindromo"<<endl;
                }
                else
                {
                    cout<<"La palabra no es palindroma"<<endl;
                    Obj1.~CPila();
                }
            }
            break;
        case 6:
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
    while (Opc!=6);
    return 0;
}
