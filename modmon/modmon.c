#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]){
	if(argc==1){
		printf("El comando recibe 1 rgumento:\n\tNombre del adaptador.\nDos argumentos:\n\tmodmon [opcion] [Nombre adaptador]\nPara mas informacion:\n\tmodmon --help");
	}else if(argc==2){
		if(strcmp(argv[1],"-v")==0||strcmp(argv[1],"--version")==0){
                        printf("modmon version 1.0");
                }else if(strcmp(argv[1],"-h")==0||strcmp(argv[1],"--help")==0){
                        printf("--help | -h \tMuestra ayuda");
                        printf("\n--connection | -c\t Activa modo monitor sin desconectar de la red\n\tmodmon -c [Adaptador]");
                        printf("\n--about | -a\t Muestra informacion sobre modmon");
                        printf("\n--version | -v \t Muestra la version de modmon\n");
                }else if(strcmp(argv[1],"-a")==0||strcmp(argv[1],"--about")==0){
			printf("Este comando fue desarrollado para hacer mas rapido la activacion del modo monitor.\nLenguaje utilizado [ C ]\nComandos Utilizados:\n\tairmon-ng check kill\n\tiw [interfaz] set type monitor\n\trfkill unblock wifi\n\tip l s [interfaz] up\n\tiwconfig | grep Mode:\n\tairmon-ng start [interfaz]\n\tDesarrollado por ALHUBO");
		}else if(strcmp(argv[1],"-c")!=0&&strcmp(argv[1],"--connection")!=0){
			printf("Matando procesos de red...\n");
			system("sudo airmon-ng check kill");
			printf("Activando  modo Monitor en %s...\n",argv[1]);
			char tmp[100];
			strcpy(tmp,"sudo iw ");
			strcat(tmp,argv[1]);
			strcat(tmp," set type monitor");
			system(tmp);
			printf("Confirmando que no hay procesos que desactiven...\n");
			system("sudo rfkill unblock wifi");
			printf("Activando adaptdor %s...\n",argv[1]);
			strcpy(tmp,"ip l s ");
			strcat(tmp,argv[1]);
			strcat(tmp," up");
			system(tmp);
			printf("Verificando resultado:\n");
			system("iwconfig | grep Mode:");
		}else{
			printf("Prueba con el argumento --help");
		}
	}else if(argc==3){
		if(strcmp(argv[1],"-c")==0||strcmp(argv[1],"--connection")==0){
			printf("Activando modo monitor en %s...\n",argv[2]);	
			char tmp[100];
			strcpy(tmp,"sudo airmon-ng start ");
			strcat(tmp,argv[2]);
			system(tmp);
		}else{
			printf("\nPrueba:\n modmon --help\n");
		}
	}
}
