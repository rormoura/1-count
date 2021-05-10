#include <stdio.h>
#include <stdlib.h>

struct integer // nodes from the linked list
{
    int n;
    struct integer *next;
};
typedef struct integer Int;

int Length (Int *head)
{
    int length = 0; // we need it, obviously

    Int *aux1 = (Int *) malloc(sizeof(Int)); // iterating down the list to get it's length
    if(aux1 == NULL)
    {
        printf("Allocation error :/\n");
        exit(-1);
    }
    aux1 = head;
    if(aux1 == NULL) // empty list
    {
        return 0;
    }
    while(aux1->next != NULL)
    {
        length++;
        aux1 = aux1->next;
    }
    if(aux1->next == NULL)
    {
        length++;
    }

    return length; // returning it
}

void InsertNth (Int **head, int index1, int a)
{
    int i = 0;
    int index = index1, len = Length(*head);
    printf("LEN: %d\n", len);
    while(index < 0 || index > len) // verifying the index1 validation
    {
        printf("Please, input a valid number (between 0...%d): ", len);
        scanf("%d", &index);
    }

    Int *aux = (Int *) malloc(sizeof(Int));
    Int *aux1 = (Int *) malloc(sizeof(Int));
    Int *aux2 = (Int *) malloc(sizeof(Int));
    if (aux == NULL || aux1 == NULL || aux2 == NULL)
    {
        printf("Allocation error :/\n");
        exit(-1);
    }
    aux->n = a;

    if (index == 0) // inserting the new node at the head
    {
        aux->next = *head;
        *head = aux;
    }
    else if (index > 0 && index < len)
    {
        // iterating down the list "index-1" times bc we need to "stop" at the element that preceds the position
        // we're gonna insert the new node
        aux1 = *head;
        for(i = 0; i < index-1; i++)
        {
            aux1 = aux1->next;
        }
        aux->next = aux1->next;
        aux1->next = aux;
    }
    else if(index == len) // inserting the new node at the end of the list
    {
        aux1 = *head;
        while (aux1->next != NULL)
        {
            aux1 = aux1->next;
        }
        aux->next = NULL;
        aux1->next = aux;
    }

    aux2 = *head; // printing the new list
    if(aux2->next == NULL)
    {
        printf("\t\tNew list:\n");
        printf("Node 0: %d\n", aux2->n);
    }
    else
    {
        i = 0;
        printf("\t\tNew list:\n");
        while(aux2->next != NULL)
        {
            printf("Node %d: %d\n", i, aux2->n);
            aux2 = aux2->next;
            i++;
        }
        if(aux2->next == NULL)
        {
            printf("Node %d: %d\n", i, aux2->n);
        }
    }
    
    aux = NULL; // deallocating the memory we used
    aux1 = NULL;
    aux2 = NULL;
    free(aux);
    free(aux1);
    free(aux2);
}

int main ()
{
    int i = 0; // to iteration
    int b = 0; // to adding new nodes
    int index = 0; // to receive the index that will be used in the InsertNth function

    Int *head = (Int *) malloc(sizeof(Int)); // creating the linked list head we're gonna use
    if(head == NULL)
    {
        printf("Allocation error.\n");
        exit(-1);
    }
    head = NULL; 

    for (i = 0; i < 6; i++) // for loop to add the five nodes of the list
    {

        printf("Input the integer: ");
        scanf("%d", &b);
        printf("Input the index: ");
        scanf("%d", &index);
        InsertNth(&head, index, b);
    }

    return 0;
}