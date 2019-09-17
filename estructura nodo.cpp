#include<iostream>
using namespace std;

struct nodo{
	int valor;
	struct nodo *apuntador;
};
int main(){
	struct nodo dato1,dato2,dato3,dato4,dato5;
	dato1.valor=3;
	dato1.apuntador=NULL;
	dato2.valor=7;
	dato2.apuntador=NULL;
	dato3.valor=9;
	dato3.apuntador=NULL;
	dato4.valor=7;
	dato4.apuntador=NULL;
	dato5.valor=1;
	dato5.apuntador=NULL;
	
	dato1.apuntador=&dato2;	
	dato2.apuntador=&dato3;
	dato3.apuntador=&dato4;
	dato4.apuntador=&dato5;
	dato5.apuntador=NULL;
	
	
	cout<<dato1.valor;
	cout<<dato1.apuntador->valor;
	cout<<dato1.apuntador->apuntador->valor;
	cout<<dato1.apuntador->apuntador->apuntador->valor;
	cout<<dato1.apuntador->apuntador->apuntador->apuntador->valor;
return 0;


}	

