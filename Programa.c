
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void Ejecutar_Proceso();
void Listado_de_Procesos();
void Matar_Proceso();
int main(int argc, char const *argv[])
{
	char opcion='0';

	do{
		fflush(stdin);
		system("clear");
		printf("MENU\n");
		printf("1)Ejecutar Proceso\n");
		printf("2)Listado de Procesos\n");
		printf("3)Matar Proceso\n");
		printf("4)Salir\n");
		scanf("%c",&opcion);


		if(opcion=='1'){
			Ejecutar_Proceso();
		}else if(opcion=='2'){
			Listado_de_Procesos();
		}else if(opcion=='3'){
			Matar_Proceso();
		}

	}while(opcion!='4');




	return 0;
}
void Ejecutar_Proceso(){
	char comando[100]="", aux='1';
	int sw=0;
	system("clear");
	printf("Introdusca en comando a usar\n");
	fflush(stdin);
	do{
		scanf("%c",&aux);
		if(aux!='\n'){
			comando[strlen(comando)]=aux;
		}
		sw++;
	}while(aux!='\n' || sw<2);

	comando[strlen(comando)]=' ';
	comando[strlen(comando)]='&';
	sw = system(comando);
	printf("Presione 'Enter' para continuar\n");
	while ( getchar() != '\n');
}
void Listado_de_Procesos(){
}
void Matar_Proceso(){

}