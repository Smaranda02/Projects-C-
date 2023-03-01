/*
 * Scopul problemei este de a sorta mai intai intervalele dupa temperatura maxima (capatul din dreapta al intervalului),
 * iar apoi de a intersecta cat mai multe intervale, iar numarul de intervale rezultate distincte este numarul nostru
 * cauat de frigidere necesare
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct
{
    int t1,t2;  //capatul din stanga, respectiv din dreapta al intervalului
}interval;

void citire(int* n, interval** i, FILE* fin)
{
    int j;
    fscanf(fin,"%d", n);
    (*i)=(interval*)malloc(sizeof(interval)*(*n));

    for(j=0;j<(*n);j++)
        fscanf(fin,"%d %d", &(*i)[j].t1, &(*i)[j].t2);

}

int cmp(const void* a, const void* b)
{
    interval i1= *(interval*)a;
    interval i2= *(interval*)b;
    return i1.t2-i2.t2;  //ordonare crescatoare
}

int greedy(char nume[20])
{
    int n,fridges=0,j;
    interval* i;
    interval i_curent;
    FILE* fin;

    fin=fopen(nume, "r+");
    if(fin==NULL)
        printf("Eroare la deschiderea fisierului");

    citire(&n,&i,fin);
    qsort(i,n,sizeof(interval),cmp);

    i_curent.t1=i[0].t1;
    i_curent.t2=i[0].t2;


    for(j=1;j<n;j++)
        if(i[j].t1<=i_curent.t2)
        {
            if(i[j].t2<i_curent.t2)
                i_curent.t2=i[j].t2;
            if(i[j].t1>i_curent.t1)
                i_curent.t1=i[j].t1;
        }

        else {

            //printf("%d %d\n", i_curent.t1, i_curent.t2); //pentru printarea intervalelor/temperaturilor fiecari frigider
            fridges++;
            i_curent.t1=i[j].t1;
            i_curent.t2=i[j].t2;
        }

    //printf("%d %d\n", i_curent.t1, i_curent.t2);
    fridges++;  ///ultima pereche nu e pusa in calcul
    fclose(fin);
    free(i);

    FILE* fout;
    fout=fopen("out.txt", "w+");
    if(fout==NULL)
        printf("Eroare la deschidere");
    fprintf(fout,"%d",fridges);
    fclose(fout);

    return fridges;
}


int main() {

    int fridges;
    assert((fridges=greedy("in1.txt"))==2);
    assert((fridges=greedy("in2.txt"))==1);
    assert((fridges=greedy("in3.txt"))==2);
    assert((fridges=greedy("in4.txt"))==2);
    assert((fridges=greedy("in5.txt"))==3);

    return 0;
}
