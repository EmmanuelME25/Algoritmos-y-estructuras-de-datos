#include<bits/stdc++.h>
using namespace std;

//TAD
class persona
{
	//no se afectan en el main
	
	private:
		char nombre[40];
		
	public:
		void hablar();
		void dormir();
		void contar();
		void adquirir_nombre(char [40]);
};


void persona::adquirir_nombre(char n[40])
{
	strcpy(nombre,n);
}

void persona::hablar()
{
	cout<<"Hola mi nombre es "<<nombre<<endl;
}

void persona::dormir()
{cout<<"Zzzz..."<<endl;
}

void persona::contar()
{
	cout<<"Uno, dos, tres, cuatro..."<<endl;
}

int main()
{
	char nombre[40];
	
	persona per;
	
	per.adquirir_nombre("Karen");
	per.contar();
	per.dormir();
	per.hablar();
	return 0;
}




