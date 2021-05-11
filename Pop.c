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

    free(aux1);
    return length; // returning it
}

void Push (Int **head, int a) // it adds a new node at the head
{
    int i = 0;
    Int *aux = (Int *) malloc(sizeof(Int));
    Int *aux1 = (Int *) malloc(sizeof(Int));
    if(aux == NULL || aux1 == NULL)
    {
        printf("Allocation error :/\n");
        exit(-1);
    }

    if(*head == NULL) // it means that the list is empty
    {
        aux->n = a;
        aux->next = NULL;
        *head = aux;
    }
    else // it means that the list isn't empty
    {
        aux->n = a;
        aux->next = *head;
        *head = aux;
    }

    printf("\t\tNew node added\n"); // printing the new list
    aux1 = *head;
    while(aux1->next != NULL)
    {
        printf("Node %d: %d\n", i, aux1->n);
        aux1 = aux1->next;
        i++;
        if(aux1->next == NULL)
        {
            printf("Node %d: %d\n", i, aux1->n);
        }
    }
}

void Pop (Int **head)
{
    int i = 0;
    Int *aux = (Int *) malloc(sizeof(Int));
    Int *aux1 = (Int *) malloc(sizeof(Int));
    if(aux == NULL || aux1 == NULL)
    {
        printf("Allocation error :/\n");
        exit(-1);
    }

    if(*head == NULL) // if the list is empty
    {
        printf("There is no node to pop\n");
        exit(-1);
    }
    else // if the list isn't empty
    {
        aux = *head;
        if(aux->next == NULL) // if it is the last node remaining
        {
            *head = NULL; // now the list is empty
        }
        else
        {
            *head = aux->next;
        }
    }

    i = 0;
    printf("\t\tNew list:\n"); // printing the new list
    if(*head == NULL) // if the list is empty
    {
        printf("Empty list\n");
    }
    else // if the list isn't empty
    {
        aux1 = *head;
        if(aux1->next == NULL)
        {
            printf("Node %d: %d\n", i, aux1->n);
        }
        else
        {
            while(aux1->next != NULL)
            {
                printf("Node %d: %d\n", i, aux1->n);
                aux1 = aux1->next;
                i++;
                if(aux1->next == NULL)
                {
                    printf("Node %d: %d\n", i, aux1->n);
                }
            }
        }
    }
}

int main ()
{
    int i = 0; // to iteration
    int b = 0; // to adding new nodes

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
        Push(&head, b);

    }

    for(i = 0; i < 6; i++) // deleting all the list
    {
        Pop(&head);
    }

    return 0;
}