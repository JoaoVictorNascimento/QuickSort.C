#include <stdio.h>
#include <stdlib.h>

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

    void quicksort(int *v, int inicio, int fim){
        int pivo;
        if(fim>inicio){
            pivo=particiona(v,inicio,fim);
            quicksort(v,inicio,pivo-1);
            quicksort(v,pivo+1,fim);
        }
    }

    int main(){
        int i, tam;
        
        printf("Digite o tamanho do vetor: ");
            scanf("%d", &tam);
        
        int v[tam];
            for(i=0;i<tam;i++){
                printf("Digite um valor: ");
                    scanf("%d", &v[i]);
            }

        quicksort(v,0,tam-1);
        
        for(i=0;i<tam;i++){
            printf("%d ", v[i]);
        }

       

        return 0;
    }