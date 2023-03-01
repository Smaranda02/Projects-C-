#include <stdio.h>
#include <stdlib.h>
int main() {

    int candidates,i;
    scanf("%d", &candidates);
    int* votes;
    votes=(int*)malloc(sizeof(int)*candidates);
    for(i=0;i<candidates;i++)
        scanf("%d", &votes[i]);

    int advantage=1, potential_winner=votes[0];
    for(i=1;i<candidates;i++) {
        if (votes[i] == potential_winner)
            advantage++;
        else {
            advantage--;
            if(advantage==0)
            {potential_winner=votes[i]; advantage=1;}
        }
    }

    if(advantage==0)
        printf("Nobody won the majority");
    else {
        int majority=0;
        for(i=0;i<candidates;i++)
            if(votes[i]==potential_winner) majority++;
        if(majority>candidates/2)
            printf("Candidate %d won the majority!", potential_winner);
        else printf("Nobody won the majority");
    }
    return 0;
}
