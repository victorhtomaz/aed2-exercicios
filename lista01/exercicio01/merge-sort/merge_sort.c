#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

void merge(int arr[], int inicio, int meio, int fim){
    int ponteiroEsq, ponteiroDir, posicao, tamanhoAux, i;

    ponteiroEsq = inicio;
    ponteiroDir = meio + 1;
    posicao = 0;
    tamanhoAux = fim - inicio + 1;
    int aux[tamanhoAux];

    
    while (ponteiroEsq <= meio && ponteiroDir <= fim)
    {
        if (arr[ponteiroEsq] <= arr[ponteiroDir]){
            aux[posicao] = arr[ponteiroEsq];
            ponteiroEsq++;
        }
        else{
            aux[posicao] = arr[ponteiroDir];
            ponteiroDir++;
        }

        posicao++;
    }
    
    for (i = ponteiroEsq; i <= meio; i++){
        aux[posicao] = arr[i];
        posicao++;
    }

    for (i = ponteiroDir; i <= fim; i++){
        aux[posicao] = arr[i];
        posicao++;
    }

    for (i = inicio; i <= fim; i++){
        arr[i] = aux[i - inicio];
    }
}

void merge_sort(int arr[], int inicio, int fim){
    if (inicio < fim){
        int meio;

        meio = (int) (inicio + fim)/2;
        merge_sort(arr, inicio, meio);
        merge_sort(arr, meio + 1, fim);

        merge(arr,inicio, meio, fim);
    }
}