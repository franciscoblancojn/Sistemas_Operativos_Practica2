
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void Ejecutar_Proceso();
void Listado_de_Procesos();
void Matar_Proceso();
int main(int argc, char const *argv[])
{
	int opcion=-1;

	do{
		printf("MENU\n");
		printf("1)Ejecutar Proceso\n");
		printf("2)Listado de Procesos\n");
		printf("3)Matar Proceso\n");
		printf("4)Salir\n");
		scanf("%i",&opcion);


		if(opcion==1){
			Ejecutar_Proceso();
		}else if(opcion==2){
			Listado_de_Procesos();
		}else if(opcion==3){
			Matar_Proceso();
		}

	}while(opcion!=4);




	return 0;
}
void Ejecutar_Proceso(){

}
void Listado_de_Procesos(){
}
void Matar_Proceso(){

}