#include "lista.h"
#include "testing.h"
#include <stdio.h>
#include "testing.c"

int main(){
	pruebas_lista_alumno();
	return failure_count() > 0;
}

