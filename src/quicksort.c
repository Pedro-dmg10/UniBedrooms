/**
* @author (60997) Rodrigo Luz r.luz@campus.fct.unl.pt
* @author (61680) Pedro Gabriel pd.gabriel@campus.fct.unl.pt 
*/
#include "quicksort.h"

/* Função de troca de elementos */
void troca(void **a, void **b) {
    void *temp = *a;
    *a = *b;
    *b = temp;
}

/* Ordenação de um vetor de elementos, de esq a dir */
void quickSort(void *v[], int esq, int dir,
               void *(*daChave)(void *),
               int (*compChaves)(void *, void *)) {
    int i = esq;
    int j = dir;
    void *p = daChave(v[(i + j) / 2]); // Pivot é o ponto médio

    do {
        while (compChaves(daChave(v[i]), p) < 0) // v[i] < p
            i++;
        while (compChaves(p, daChave(v[j])) < 0) // p < v[j]
            j--;

        if (i <= j)
            troca(&v[i++], &v[j--]); // Troca os elementos

    } while (i <= j);

    if (esq < j)
        quickSort(v, esq, j, daChave, compChaves);
    if (i < dir)
        quickSort(v, i, dir, daChave, compChaves);
}