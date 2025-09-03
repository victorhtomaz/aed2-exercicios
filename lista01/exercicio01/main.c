#include <stdio.h>
#include <stdlib.h>
#include "merge-sort/merge_sort.h"
#include "quick-sort/quick_sort.h"

#define TAM 15

void print_array(int arr[]);
int main(void);

void print_array(int arr[]){
    int i;
    for (i=0; i<TAM; i++)
        printf("%d; ", arr[i]);

    printf("\n");
}

int main (void){
    int i;
    int arrMerge[TAM] = {9, 21, 5, 87, 13, 2, 70, 44, 3, 10, 6, 17, 99, 55, 30};
    int arrQuick[TAM] = {33, 17, 88, 5, 29, 71, 12, 44, 95, 6, 2, 50, 4, 8, 20};

    printf("Odernação com Merge Sort: \n");
    print_array(arrMerge);
    merge_sort(arrMerge, 0, TAM - 1);
    print_array(arrMerge);

    printf("Odernação com Quick Sort: \n");
    print_array(arrQuick);
    quick_sort(arrQuick, 0, TAM - 1);
    print_array(arrQuick);

    return 0;
}