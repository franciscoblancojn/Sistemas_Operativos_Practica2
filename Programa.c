
#include <stido.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int opcion=-1;

	do{
		system("cls");
		printf("MENU\n");
		printf("1)Ejecutar Proceso\n");
		printf("2)Listado de Procesos\n");
		printf("3)Matar Proceso\n");
		printf("4)Salir\n");
		fscanf("%i",&opcion);
		if(opcion==1){
		}else if(opcion==2){

		}else if(opcion==3){

		}
		printf("%i\n",opcion );

	}while(opcion!=4);




	return 0;
}