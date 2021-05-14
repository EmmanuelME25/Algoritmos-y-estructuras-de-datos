#include <iostream>
using namespace std;

//Materia: Algoritmos y Estructuras de Datos
//Emmanuel Medina Espinosa     |     Ana Paola Rebolloso Saucedo     |     Eliane Danae Trejo Aguiñaga
//Grupo: 1CM1

class busqueda{
 private:
     int buscado;
     int n;
     int datos[];
 public:
 	int insercion();
    int secuencial_ordenado();
    int secuencial();
    int binaria();
    void adquirir_buscado(int buscado);
    int devolver_buscado();
    void adquirir_n(int n);
    int devolver_n();
    void adquirir_datos(int datos[]);
    int devolver_datos(); 
    busqueda();
    ~busqueda();
};

busqueda::busqueda(){

}

void busqueda::adquirir_buscado(int buscado){
    this->buscado=buscado;
}

int busqueda::devolver_buscado(){
    return buscado;
}

int busqueda::insercion(){
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
}

void busqueda::adquirir_n(int n){
    this->n=n;
}

int busqueda::devolver_n(){
    return n;
}

void busqueda::adquirir_datos(int datos[]){
    for(int i=0;i<n;i++){
        this->datos[i]=datos[i];
    }
}

int busqueda::devolver_datos(){
    return datos[n];
}

int busqueda::secuencial(){
	bool aviso=false;

    for(int i=0;i<n;i++)
    {
        if(datos[i]==buscado){
            cout<<"El dato fue encontrado en la posicion "<<i<<" del arreglo."<<endl;
            aviso=true;
        }
    }
    if(aviso==false){
            cout<<"El dato no fue encontado"<<endl;
    }
}

int busqueda::secuencial_ordenado(){
	bool aviso=false;

    for(int i=0;i<n;i++)
    {
        if(datos[i]==buscado){
            cout<<"El dato fue encontrado en la posicion "<<i<<" del arreglo."<<endl;
            aviso=true;
        }
    }
    if(aviso==false){
            cout<<"El dato no fue encontado"<<endl;
    }
}

int busqueda::binaria(){
	int cont=0,contA=0,contB=0;
	int mitad,i;
	
	 while (cont <= n){
    contA++;
    mitad = (cont + n) / 2;

    if(buscado > datos[n-1]){
      printf("Numero no encontrado\n");
      break;
    }

    if(buscado == datos[mitad]){
      printf("Numero %d encontrado en posicion %d\n", datos[mitad], mitad);
      break;
    }
    else if(buscado < datos[mitad]){
      n = mitad -1;
    }
    else{
      cont = mitad + 1;
    }
    contB++;

  }

if(contA == contB){
  printf("Numero no encontrado\n");
}

}

busqueda::~busqueda(){

}

int main(){
    int opc,n,buscado;
    busqueda Var1;

    do{
		cout<<"--------------------------MENU--------------------------"<<endl;
    	cout<<"1.Secuencial"<<endl;
    	cout<<"2.Secuencial 2"<<endl;
    	cout<<"3.Binaria"<<endl;
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
				cout<<"Ingrese el dato que desea buscar:"<<endl;
				cin>>buscado;
				Var1.adquirir_buscado(buscado);
    			cout<<endl<<"Datos encontrados: "<<endl;
    			Var1.secuencial();
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
                cout<<"Ingrese el dato que desea buscar:"<<endl;
				cin>>buscado;
				Var1.adquirir_buscado(buscado);
    			cout<<endl<<"Datos encontrados: "<<endl;
    			Var1.insercion();
    			Var1.secuencial_ordenado();
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
                cout<<"Ingrese el dato que desea buscar:"<<endl;
				cin>>buscado;
				Var1.adquirir_buscado(buscado);
    			cout<<endl<<"Datos encontrados: "<<endl;
    			Var1.insercion();
    			Var1.binaria();
				break;
			    }

			case 4:
			    {
				cout<<"FIN"<<endl;
    			return 0;
				break;
			    }

			default:
				cout<<"ERROR"<<endl;
    			return 0;
				break;
		}
	}
	while(opc!=4);
    return 0;
}
