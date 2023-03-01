///GRUPA 161, ANDRONIC SMARANDA, PROBLEMA 1-SUDOKU

#include <stdio.h>
#include <stdlib.h>

int validare(int** a,int l,int c)
{
    for(int j=0;j<9;j++)
        if(a[l][c]==a[l][j] && c!=j) return 0;
    for(int i=0;i<9;i++)
        if(a[i][c]==a[l][c] && i!=l) return 0;
    return 1;
}


void read_data(int ***a, char nume[20])
{
    int i;
    FILE *fin;
    fin=fopen(nume,"r+");
    if(fin==NULL)
        printf("Eroare la deschiderea fisierului");

    (*a)=(int**)malloc(sizeof(int*)*9);
    for(i=0;i<9;i++)
        (*a)[i]=(int*)malloc(sizeof(int)*9);

    for(i=0;i<9;i++)
        for(int j=0;j<9;j++)
        fscanf(fin,"%d",&(*a)[i][j]);

    fclose(fin);

}

void afisare(int** a)
{
    FILE* fout;
    fout=fopen("out.txt","w+");
    if(fout==NULL)
        printf("Eroare la deschiderea fisierului");

    for(int i=0;i<9;i++) {
        for (int j = 0; j < 9; j++)
            fprintf(fout,"%d ", a[i][j]);
        fprintf(fout,"\n");
    }

    fprintf(fout,"\n");

    fclose(fout);

}


void bkt(int** a,int l,int c) {

    if (a[l][c] == 0) {
        for (int i = 1; i <= 9; i++) {
            a[l][c] = i;
            if (validare(a, l, c)) {
                if (c < 8) bkt(a, l, c + 1);
                else if (c == 8 && l < 8)
                    bkt(a, l + 1, 0);
                else if (c == 8 && l == 8)
                    afisare(a);

            }
            a[l][c] = 0;

        }
    }
        else {
            if (c < 8) bkt(a, l, c + 1);
            else if (c == 8 && l < 8)
                bkt(a, l + 1, 0);
            else if (c == 8 && l == 8)
                afisare(a);

        }


}

int pb_bkt(char nume[20])
{
    int **a;

    read_data(&a, nume);
    bkt(a,0,0);

    for(int i=0;i<9;i++)
        free(a[i]);
    free(a);

}

int main() {

    //pb_bkt("in.txt");
    pb_bkt("in2.txt");
    //pb_bkt("in3.txt");


    return 0;
}


/*
 *
 * 5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

*/
