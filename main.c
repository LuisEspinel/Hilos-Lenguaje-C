/*
    Author: Luis Espinel Fuentes.
    Este codigo implementa Threads bajo linux siguiendo el estandar POSIX
    para mas información: https://es.wikipedia.org/wiki/POSIX

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

/* 
    Libreria luigy.h contiene la funcion gotoxy(int x,int y) cuyo codigo es:

    void gotoxy(int x, int y) { 
        printf("33[%d;%df", y, x); 
        fflush(stdout); 
    }
     
*/
#include <luigy.h>

typedef struct{
    char c;
} caracter;

void *hilo1(void *arg){
    char *cadena="hola";
    int i;
    for(i=0;i < strlen(cadena);i++){
        printf("%c\n",cadena[i]);
        fflush(stdout);
        usleep(1000000);
    }
    return NULL;
}

void *hilo2(void *arg){
    char *cadena=" mundo";
    int i;
    for(i=0;i < strlen(cadena);i++){
        printf("%c\n",cadena[i]);
        fflush(stdout);
        usleep(1000000);
    }
    return NULL;
}

void *leerTecla(caracter *c){
    caracter *a=(caracter *)c;
    gotoxy(10,10);
    char cc;
    cc=getch();
    a->c=cc;
    pthread_exit((void *)NULL);
}

int main()
{
    caracter a;
    a.c='s';
    pthread_t h1;
    pthread_t h2;
    pthread_t h3;
    pthread_create(&h1,NULL,hilo1,NULL);
    pthread_create(&h2,NULL,hilo2,NULL);
    pthread_create(&h3,NULL,leerTecla,(void *)&a);
    pthread_join(h1,NULL);
    pthread_join(h2,NULL);
    pthread_join(h3,NULL);
    printf("caracter leido : %c",a.c);
    printf("fin\n");
    return 0;
}
