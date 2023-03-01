#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// /////////////////////////////// Problema 1 ///////////////////////////////

int s[101], n;

int suma(int k)
{
    int i, scrt;
    scrt = 0;
    for(i = 1; i <= k; i++)
        scrt = scrt + s[i];
    return scrt;
}

int desc_distincte(int *s, int k) {
    if(s[k]<s[k-1])
    return 0;
    return 1;
}

int term_distincti(int *s, int k) {
    for(int i=1;i<k;i++)
            if(s[k]==s[i]) return 0;
    return 1;
}

int desc_distincte_term_distincti(int *s, int k) {

    if(term_distincti(s,k)==1 && desc_distincte(s,k)==1) return 1;
    return 0;

}

int cond_lungime_sir(int k, int k_fix) {
    return k==k_fix;
}

int term_conditie_max(int *s, int k, int term_max) {
    if(s[k]<=term_max) return 1;
    return 0;
}

void bkt(int k) {
    int i, v, scrt;
    for (v = 1; v <= n - k + 1; v++) {
        s[k] = v;
        scrt = suma(k);
        if (scrt <= n) {
            if (scrt <= n && desc_distincte(s, k)) {                     // n = 4: 1+1+1+1, 1+1+2, 1+3, 2+2, 4
               // if (scrt <= n && term_distincti(s, k)) {                     // n = 4: 1+3, 3+1, 4
                   // if (scrt <= n && desc_distincte_term_distincti(s, k)) {      // n = 4: 1+3, 4
                        //if (scrt <= n && term_conditie_max(s, k,2)) {               // n = 4: termeni cel mult egali cu 2: 1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2
                            if (scrt == n)
                                //if (scrt == n && cond_lungime_sir(k,3))                // n = 4: descompuneri de lungime egală cu 3: 1+1+2, 1+2+1 și 2+1+1
                                {
                                    for (i = 1; i <= k; i++)
                                        printf("%d ", s[i]);
                                    printf("\n");
                                }else
                                    bkt(k + 1);
                        }
                    }
                }
            }
    //    }
  //  }
//}

void p1() {
    printf("n = ");
    scanf("%d", &n);
    bkt(1);
}

/// /////////////////////////////// Problema 2 ///////////////////////////////

char *dict[] = {
        "ARM", "ART", "ARTIST", "ARTISTIC",
        "IN", "IS", "OIL",
        "TO", "TODAY", "TOIL"
};

int NR_WORDS = 10;
unsigned input_len;

#define MAX_WORD_LEN 20

int is_word(char *str) {
    int i;
    for(i = 0; i < NR_WORDS; i++)
      if(strcmp(str,dict[i])==0)
           return 1;
    return 0;
}

void bkt_words(char *input_str, char *output, int num_spaces)
{
    unsigned v, local_len = strlen(input_str);
    char bkt[strlen(input_str)*2];
    char prefix[MAX_WORD_LEN];
    char *other_output = malloc(2*input_len); // *2 deoarece pot avea câte un spațiu după fiecare literă

    for(v = 1; v <= local_len ; v++)  // un cuvânt are cel puțin o literă
    {
        strcpy(prefix,input_str);
        prefix[v] = '\0';
        if(is_word(prefix)) {
            // fac o copie a șirului output inițial
            strcpy(bkt,output);
            // adaug prefixul la output-ul deja existent
            strcat(output,prefix);
            // adaug un spațiu între cuvinte
            strcat(output," ");
            if(strlen(output)-num_spaces-1 == input_len)
            {
                printf("%s\n", output);
            }
            else {
                bkt_words(input_str + v, output, num_spaces+1);
            }
            strcpy(output,bkt);
        }
    }
    free(other_output);
}


void p2() {
    char input_str[] = "ARTISTOIL";
    input_len = strlen(input_str);
    char *output = malloc(2*input_len);
    output[0] = '\0';
    bkt_words(input_str, output, 0);
    free(output);
}

/// /////////////////////////////// Problema 3 ///////////////////////////////

#define COUNTRIES 20
int a[COUNTRIES][COUNTRIES], sol[101], nc; //nc e nr de tari;

void read_map() {
    int nr_perechi,j,k,i;
    FILE *in = fopen("in.txt", "r+");
    fscanf(in,"%d %d", &nc, &nr_perechi);
    for(int i=0;i<nr_perechi;i++) {
        fscanf(in,"%d %d", &j, &k);
        a[j][k] = 1;
        a[k][j] = 1;
    }
    fclose(in);
}

int valid(int *sol, int k) {
    int i;
    for(i=1; i<k; i++)
        if(a[i][k]==1 && sol[i]==sol[k])
            return 0;
    return 1;
}

void bkt_map(int k)
{
    int i, v;
    for(v = 1; v <= 4; v++)
    {
        sol[k]=v;
        if(valid(sol,k))
        {
            if(k==nc)
            {
                for(i=1;i<=nc;i++)
                    printf("%d ", sol[i]);
                printf("\n");
            }
            else bkt_map(k + 1);
        }
    }
}

void p3() {
    read_map();
    bkt_map(1);
}

int main()
{
    //p1();
    p2();
    //p3();
    return 0;
}