#include <iostream>
using namespace std;

//Materia: Algoritmos y Estructuras de Datos
//Emmanuel Medina Espinosa     |     Ana Paola Rebolloso Saucedo     |     Eliane Danae Trejo Aguiñaga
//Grupo: 1CM1

class ordenamientos{
 private:
     int n;
     int datos[];
 public:
    int insercion();
    int seleccion();
    int burbuja();
    void adquirir_datos(int datos[]);
    int devolver_datos();
    void adquirir_n(int n);
    int devolver_n();
    ordenamientos();
    ~ordenamientos();
};

ordenamientos::ordenamientos(){

}

void ordenamientos::adquirir_datos(int datos[]){
    for(int i=0;i<n;i++){
        this->datos[i]=datos[i];
    }
}

int ordenamientos::devolver_datos(){
    return datos[n];
}

void ordenamientos::adquirir_n(int n){
    this->n=n;
}

int ordenamientos::devolver_n(){
    return n;
}

int ordenamientos::insercion(){
int a,indice;
    for (int i=1;i<n;i++)
    {
        indice=datos[i];
        a=i-1;
        while (a>=0&&datos[a]>indice)
        {
            datos[a+1]=datos[a];
            a--;
        }
        datos[a+1]=indice;
    }
    for(int i=0; i<n; i++){
    	cout<<datos[i]<<endl;
	}
}

int ordenamientos::seleccion(){
    int aux;
   for (int i=0; i<n-1;++i) {
       int mini=i;
       for (int c=i+1;c<n;++c) {
           if (datos[mini]>datos[c])
           {
            mini=c;
           }
       }
       aux=datos[i];
       datos[i]=datos[mini];
       datos[mini]=aux;
   }
   for(int i=0; i<n; i++){
    	cout<<datos[i]<<endl;
	}
}

int ordenamientos::burbuja(){
    int aux;
    for(int i=0; i<n; i++){
	    for(int j=i+1; j<n; j++){
	        if(datos[j]<datos[i]){
	            aux=datos[j];
	            datos[j]=datos[i];
	            datos[i]=datos[j];
	            datos[i]=aux;
	        }
	    }
	}
	for(int i=0; i<n; i++){
    	cout<<datos[i]<<endl;
	}
}

ordenamientos::~ordenamientos(){

}

int main(){
    int opc,n;
    ordenamientos Var1;
    
    do{
		cout<<"--------------------------MENU--------------------------"<<endl;
    	cout<<"1.Insercion"<<endl;
    	cout<<"2.Seleccion"<<endl;
    	cout<<"3.Burbuja"<<endl;
    	cout<<"4.Salir"<<endl;
    	cout<<"Elija una opcion: ";
    	cin>>opc;
		
		switch (opc){
			case 1:
				{
				cout<<"Ingrese el numero de datos: ";
    			cin>>n;
    			Var1.adquirir_n(n);
    			int datos[n];
    			cout<<"Ingrese los numeros: "<<endl;
    			for(int i=0;i<n;i++){
					cin>>datos[i];
				}
    			Var1.adquirir_datos(datos);
    			cout<<endl<<"Datos ordenados: "<<endl;
    			Var1.insercion();
				break;
			}
			case 2:
			{
				cout<<"Ingrese el numero de datos: ";
    			cin>>n;
    			Var1.adquirir_n(n);
    			int datos[n];
    			cout<<"Ingrese los numeros: "<<endl;
    			for(int i=0;i<n;i++){
					cin>>datos[i];
				}
    			Var1.adquirir_datos(datos);
    			cout<<endl<<"Datos ordenados: "<<endl;
    			Var1.seleccion();
				break;
			}
			case 3:
				{
				cout<<"Ingrese el numero de datos: ";
    			cin>>n;
    			Var1.adquirir_n(n);
    			int datos[n];
    			cout<<"Ingrese los numeros: "<<endl;
    			for(int i=0;i<n;i++){
					cin>>datos[i];
				}
    			Var1.adquirir_datos(datos);
    			cout<<endl<<"Datos ordenados: "<<endl;
    			Var1.burbuja();
				break;	
			}
			case 4:
				{
				cout<<"FIN"<<endl;
    			return 0;
				break;
			}
			default:
				{
				cout<<"ERROR"<<endl;
    			return 0;
				break;
			}
		}
	}
	while(opc!=4);
    return 0;
}
