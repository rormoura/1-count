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

    i = 1; // printing the new list
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

void count (Int *head, int number)
{
    int counter = 0; // we need a counter, like, obviously
    Int *aux = (Int *) malloc(sizeof(Int)); // allocating the aux that we're gonna use to iterate down the list

    aux = head;

    while (aux->next != NULL) // iterating down the list to see how many times the given number occurs
    {
        if(aux->n == number)
        {
            counter++;
        }
        aux = aux->next;
        if(aux->next == NULL)
        {
            if(aux->n == number)
            {
            counter++;
            }
        }
    }

    printf("%d appears %d times in the list\n", number, counter);

    free(aux); // realising the used memory
}

int main()
{
    int i = 0; // to iteration
    int b = 0; // to adding new nodes
    int number = 0;

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

    printf("Input the number that u wanna know how many times occurs: ");
    scanf("%d", &number);

    count(head, number); // calling the count() function

    return 0;
}