/*
Emmanuel Medina Espinosa
Sistemas Computacionales 	2CM1
Karina Rodriguéz Mejia 
Algoritmos y estructuras de datos
*/
#include <bits/stdc++.h>
#define MAX 50
#define Max 50
using namespace std;

class Parentesis
{
private:
    char Pila[MAX];
    char Pal[Max];
    int topM;
    int topP;
    bool pal;
public:
    void ingresar(char[50]);
    char sacar();
    bool vacia();
    bool llena();
    void imprimir();
    char etope();
    bool balanceada(char[MAX]);
    void ingresarP(char);
    char sacarP();
    bool vaciaP();
    bool llenaP();
    void imprimirP();
    bool vpal();
    bool fpal();
	char limpiarP();
    Parentesis();
    ~Parentesis();
};

Parentesis::Parentesis()
{
    topM=-1;
    topP=-1;
    pal=false;
}

bool Parentesis::vpal()
{
	return pal;
}
bool Parentesis::fpal()
{
	pal=false;
}

void Parentesis::ingresar(char Cad[50])
{
    if (llena()==true)
    {
        cout<<"Pila llena"<<endl;
    }
    else
    {
    	for (int i=0;i<strlen(Cad);i++)
    {
    	topM=topM+1;//Tope++;
        Pila[topM]=Cad[i];        
		
    }

    }
}


bool Parentesis::llena()
{
    if (topM==MAX-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Parentesis::vacia()
{
    if (topM==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Parentesis::imprimir()
{
    if (vacia()==true)
    {
        cout<<"Pila vacia"<<endl;
    }
    else
    {
        for(int i=topM;i>=0;i--)
        {
            cout<<"| "<<Pila[i]<<"|"<<endl;
            cout<<"______________"<<endl;
        }
    }
}

char Parentesis::sacar()
{
	char Dato;
    if (vacia()==true)
    {
        cout<<"La pila no tiene datos"<<endl;
        return NULL;
    }
    else
    {
        Dato=Pila[topM];
        topM=topM-1;//Tope--;
        return Dato;
    }
}

char Parentesis::etope()
{
    if (vacia()==true)
    {
        cout<<"La pila no tiene datos"<<endl;
        return NULL;
    }
    else
    {
        return Pila[topM];
    }
}



Parentesis::~Parentesis()
{
	
	int T=Tope;
	for (int i=0; i<=T;i++)
	{
		sacar();
	}
}
//_____________________________________________________________________________________________________________________________________________________

void Parentesis::ingresarP(char Data)
{
    if (llenaP()==true)
    {
        cout<<"La pila balanceo esta llena"<<endl;
    }
    else
    {
        topP=topP+1;//Tope++;
        Pal[topP]=Data;
    }
}

bool Parentesis::llenaP()
{
    if (topP==Max-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Parentesis::vaciaP()
{
	
    if (topP==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char Parentesis::sacarP()
{
    char Data;
    if (vaciaP()==true)
    {
    	pal = true;
    	return NULL;
    }
    else
    {
        Data=Pal[topP];
        topP=topP-1;//Tope--;
        return Data;
    }
}

char Parentesis::limpiarP()
{
    char Dato;
    if (vaciaP()==true)
    {
        return NULL;
    }
    else
    {
        Dato=Pal[topP];
        topP=topP-1;//Tope--;
        return Dato;
    }
}

bool Parentesis::balanceada(char cad[50])
{
    	for (int i=0;i<strlen(cad);i++)
	{
		if(Pila[i]=='(')
        {
        	ingresarP('(');
		}
		if(Pila[i]==')')
		{
		sacarP();
		
		}
	}
	
	if(vaciaP()==true && vpal()==false)
	{
		return true;
	}
	else 
	{
		return false;
	}
	
}
//_____________________________________________________________________________________________________________________________________________________
int main()
{
    int Opc;
    char Dat,Cad[50];
    Parentesis Obj1;
    int len=0;

    do
    {
        cout<<"Ingresar pila ---------> 1"<<endl;
        cout<<"Sacar pila ------------> 2"<<endl;
        cout<<"Limpiar pila-----------> 3"<<endl;
        cout<<"Imprimir pila ---------> 4"<<endl;
        cout<<"Elemento tope ---------> 5"<<endl;
        cout<<"Balanceado ------------> 6"<<endl;
        cout<<"Salir -----------------> 7"<<endl;
        cout<<"Elige un opcion: ";
        cin>>Opc;
        switch (Opc)
        {
        case 1:
            {
                cout<<"Dato a ingresar"<<endl;
                cin>>Cad;
                len=strlen(Cad);
                Obj1.ingresar(Cad);
            }
            break;
        case 2:
            {
            	int num;
            	cout<<"Numero de elementos a sacar: ";
            	cin>>num;
            	for(int i=0;i<=num-1;i++)
            	{
                Obj1.sacar();
            	}
            }
            break;
        case 3:
            {
            	for(int i=0;i<=len;i++)
            	{
                Obj1.sacar();
                Obj1.limpiarP();
            	}
            }
            break;
        case 4:
            {
                Obj1.imprimir();
            }
            break;
        case 5:
            {
                Dat=Obj1.etope();
                if (Dat!=NULL)
                    cout<<"El elemento en la cima es: "<<Dat<<endl;
            }
            break;
        case 6:
            {
  
            	if(Obj1.balanceada(Cad)==true)
            	{
            		cout<<"La expresion esta balanceada"<<endl;
				}
				else
				{
					cout<<"La expresión NO esta balanceada"<<endl;
					Obj1.fpal();
				}
				
				
            }
            break;
        case 7:
            {
                cout<<"Fin"<<endl;
            }
            break;
        default:
            {
                cout<<"No valida"<<endl;
            }
        }
    }
    while (Opc!=7);
    return 0;
}
