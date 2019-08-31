#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CANT_AGRAGAR_VOLUMEN 500
#define CANT_AGRAGAR_VACIA 20
#define CANT_AGREGAR_ITER 10

void pruebas_crear_destruir(){
	printf("\n--CREAR/DESTRUIR--\n");
	void* nulo = NULL;
	lista_t* lista = lista_crear();
	print_test("Se creo una lista", lista!=NULL);
	lista_destruir(lista, nulo);
	print_test("Se destruyo la lista", true);	
}

void pruebas_destruir(){
	printf("\n--DESTRUIR--\n");
	char* dato = malloc(sizeof(char));
	if (!dato){
		return;
	}
	char* dato1 = malloc(sizeof(char));
	if (!dato1){
		return;
	}
	char* dato2 = malloc(sizeof(char));
	if (!dato2){
		return;
	}
	char* dato3 = malloc(sizeof(char));
	if (!dato3){
		return;
	}
	
	/*Pruebas de 1 elemento*/
	lista_t* lista = lista_crear();
	print_test("Creo una lista", lista!=NULL);
	print_test("Inserto un dato", lista_insertar_primero(lista, dato) == true);
	lista_destruir(lista, free);
	print_test("Destruyo la lista y su dato", true);
	
	/*Pruebas de varios elementos*/
	lista = lista_crear();
	print_test("Creo una lista", lista!=NULL);
	print_test("Inserto dato1", lista_insertar_primero(lista, dato1) == true);
	print_test("Inserto dato2", lista_insertar_primero(lista, dato2) == true);
	print_test("Inserto dato3", lista_insertar_primero(lista, dato3) == true);
	lista_destruir(lista, free);
	print_test("Destruyo la lista y sus datos", true);	
}

void pruebas_vacia(){
	printf("\n--VACIA--\n");
	lista_t* lista = lista_crear();
	print_test("Se creo una lista", lista!=NULL);
	print_test("La lista esta vacia", lista_esta_vacia(lista) == true);
	print_test("No puede borrar el primer elemento",lista_borrar_primero(lista) == NULL);
	print_test("Su largo es 0", lista_largo(lista) == 0);
	print_test("No hay primero", lista_ver_primero(lista) == NULL);
	print_test("No hay ultimo", lista_ver_ultimo(lista) == NULL);
	
	lista_destruir(lista, NULL);
}

void pruebas_insertar_borrar_primero(){
	printf("\n--INSERTAR/BORRAR PRIMERO--\n");
	lista_t* lista = lista_crear();
	int valor1[] = {0};
	int valor2[] = {489};
	int valor3[] = {68};
	
	/*Pruebas con 1 elemento*/
	print_test("Inserta valor1 como primer elemento", lista_insertar_primero(lista, valor1) == true);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("Borra el primero elemento: valor1", lista_borrar_primero(lista) == valor1);
	print_test("Esta vacia", lista_esta_vacia(lista) == true);
	
	/*Pruebas con varios elementos*/
	print_test("Inserta valor2 como primer elemento", lista_insertar_primero(lista, valor2) == true);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("Inserta valor3 como primer elemento", lista_insertar_primero(lista, valor3) == true);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("Borra el primero elemento: valor3", lista_borrar_primero(lista) == valor3);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("Borra el primero elemento: valor2", lista_borrar_primero(lista) == valor2);
	print_test("Esta vacia", lista_esta_vacia(lista) == true);
	
	lista_destruir(lista, NULL);
}

void pruebas_ver_primero(){
	printf("\n--VER PRIMERO--\n");
	lista_t* lista = lista_crear();
	int valor1[] = {0};
	int valor2[] = {489};
	int valor3[] = {68};
	
	/*Pruebas con 1 elemento*/
	print_test("Inserta valor1 como primer elemento", lista_insertar_primero(lista, valor1) == true);
	print_test("El primer elemento es valor1", lista_ver_primero(lista) == valor1);
	print_test("Borra el primero elemento: valor1", lista_borrar_primero(lista) == valor1);
	print_test("No hay primero", lista_ver_primero(lista) == NULL);
	
	/*Pruebas con varios elementos*/
	print_test("Inserta valor2 como primer elemento", lista_insertar_primero(lista, valor2) == true);
	print_test("El primer elemento es valor2", lista_ver_primero(lista) == valor2);
	print_test("Inserta valor3 como primer elemento", lista_insertar_primero(lista, valor3) == true);
	print_test("El primer elemento es valor3", lista_ver_primero(lista) == valor3);
	print_test("Borra el primero elemento: valor3", lista_borrar_primero(lista) == valor3);
	print_test("El primer elemento es valor2", lista_ver_primero(lista) == valor2);
	print_test("Borra el primero elemento: valor2", lista_borrar_primero(lista) == valor2);
	print_test("No hay primero", lista_ver_primero(lista) == NULL);
	
	lista_destruir(lista, NULL);
}

void pruebas_insertar_borrar_ultimo(){
	printf("\n--INSERTAR/BORRAR ULTIMO--\n");
	lista_t* lista = lista_crear();
	int valor4[] = {34};
	int valor5[] = {758};
	int valor6[] = {89};
	
	/*Pruebas con 1 elemento*/
	print_test("Inserta valor4 como ultimo elemento", lista_insertar_ultimo(lista, valor4) == true);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("Borra el primer elemento: valor4", lista_borrar_primero(lista) == valor4);
	print_test("Esta vacia", lista_esta_vacia(lista) == true);
	
	/*Pruebas con varios elementos*/
	print_test("Inserta valor5 como ultimo elemento", lista_insertar_ultimo(lista, valor5) == true);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("Inserta valor6 como ultimo elemento", lista_insertar_ultimo(lista, valor6) == true);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("Borra el primer elemento: valor5", lista_borrar_primero(lista) == valor5);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("Borra el primer elemento: valor6", lista_borrar_primero(lista) == valor6);
	print_test("Esta vacia", lista_esta_vacia(lista) == true);
	
	lista_destruir(lista, NULL);
}

void pruebas_ver_ultimo(){
	printf("\n--VER ULTIMO--\n");
	lista_t* lista = lista_crear();
	int valor4[] = {34};
	int valor5[] = {758};
	int valor6[] = {89};
	
	/*Pruebas con 1 elemento*/
	print_test("Inserta valor4 como ultimo elemento", lista_insertar_ultimo(lista, valor4) == true);
	print_test("El ultimo elemento es valor4", lista_ver_ultimo(lista) == valor4);
	print_test("Borra el primer elemento: valor4", lista_borrar_primero(lista) == valor4);
	print_test("No hay ultimo", lista_ver_ultimo(lista) == NULL);
	
	/*Pruebas con varios elementos*/
	print_test("Inserta valor5 como ultimo elemento", lista_insertar_ultimo(lista, valor5) == true);
	print_test("El ultimo elemento es valor5", lista_ver_ultimo(lista) == valor5);
	print_test("Inserta valor6 como ultimo elemento", lista_insertar_ultimo(lista, valor6) == true);
	print_test("El ultimo elemento es valor6", lista_ver_ultimo(lista) == valor6);
	print_test("Borra el primer elemento: valor5", lista_borrar_primero(lista) == valor5);
	print_test("El ultimo elemento es valor6", lista_ver_ultimo(lista) == valor6);
	print_test("Borra el primer elemento: valor6", lista_borrar_primero(lista) == valor6);
	print_test("No hay ultimo", lista_ver_ultimo(lista) == NULL);
	
	lista_destruir(lista, NULL);
}

void pruebas_largo_volumen(){
	printf("\n--LARGO/VOLUMEN--\n");
	lista_t* lista = lista_crear();
	int valor[] = {765};
	
	/*Prueba con 500 elementos*/
	for (int i = 0; i < CANT_AGRAGAR_VOLUMEN; i++){
		lista_insertar_primero(lista, valor);
	}
	print_test("Puede almacenar 500 elementos", true);
	print_test("Luego de ingresar 500 elementos, su largo es 500", lista_largo(lista) == 500);
	
	/*Prueba vaciada*/
	for (int i = 0; i < CANT_AGRAGAR_VOLUMEN; i++){
		lista_borrar_primero(lista);
	}
	print_test("Puede borrar 500 elementos", true);
	print_test("Luego de vaciarla tiene un largo de 0", lista_largo(lista) == 0);
	
	lista_destruir(lista, NULL);
}

void pruebas_nulo(){
	printf("\n--CON NULO--\n");
	lista_t* lista = lista_crear();
	void* nulo = NULL;
	
	print_test("Esta vacia", lista_esta_vacia(lista) == true);
	print_test("Inserto NULL primero", lista_insertar_primero(lista, nulo) == true);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("El primero es NULL", lista_ver_primero(lista) == nulo);
	print_test("El ultimo es NULL", lista_ver_ultimo(lista) == nulo);
	print_test("Borro NULL", lista_borrar_primero(lista) == nulo);
	print_test("Inserto NULL ultimo", lista_insertar_ultimo(lista, nulo) == true);
	print_test("No esta vacia", lista_esta_vacia(lista) == false);
	print_test("El primero es NULL", lista_ver_primero(lista) == nulo);
	print_test("El ultimo es NULL", lista_ver_ultimo(lista) == nulo);
	print_test("Borro NULL", lista_borrar_primero(lista) == nulo);
	print_test("Esta vacia", lista_esta_vacia(lista) == true);
	
	lista_destruir(lista, NULL);
}

void pruebas_iter_crear_destruir(){
	printf("\n--CREAR/DESTRUIR ITERADOR--\n");
	lista_t* lista = lista_crear();
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("Se creo un iterador para la lista", iter!=NULL);
	lista_iter_destruir(iter);
	print_test("Destruyo el iterador", true);
	lista_destruir(lista, NULL);
}

void pruebas_iter_insertar_principio(){
	printf("\n--INSERTAR CON ITERADOR AL PRINCIPIO--\n");
	lista_t* lista = lista_crear();
	lista_iter_t* iter = lista_iter_crear(lista);
	int valor1[] = {0};
	int valor2[] = {489};
	int valor3[] = {68};
	
	/*Pruebas en lista vacia*/
	print_test("Se creo una lista", lista!=NULL);
	print_test("Se creo un iterador para la lista", iter!=NULL);
	print_test("Inserto valor1 con el iterador", lista_iter_insertar(iter, valor1) == true);
	print_test("El primer elemento es valor1", lista_ver_primero(lista) == valor1);
	lista_iter_destruir(iter);
	print_test("Se destruyo el iterador", true);
	
	/*Pruebas en lista con 1 valor*/
	iter = lista_iter_crear(lista);
	print_test("Se vuelve a crear un iterador para la lista", iter!=NULL);
	print_test("Inserto valor2 con el iterador", lista_iter_insertar(iter, valor2) == true);
	print_test("El primer elemento es valor2", lista_ver_primero(lista) == valor2);
	lista_iter_destruir(iter);
	print_test("Se destruyo el iterador", true);
	
	/*Pruebas con mas de 1 elemento*/
	iter = lista_iter_crear(lista);
	print_test("Se vuelve a crear un iterador para la lista", iter!=NULL);
	print_test("Inserto valor3 con el iterador", lista_iter_insertar(iter, valor3) == true);
	print_test("El primer elemento es valor3", lista_ver_primero(lista) == valor3);
	
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
}

void pruebas_iter_insertar_final(){
	printf("\n--INSERTAR CON ITERADOR AL FINAL--\n");
	lista_t* lista = lista_crear();
	int valor[] = {489};
	int valor1[] = {68};
	
	/*Inserto CANT_AGREGAR_ITER elementos*/
	for (int i = 0; i < CANT_AGREGAR_ITER; i++){
		lista_insertar_ultimo(lista, valor);
	}
	
	lista_iter_t* iter = lista_iter_crear(lista);
	
	/*Avanzo hasta el final*/
	for (int i = 0; i < CANT_AGREGAR_ITER; i++){
		lista_iter_avanzar(iter);
	}
	
	print_test("El iterador esta al final de la lista", lista_iter_al_final(iter) == true);
	print_test("Inserto valor1 con el iterador", lista_iter_insertar(iter, valor1) == true);
	print_test("El ultimo elemento es valor1", lista_ver_ultimo(lista) == valor1);
	
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
}

void pruebas_iter_insertar_medio(){
	printf("\n--INSERTAR CON ITERADOR EN EL MEDIO--\n");
	lista_t* lista = lista_crear();
	int valor0[] = {489};
	int valor1[] = {68};
	int valor2[] = {37};
	int valor3[] = {543};
	
	/*Inserto valores en la lista*/
	print_test("Inserto valor0 en la lista", lista_insertar_ultimo(lista, valor0) == true);
	print_test("Inserto valor1 en la lista", lista_insertar_ultimo(lista, valor1) == true);
	print_test("Inserto valor2 en la lista", lista_insertar_ultimo(lista, valor2) == true);
	
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("Creo un iterador", iter!=NULL);
	print_test("Avanzo a la segunda posicion con el iterador", lista_iter_avanzar(iter) == true);
	print_test("El dato actual es valor1", lista_iter_ver_actual(iter) == valor1);
	print_test("Inserto valor3", lista_iter_insertar(iter, valor3) == true);
	print_test("El dato actual es valor3", lista_iter_ver_actual(iter) == valor3);
	print_test("Avanzo a la tercer posicion con el iterador", lista_iter_avanzar(iter) == true);
	print_test("El dato actual es valor1", lista_iter_ver_actual(iter) == valor1);
	
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
}

void pruebas_iter_borrar_principio(){
	printf("\n--BORRAR CON ITERADOR AL PRINCIPIO--\n");
	lista_t* lista = lista_crear();
	int valor0[] = {489};
	int valor1[] = {68};
	
	/*Pruebas con lista vacia*/
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("Si esta vacia no borra nada", lista_iter_borrar(iter) == NULL);
	lista_iter_destruir(iter);
	print_test("Se destruyo el iterador", true);
	
	/*Pruebas con 1 elemento*/
	iter = lista_iter_crear(lista);
	print_test("Inserto valor0 en la lista", lista_iter_insertar(iter, valor0) == true);
	print_test("Se borra el valor0", lista_iter_borrar(iter) == valor0);
	lista_iter_destruir(iter);
	print_test("Se destruyo el iterador", true);
	
	/*Pruebas con varios elementos*/
	iter = lista_iter_crear(lista);
	print_test("Inserto valor1 en la lista", lista_iter_insertar(iter, valor1) == true);
	print_test("Inserto valor0 en la lista", lista_iter_insertar(iter, valor0) == true);
	print_test("Se borra el valor0", lista_iter_borrar(iter) == valor0);
	print_test("Se borra el valor1", lista_iter_borrar(iter) == valor1);
	
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
}

void pruebas_iter_borrar_ultimo(){
	printf("\n--BORRAR CON ITERADOR AL FINAL--\n");
	lista_t* lista = lista_crear();
	int valor0[] = {489};
	int valor1[] = {68};

	/*Pruebas con varios elementos*/
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("Inserto valor1 en la lista", lista_iter_insertar(iter, valor1) == true);
	print_test("Inserto valor0 en la lista", lista_iter_insertar(iter, valor0) == true);
	print_test("Avanzo a la ultima posicion", lista_iter_avanzar(iter) == true);
	print_test("Se borra el valor1", lista_iter_borrar(iter) == valor1);
	print_test("Ultimo es ahora valor0", lista_ver_ultimo(lista) == valor0);
	
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
}

void pruebas_iter_borrar_medio(){
	printf("\n--BORRAR CON ITERADOR EN EL MEDIO--\n");
	lista_t* lista = lista_crear();
	int valor0[] = {489};
	int valor1[] = {68};
	int valor2[] = {37};
	
	/*Inserto valores en la lista*/
	print_test("Inserto valor0 en la lista", lista_insertar_ultimo(lista, valor0) == true);
	print_test("Inserto valor1 en la lista", lista_insertar_ultimo(lista, valor1) == true);
	print_test("Inserto valor2 en la lista", lista_insertar_ultimo(lista, valor2) == true);
	
	lista_iter_t* iter = lista_iter_crear(lista);
	print_test("Creo un iterador", iter!=NULL);
	print_test("Avanzo a la segunda posicion con el iterador", lista_iter_avanzar(iter) == true);
	print_test("El dato actual es valor1", lista_iter_ver_actual(iter) == valor1);
	print_test("Borro valor1", lista_iter_borrar(iter) == valor1);
	print_test("El dato actual es valor2", lista_iter_ver_actual(iter) == valor2);
	print_test("La siguiente es la ultima posicion", lista_iter_avanzar(iter) == true && lista_iter_al_final(iter) == true);
	
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
}

//Devuelve la suma entre nro1 y nro2.
bool sumar(void* nro1, void* nro2){
	int *valor1 = (int*)nro1;
	int *valor2 = (int*)nro2;
	*valor1 += *valor2;
	return true;
}

//Devuelve la suma entre nro1 y nro2 si el primero es menor al segundo.
bool suma_condicional(void* nro1, void* nro2){
	int *valor1 = (int*)nro1;
	int *valor2 = (int*)nro2;
	if((*valor1) > (*valor2)){
		return false;
	}
	*valor1 += *valor2;
	return true;
}

void pruebas_iter_interno(){
	printf("\n--ITERADOR INTERNO--\n");
	lista_t* lista = lista_crear();
	int dato[] = {1};
	int dato1[] = {2};
	int dato2[] = {3};
	int dato3[] = {4};
	int suma1 = 1;
	int suma2 = 3;
	
	/*Prueba con corte*/
	print_test("Inserto valor0 en la lista", lista_insertar_ultimo(lista, dato) == true);
	print_test("Inserto valor1 en la lista", lista_insertar_ultimo(lista, dato1) == true);
	print_test("Inserto valor2 en la lista", lista_insertar_ultimo(lista, dato2) == true);
	print_test("Inserto valor3 en la lista", lista_insertar_ultimo(lista, dato3) == true);
	lista_iterar(lista, sumar, &suma1);
	print_test("Sumo 'suma1' a cada valor de la lista", (2 == dato[0] && 3 == dato1[0] && 4 == dato2[0] && 5 == dato3[0]));
	
	lista_iterar(lista, suma_condicional, &suma2);
	print_test("Sumo 'suma2' a los valores menores o iguales a esta", 5 == dato[0] && 6 == dato1[0] && 4 == dato2[0] && 5 == dato3[0]);
	
	lista_destruir(lista, NULL);
}
	
void pruebas_lista_alumno(){
	pruebas_crear_destruir();
	pruebas_destruir();
	pruebas_vacia();
	pruebas_insertar_borrar_primero();
	pruebas_ver_primero();
	pruebas_insertar_borrar_ultimo();
	pruebas_ver_ultimo();
	pruebas_largo_volumen();
	pruebas_nulo();
	pruebas_iter_crear_destruir();
	pruebas_iter_insertar_principio();
	pruebas_iter_insertar_final();
	pruebas_iter_insertar_medio();
	pruebas_iter_borrar_principio();
	pruebas_iter_borrar_ultimo();
	pruebas_iter_borrar_medio();
	pruebas_iter_interno();
}
