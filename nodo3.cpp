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
		cout<<"3.- salir\n";
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
		}
		system("cls");
	}while(opcion !=3);
}
