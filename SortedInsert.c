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

int Walk (Int *head, int index) // Walk() basically returns the integer that is inside the node of the given index
{ // if we were using an array, Walk() returns the same as array[index]
    int i = 0;
    Int *aux = (Int *) malloc(sizeof(Int));
    if(aux == NULL)
    {
        printf("Allocation error :/\n");
        exit(-1);
    }
    aux = head;

    for(i = 0; i < index-1; i++)
    {
        aux = aux->next;
    }

    return aux->n;
}

void Swap (Int **head, int i, int j) // Swap() swaps two nodes @_@ (it actually swaps the data inside them)
{
    int k = 0; // the variable that we're gonna use to iterate down the list ('i-1' times and 'j-1' times)
    int aux2 = 0; // the variable we're gonna to swap the data
    Int *aux = (Int *) malloc(sizeof(Int));
    Int *aux1 = (Int *) malloc(sizeof(Int));
    if(aux == NULL || aux1 == NULL)
    {
        printf("Allocation error :/\n");
        exit(-1);
    }
    aux = *head;
    aux1 = *head;
    
    for(k = 0; k < i-1; k++) // iterating down the list 'i-1' times
    {
        aux = aux->next;
    }
    for(k = 0; k < j-1; k++) // iterating down the list 'j-1' times
    {
        aux1 = aux1->next;
    }
    
    aux2 = aux->n; // swapping the data
    aux->n = aux1->n;
    aux1->n = aux2;

    aux = NULL; // deallocating the memory we used
    aux1 = NULL;
    free(aux);
    free(aux1);
}

int partition (Int *head, int left, int right) // Lomuto's partition
{
    int pivot = Walk(head, left);
    int i = left, j = 0;

    for(j = left + 1; j <= right; j++)
    {
        if(Walk(head, j) <= pivot)
        {
            i++;
            Swap(&head, i, j);
        }
    }

    Swap(&head, left, i);

    return i;
}

void QuickSort (Int *head, int left, int right) // quicksort @_@
{
    if(left < right)
    {
        int index_pivot = partition(head, left, right);
        QuickSort(head, left, index_pivot - 1);
        QuickSort(head, index_pivot + 1, right);
    }
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

void SortedInsert (Int **head, Int *newnode)
{
    int i = 0;
    Int *aux = (Int *) malloc(sizeof(Int));
    Int *aux1 = (Int *) malloc(sizeof(Int));
    if(aux == NULL || aux1 == NULL)
    {
        printf("Allocation error :/\n");
        exit(-1);
    }

    aux = *head;
    while(aux->n <= newnode->n) // we're gonna insert newnode into aux1 and aux
    {
        aux1 = aux;
        aux = aux->next;
    }

    newnode->next = aux; // inserting the newnode
    aux1->next = newnode;

    aux = *head; // printing the new list
    printf("\t\tNew list:\n");
    while(aux->next != NULL)
    {
        printf("Node %d: %d\n", i, aux->n);
        aux = aux->next;
        i++;
        if(aux->next == NULL)
        {
            printf("Node %d: %d\n", i, aux->n);
        }
    }

    aux = NULL; // deallocating the memory we used
    aux1 = NULL;
    free(aux);
    free(aux1);
}

int main ()
{
    int i = 0; // to iteration
    int b = 0; // to adding new nodes

    Int *head = (Int *) malloc(sizeof(Int)); // creating the linked list head we're gonna use
    Int newnode = {7}; // the new node we're gonna insert

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

    QuickSort(head, 0, Length(head)); // sorting the LINKED LIST, it isn't a ARRAY, is a linked list

    SortedInsert(&head, &newnode);

    return 0;
}
