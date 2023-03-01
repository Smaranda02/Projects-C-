#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "recap_fisiere.h"

int cmpCrescator(const void* a, const void* b)
{
    int va = *(int*)a;
    int vb = *(int*)b;
    if(va < vb) return -1;
    if(va > vb) return +1;
    return 0;
}

int cifraPozX(int n, int x) {
    int nr_cifre = 0, tmp = n;
    while (tmp > 0) {
        tmp /= 10;
        nr_cifre++;
    }
    if (x > nr_cifre) return 0;
    int pow10 = pow(10, nr_cifre - x);
    return (n / pow10) % 10;
}

int cmpLexicografic(const void* a, const void* b)
{
    int va = *(int*)a;
    int vb = *(int*)b;
    int cifa, cifb, c=1;
    while ((va > 0) || (vb > 0)) {
        cifa = cifraPozX(va, c);
        cifb = cifraPozX(vb, c);
        if (cifa < cifb) return -1;
        if (cifa > cifb) return +1;
        c++;
    }
    return 0;
}


void pbCronometru()
{
    int i, n = 10e6;
    n = 10e4;
    int *v = (int*)malloc(n*sizeof(int));
    double t;
    //initializarea generatorului de numere pseudoaleatorii
    //time(NULL) = numarul de secunde trecute de la 01.01.1970
    srand(time(NULL));
    for(i = 0; i < n; i++)
        //functia rand() va genera, la fiecare apel,
        //un numar pseudoaleatoriu cuprins intre 0 si RAND_MAX = 32767
        v[i] = rand();

    for (i = 0; i < n; i++)
      printf("%d ", v[i]);
    printf("\n");
    //numarul de cicli de procesor utilizati de la
    //inceputul programului
    t = clock();

    //sortam "manual" (interschimbare)
    /*int tmp;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (v[i] > v[j]) {
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
    */


    // sortam cu qsort
    qsort(v, n, sizeof(int), cmpCrescator);
    //qsort(v, n, sizeof(int), cmpLexicografic);

    //calculez numarul de cicli de procesor utilizati
    //pentru secventa cronometrata
    t = clock() - t;
    //calculez numarul de secunde in care a fost executata
    //secventa cronometrata
    //CLOCKS_PER_SEC = numarul de cicli per secunda
    t = t / CLOCKS_PER_SEC;

    for (i = 0; i < n; i++)
      printf("%d ", v[i]);
    printf("\n");


    printf("Timp de executare sortare: %.2f secunde\n", t);


    //printf("Cifra poz %d din %d: %d\n;", 3, 837192, cifraPozX(837192, 3));
    printf("\n");
    free(v);
}
