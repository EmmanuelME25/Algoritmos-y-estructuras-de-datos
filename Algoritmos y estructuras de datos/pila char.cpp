#include <iostream>
#define MAX 10
#include <string.h>

using namespace std;

class CPila
{
private:
    char Pila[MAX];
    int Tope;
public:
    void ingresar(char);
    int sacar();
    bool vacia();
    bool llena();
    void imprimir();
    int etope();
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

int CPila::sacar()
{
    int Dato;
    if (vacia()==true)
    {
        cout<<"La pila no tiene datos"<<endl;
    }
    else
    {
        Dato=Pila[Tope];
        Tope=Tope-1;//Tope--;
        return Dato;
    }
}

int CPila::etope()
{
    if (vacia()==true)
    {
        cout<<"La pila no tiene datos"<<endl;
    }
    else
    {
        return Pila[Tope];
    }
}


CPila::~CPila()
{

}

int main()
{
    int Opc;
    char Dat;
    CPila Obj1;

    do
    {
        cout<<"Ingresar pila ---------> 1"<<endl;
        cout<<"Sacar pila ------------> 2"<<endl;
        cout<<"Imprimir pila ---------> 3"<<endl;
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
                cout<<"El elemento que se saco es: "<<Obj1.sacar()<<endl;
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
