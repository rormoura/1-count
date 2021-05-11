#include <stdio.h>
#include <stdlib.h>

struct integer // nodes from the linked list
{
    int n;
    struct integer *next;
};
typedef struct integer Int;

void add (Int **head, int a) // function to add a new node to the list
{
    int i = 0;
    Int *aux = (Int *) malloc(sizeof(Int)); // to receive the integer
    Int *aux1 = (Int *) malloc(sizeof(Int)); // to iterate down the list

    if (aux == NULL || aux1 == NULL) // if there is a allocation error
    {
        printf("Allocation error :/");
        exit(-1);
    }

    aux->n = a; // filling in the node that will be added
    aux->next = NULL;

    if (*head == NULL) // checking if the list is empty
    {
        *head = aux; // adding the new node to the first position of the list
    }
    else
    {

        aux1 = *head; // iterating down the list
        while (aux1->next != NULL) // stops when reaches the last node
        {
            aux1 = aux1->next;
        }

        aux1->next = aux; // adding the new node to the list
    }    

    printf("New node added\n"); // success message 

    i = 0; // printing the new list
    aux1 = *head; 
    while (aux1->next != NULL) // stops when reaches the last node
    {

        printf("Integer %d: %d\n", i, aux1->n);
        aux1 = aux1->next;
        i++;
        if (aux1->next == NULL)
        {

            printf("Integer %d: %d\n", i, aux1->n);

        }

    }
    
}

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

int GetNth (Int *head, int index)
{
    int i = 0;

    Int *aux = (Int *) malloc(sizeof(Int)); // iterating down the list "index1" times
    if(aux == NULL)
    {
        printf("Allocation error :/\n");
        exit(-1);
    }
    aux = head;
    while(i <= index)
    {
        i++;
        aux = aux->next;
    }

    return aux->n; // returning the data
}

int main()
{
    int i = 0; // to iteration
    int b = 0; // to adding new nodes
    int index = 0, data = 0;

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
        add(&head, b);

    }

    int len = Length(head);

    printf("Input the index: "); // receiving the index
    scanf("%d", &index);
    while(index < 0 || index >= len) // if the index is out of range
    {
        printf("Input a valid index: ");
        scanf("%d", &index);
    }

    data = GetNth(head, index); // calling the function
    printf("Data: %d\n", data);
    
    return 0;
}