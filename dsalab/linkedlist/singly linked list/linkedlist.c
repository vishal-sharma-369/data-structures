#include<stdio.h>
#include<stdlib.h>

// Creating the node structure
struct Node 
{
    int data;
    struct Node* next;
};

// Defining the global head node
struct Node*head = NULL;
struct Node*head2 = NULL;

// Defining the global last node
struct Node*last = NULL;

// Creation of singly linked list
void createLinkedList(int arr[] , int n , struct Node**head)
{
    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->data = arr[0];

    last = *head;

    for(int i = 1;i<n;i++)
    {
        struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        last->next = temp;
        last = temp;
    }

    last->next = NULL;
}

// Displaying a linked list
void displaySinglyLinkedList(struct Node*head)
{
    while(head != NULL)
    {
        printf("%d " , head->data);
        head = head->next;
    }

    printf("\n");
    return;
}

// counting the number of nodes in linked list 
int countNodesInLinkedList(struct Node*head)
{
    int nodes = 0;
    while(head != NULL)
    {
        nodes ++;
        head = head->next;
    }
    return nodes;
}

// Printing the linked list in reverse order using recursion
void reversePrint(struct Node*head)
{
    if(head == NULL)
    {
        return;
    }
    else 
    {
        reversePrint(head->next);
        printf("%d " , head->data);
    }
}

// Reversing the linked list 
void reverseLinkedList(struct Node**head)
{
    struct Node*prev = NULL;
    struct Node*curr = *head;
    while(curr!=NULL)
    {
        struct Node*next= curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}


// Inserting a nodes at first place in linked list 
void insertAtBeginning(struct Node**head ,int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

// Inserting at the end in a linked list 
void insertAtEnd(struct Node*head , int data)
{
    struct Node*ptr = head;
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
}


void insertInBetween(struct Node*head , int val, int data)
{
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    struct Node*ptr = head;

    while(ptr->data != val)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}


// Deletion from a linked list 

// Deleting first node from the linked list
void deleteFromBeginning(struct Node**head)
{
    struct Node* ptr = *head;
    *head = (*head)->next;
    free(ptr);
}


// Deleting the last node from the linked list 
void deleteFromEnd(struct Node*head)
{
    struct Node*ptr = head;
    struct Node*prev = NULL;
    while(ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;
    last = prev;
    free(ptr);
}


// Deleting in between the linked list 
void deleteInBetween(struct Node*head , int val)
{
    struct Node*ptr = head;
    struct Node*prev = NULL;
    while(ptr->data != val)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = ptr->next;
    free(ptr);
}

// Merging two linked lists
struct Node* mergeLinkedLists(struct Node*head1 , struct Node*head2)
{
    struct Node*head3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node*last = head3;

    if(head1->data < head2->data)
    {
        head3->data = head1->data;
        head1 = head1->next;
    }
    else 
    {
        head3->data = head2->data;
        head2 = head2->next;
    }

    while(head1 && head2)
    {
        struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
        if(head1->data < head2->data)
        {
            
        temp->data = head1->data;
        head1 = head1->next;
        last->next = temp;
        last = temp;
        }
        else 
        {
            temp->data = head2->data;
            head2 = head2->next;
            last->next = temp;
            last = temp;
        }
    }

    while(head1)
    {
        struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = head1->data;
        head1 = head1->next;
        last->next = temp;
        last = temp;
    }
    while(head2)
    {
        struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = head2->data;
        head2 = head2->next;
        last->next = temp;
        last = temp;
    }
    last->next = NULL;
    return head3;
}


// Concatenating two linked lists 
void concatenateLinkedLists(struct Node*head1 , struct Node*head2)
{
    struct Node*ptr = head1;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = head2;
}




int main()
{
    int arr[] = {1,2,3,4,5,6,8,9,10};

    createLinkedList(arr , 9 , &head);
    printf("Printing the linked list\n");
    displaySinglyLinkedList(head);

    int count = countNodesInLinkedList(head);
    printf("Number of nodes in linked List is %d \n" , count);

    printf("Reverse printing the linked list \n");
    reversePrint(head);
    printf("\n");


    insertAtBeginning(&head , 0);
    
        printf(" printing the linked list after inserting 0 at beginning \n");
    displaySinglyLinkedList(head);

    insertAtEnd(head , 11);
        printf(" printing the linked list after inserting 11 at the end \n");
    displaySinglyLinkedList(head);


    insertInBetween(head , 6 , 7);
    printf("printing the linked list after inserting 7 after 6\n");
    displaySinglyLinkedList(head);

    
    deleteFromBeginning(&head);
    printf("printing after deleting first node from linked list\n");
    displaySinglyLinkedList(head);


    deleteFromEnd(head);
    printf("Printing after deleting last node from linked list\n");
    displaySinglyLinkedList(head);


    deleteInBetween(head , 7);
    printf("Printing after deleting node with value 7 from linked list\n");
    displaySinglyLinkedList(head);



    reverseLinkedList(&head);
    printf("Printing after reversing the linked list\n");
    displaySinglyLinkedList(head);


    reverseLinkedList(&head);
    int arr2[] = {11,12,13,14,15,16,17,18,19};
    createLinkedList(arr2 , 9 , &head2);
    struct Node*head3 = mergeLinkedLists(head , head2);
    printf("Printing the merged Linked list \n");
    displaySinglyLinkedList(head3);

    concatenateLinkedLists(head , head2);
    printf("Printing the concatenated linked list \n");
    displaySinglyLinkedList(head);

    
    return 0;
}