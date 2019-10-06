#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
	int valor;
	struct nodo*puntero;
};
void menu();
void insertar(nodo*&,int );
void imprimir(nodo*);
void eliminarelemento(nodo *&, int);

nodo*lista=NULL;
int main(){
    menu();	
	getch();
	return 0;
}
void insertar(nodo*&lista, int dato){
	nodo*nodonuevo = new nodo();
	nodonuevo->valor =dato;
	
	nodo*auxiliar=lista;
	nodo*auxiliar2;
	
	while((auxiliar != NULL) &&(auxiliar->valor < dato)){
	    auxiliar2 = auxiliar;
	    auxiliar = auxiliar->puntero;
    }
    
	if(lista == auxiliar){
	    lista = nodonuevo;
    }
    
    else{
    	auxiliar2->puntero=nodonuevo;
	}
	nodonuevo->puntero =auxiliar;
    
    cout<<dato<<" numero guardado\n";
}
//funcion imprimir
void imprimir(nodo*lista){
	nodo*inicio=new nodo();
	inicio=lista;
	
	while(inicio !=NULL){
		cout<<inicio->valor<<"-";
		inicio=inicio->puntero;
	}
}
	
void menu(){
	int opcion, valor;
	
	do{
		cout<<"\t.:::MENU:::.\n";
		cout<<"1.- agregar valores\n";
		cout<<"2.- imprimir\n";
		cout<<"3.- eliminar elemento de la lista\n";
		cout<<"4.- salir\n";
		cout<<"elije una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"\n ingrese un numero: ";
				cin>>valor;
				insertar(lista,valor);
				cout<<"\n";
				system("pause");
			break;
			
			case 2:
				imprimir(lista);
				cout<<"\n";
				system("pause");
			break;	
			///opcion para ingreasar los datos que se eliminaran
			case 3:
				cout<<"\nDiguiente el elemento que desea eliminar: ";
				cin >>valor;
				eliminarelemento(lista,valor);
				cout<<"\n";
				system("pause");
			break;
			
		}
		system("cls");
	}while(opcion !=4);
}
//funcion si que elimina el numero que hay en la lista de nodos, el cual es ingresado por el usuario.
void eliminarelemento(nodo *&lista,int n){
	if (lista != NULL){
		nodo*aux_borrar;
		nodo*anterior =NULL;
		
		aux_borrar=lista;
		
	while((aux_borrar != NULL)&&(aux_borrar->valor != n)){
		anterior=aux_borrar;
		aux_borrar=aux_borrar->puntero;
	}
	if (anterior == NULL){
		lista=lista->puntero;
		delete aux_borrar;
	}
	else {
		anterior->puntero =aux_borrar->puntero;
		delete aux_borrar;
	}
	}	
}
