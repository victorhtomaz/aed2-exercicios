#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

void troca(int arr[], int i, int j){
    int aux;
    aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux; 
}

int particao(int arr[], int inicio, int fim){
    int pivo, i, j;

    i = inicio - 1;
    j = fim + 1;
    pivo = arr[(inicio + fim)/2];

    while(i < j){
        do {
            j--;
        } while (arr[j] > pivo);

        do{
            i++;
        } while(arr[i] < pivo);

        if (i < j)
            troca(arr, i, j);
    }

    return j;
}

void quick_sort(int arr[], int inicio, int fim){
    int meio;

    if (inicio < fim){
        meio = particao(arr, inicio, fim);
        quick_sort(arr, inicio, meio);
        quick_sort(arr, meio + 1, fim);
    }
}
