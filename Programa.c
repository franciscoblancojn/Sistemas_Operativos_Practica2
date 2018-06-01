
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
	while ( getchar() != '\n');
    int maxpid;
	FILE *fn = fopen("/proc/sys/kernel/pid_max", "r");
	fscanf(fn, "%i",&maxpid);
	fclose(fn);

    char statFileName[128] ,aux [10];
	FILE *fd;
	char encabesado[10][15]={"PID","CMD","Estado","PPID","Tiempo usuario",
								"Tiempo kernel","Nice","Threads","Iniciado en","Tamaño"};
	printf("%-5s",encabesado[0]);
	printf("%-20s",encabesado[1]);
	printf("%-10s",encabesado[2]);
	printf("%-10s",encabesado[3]);
	printf("%-17s",encabesado[4]);
	printf("%-17s",encabesado[5]);
	printf("%-10s",encabesado[6]);
	printf("%-10s",encabesado[7]);
	printf("%-15s",encabesado[8]);
	printf("%-10s\n",encabesado[9]);
	for(int i=1;i<maxpid;i++){
		strcpy(statFileName,"/proc/");
		snprintf( aux,10, "%d", i );
		strcat(statFileName,aux);
		strcat(statFileName,"/stat");
		fd = fopen(statFileName, "r");
		if(fd){
			    char
			    state,
			      name[32];
			    int
			      pid,
			      ppid,
			      pgrp,
			      session,
			      tty,
			      tpgid,
			      nlwp;

			    unsigned long
			    flags,
			      min_flt,
			      cmin_flt,
			      maj_flt,
			      cmaj_flt,
			      vsize;

			    unsigned long long
			    utime,
			      stime,
			      cutime,
			      cstime,
			      start_time;

			    long
			    priority,
			      nice,
			      alarm,
			      rss;
			   
			    fscanf(fd, "%d %s "
			                 "%c "
			                 "%d %d %d %d %d "
			                 "%lu %lu %lu %lu %lu "
			                 "%Lu %Lu %Lu %Lu "
			                 "%ld %ld "
			                 "%d "
			                 "%ld "
			                 "%Lu "
			                 "%lu "
			                 "%ld",
			                 &pid,
			                 name,
			                 &state,
			                 &ppid, &pgrp, &session, &tty, &tpgid,
			                 &flags, &min_flt, &cmin_flt, &maj_flt, &cmaj_flt,
			                 &utime, &stime, &cutime, &cstime,
			                 &priority, &nice,
			                 &nlwp,
			                 &alarm,
			                 &start_time,
			                 &vsize,
			                 &rss);
			   
			    fclose(fd);
			    printf("%-5d",pid);
				printf("%-20s",name);
				printf("%-10c",state);
				printf("%-10d",ppid);
				printf("%-17Lu",utime);
				printf("%-17Lu",stime);
				printf("%-10ld",nice);
				printf("%-10d",nlwp);
				printf("%-15Lu",start_time);
				printf("%-10lu\n",vsize);
		}
	}




    printf("Presione 'Enter' para continuar\n");
	while ( getchar() != '\n');

}
void Matar_Proceso(){

}