#include <stdio.h>
#include <stdlib.h>
#define T 10

    void quicksort(int *v, int inicio, int fim){
        int pivo;
        if(fim>inicio){
            pivo=particiona(v,inicio,fim);
            quicksort(v,inicio,pivo-1);
            quicksort(v,pivo+1,fim);
        }
    }

    int particiona(int *v,int inicio,int fim){
        int esq,dir,pivo,aux;
        esq=inicio;
        dir=fim;
        pivo=v[esq];

        while(esq<dir){

            while(v[esq]<=pivo)
              esq++;

            while(v[dir]>pivo)
                dir--;


            if(esq<dir){
                aux=v[esq];
                v[esq]=v[dir];
                v[dir]=aux;
            }
        }
        v[inicio]=v[dir];
        v[dir]=pivo;
        return dir;
    }

    int main(){
        int v[T]={15,7,1,2,1,6,7,8,9,5},i;

        quicksort(v,0,T-1);

        while(i<=T-1){
        printf("%d ",v[i]);
        i++;
        }

        return 0;
    }

