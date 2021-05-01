#include <stdio.h>
#include <stdlib.h>

struct integer // nodes from the linked list
{
    int n;
    struct integer *next;
};
typedef struct integer Int;

struct list // linked list
{
    Int *first;
    Int *last;
};
typedef struct list List;

void add(List list1, int a) // function to add a new node to the list
{

    Int *aux = (Int *) malloc(sizeof(Int)); // to receive the integer
    Int *aux1 = (Int *) malloc(sizeof(Int)); // to iterate down the list

    if (aux == NULL || aux1 == NULL) // if there is a allocation error
    {
        printf("Allocation error :/");
        exit(-1);
    }

    aux->n = a; // filling in the node that will be added
    aux->next = NULL;

    if (list1.first == NULL) // checking if the list is empty
    {

        list1.first = aux; // adding the new node to the first position of the list

    }
    else
    {

        aux1 = list1.first; // iterating down the list
        while (aux1->next != NULL)
        {
            aux1 = aux1->next;
        }

        aux1->next = aux; // adding the new node to the list
        list1.last = aux;

    }    

    printf("New node added\n"); // success message 

    i = 1;
    aux1 = list1.first; // printing the new list
    while (aux1->next != NULL)
    {

        printf("Integer %d: %d\n", i, aux1->n);
        aux1 = aux1->next;
        i++;
        if (aux1->next ++NULL)
        {

            printf("Integer %d: %d\n", i, aux1->n);

        }

    }

    free(aux); // realising the used memory
    free(aux1); 
}

int main()
{
    int i = 0; // to iteration
    int b = 0; // to adding new nodes

    List list1; // creating the linked list we're gonna use
    list1.first = NULL;
    list1.last = NULL;

    for (i = 0; i < 6; i++) // for loop to add the five nodes of the list
    {

        printf("Input the integer: ");
        scanf("%d", &b);
        add(list1, b);

    }
}