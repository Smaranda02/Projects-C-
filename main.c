#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    struct list_st *next;
} *List;

List init_node(int value)
{
    List node = calloc(1, sizeof(struct list_st));
    node->value = value;
    node->next = NULL;

    return node;
}

List add_node(List head, int value)
{
    if (head == NULL) {
        return init_node(value);
    }

    List tmp = head; //cu tmp merg din nod in nod
    List to_add = init_node(value); //ii pun valoare si null in campul next ca o sa fie ultimul
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
//cand tmp-next a ajuns null, il fac sa pointeze catre nodul pe care il adaug
    tmp->next = to_add;

    return head;
}

List add_first(List head, int value)
{
    if (head == NULL) {
        return init_node(value);
    }

    List to_add = init_node(value);//ii adaug valoare si il fca sa pointeze spre null
    to_add->next = head; //il fac sa pointeze spre head

    return to_add;
}

List remove_node(List head, int index)
{
    if (head == NULL) {
        return NULL;
    }

    int k = 0;
    List tmp = head;

/*
daca lista e 1 -> 5 -> 7 -> 8 -> 2 si vreau sa sterg elem de pe poz 3, adica 7
trebuie sa ma duc la elem anterior(5) si sa l fac sa pointeze catre elem urmator(8)
 */

    while (tmp->next) {
        if (k + 1 == index) //cand ajung la pozitia k - 1
            break;
        tmp = tmp->next;
        k++;
    }

//merg cu tmp ul din nod in nod pana ajung la elementul 5, cel care arata catre elem pe care vreau sa il sterg(7)

    if (tmp->next == NULL) {
        return head;
    }
//in timp am elementul de dinaintea celui pe care vreau sa il sterg
    List to_free = tmp->next; //il to_free pun adresa nodului pe care vreau sa il sterg
    tmp->next = to_free->next; //in ex, pe 5 il fac sa pointeze la 7 -> next, adica la 8
    to_free->next = NULL;
    free(to_free);

    return head;
}

void print_list(List head)
{
    List tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(void)
{
    List head = NULL;
    head = add_node(head, 1);
    head = add_node(head, 2);
    head = add_node(head, 3);
    head = add_node(head, 4);
    head = remove_node(head, 1);
    head = add_first(head, 0);
    print_list(head);
    return 0;
}