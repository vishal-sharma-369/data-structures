#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

struct Node 
{
    int data;
    struct Node* next;
}*first;

void createLinkedList(int arr[] , int n , struct Node**head)
{
    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->data = arr[0];

    struct Node*last = *head;
    for(int i = 1;i<n;i++)
    {
        struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = arr[i];
        last->next= temp;
        last = temp;
    }

    last->next = NULL;
}


void displayLinkedList(struct Node*head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}


void displayLinkedListRecursively(struct Node*head)
{
    if(head == NULL)
    {
        return;
    }
    else 
    {
        printf("%d ",head->data);
        displayLinkedListRecursively(head->next);
    }
}

void reverseDisplayLinkedListRecursively(struct Node*head)
{
    if(head == NULL)
    {
        return;
    }
    else
    {
        reverseDisplayLinkedListRecursively(head->next);
        printf("%d " , head->data);
    }
}


int countNumberOfNodesInLinkedList(struct Node*head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}


int countNumberOfNodesInLinkedListRecursively(struct Node*head)
{
    if(head == NULL)
    {
        return 0;
    }
    else 
    {
        return countNumberOfNodesInLinkedListRecursively(head->next) + 1;
    }
}


int sumOfNodesInLinkedList(struct Node*head)
{
    int sum = 0;
    while(head!=NULL)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int sumOfNodesInLinkedListRecursively(struct Node*head)
{
    if(head == NULL)
    {
        return 0;
    }
    else 
    {
        return sumOfNodesInLinkedListRecursively(head->next) + head->data;
    }
}


int maximumElementInLinkedList(struct Node*head)
{
    int maxi = INT_MIN;
    while(head)
    {
        maxi = fmax(maxi , head->data);
        head = head->next;
    }
    return maxi;
}

int minimumElementInLinkedList(struct Node*head)
{
    int mini = INT_MAX;
    while(head)
    {
        mini = fmin(mini , head->data);
        head = head->next;
    }
    return mini;
}

int maximumElementInLinkedListRecursively(struct Node*head)
{
    if(head == NULL)
    {
        return INT_MIN;
    }

    else 
    {
        return fmax(maximumElementInLinkedListRecursively(head->next) , head->data);
    }
}

struct Node* linearSearchInALinkedList(struct Node*head , int val , struct Node**originalHead)
{
    struct Node*prev = NULL;
    while(head)
    {
        if(head -> data == val)
        {
            if(prev != NULL)
            {
                prev->next = head->next;
                head->next = *originalHead;
                *originalHead = head;
            }
            return head;
        }
        prev = head;
        head = head->next;
    }

    return NULL;
}

struct Node* linearSearchInALinkedListRecursively(struct Node*head , int val)
{
    if(head == NULL)
    {
        return NULL;
    }
    else 
    {
        if(head -> data == val)
        {
            return head;
        }
        else 
        {
            return linearSearchInALinkedListRecursively(head->next , val);
        }
    }
}


void insertInALinkedListAtBeginning(struct Node**head , int data)
{
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void insertAtEnd(struct Node**head , int data)
{
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    struct Node*ptr = *head;
    if(ptr ==  NULL)
    {
        *head = temp;
        return;
    }
    while(ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next= temp;
}

void insertInBetweenLinkedList(struct Node**head , int val,int data)
{
    if(head == NULL)
    {
        *head = (struct Node*)malloc(sizeof(struct Node));
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }

    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    
    struct Node*ptr = *head;
    struct Node*prev = NULL;
    while(ptr)
    {
        if(ptr->data == val)
        {
            temp->next = ptr->next;
            ptr->next = temp;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        prev->next = temp;
    }
}


void insertInALinkedListAtGivenIndex(struct Node**head , int index  , int data)
{
    if(index < 0 || index > countNumberOfNodesInLinkedList(*head))
    {
        printf("Enter a valid index\n");
        return;
    }

    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if(index == 0)
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    
    struct Node*ptr = *head;
    for(int i = 0;i<index-1;i++)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    return;
}


void insertingInSortedLinkedList(struct Node**head , int data)
{
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if(*head == NULL)
    {
        *head = temp;
    }

    struct Node*ptr = *head;
    struct Node*prev = NULL;

    while(ptr)
    {
        if(ptr->data >= data)
        {
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if(prev == NULL)
    {
        temp->next = *head;
        *head = temp;
    }
    else 
    {
        temp->next= prev->next;
        prev->next = temp;
    }
    return;
}

void deleteFirstNodeFromLinkedList(struct Node**head)
{
    if(*head == NULL)
    {
        return;
    }

    struct Node*ptr = *head;
    *head = (*head)->next;
    free(ptr);
}

void deleteLastNodeFromLinkedList(struct Node**head)
{
    if(*head == NULL)
    {
        return;
    }

    struct Node*ptr = *head;
    struct Node*prev = NULL;
    while(ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if(prev == NULL)
    {
        *head = NULL;
        free(ptr);
    }
    else 
    {
        prev->next = NULL;
        free(ptr);
    }
    return;
}


void deleteANodeWithGivenValue(struct Node**head , int val)
{
    if(*head == NULL)
    {
        return;
    }

    struct Node*ptr = *head;
    struct Node*prev = NULL;
    while(ptr && ptr->data != val)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if(prev == NULL)
    {
        *head = (*head)->next;
        free(ptr);
        return;
    }
    else if(ptr == NULL)
    {
        return;
    }
    else 
    {
        prev->next = ptr->next;
        ptr->next = NULL; // Not necessary
        free(ptr);
        return;
    }
}

void deletingANodeAtGivenIndex(struct Node**head , int index)
{
    if(index < 0 || index >= countNumberOfNodesInLinkedList(*head))
    {
        printf("Enter a valid index to delete\n");
        return;
    }
    else 
    {
        struct Node*ptr = *head;
        struct Node*prev = NULL;
        for(int i = 0;i<index;i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        if(prev == NULL)
        {
            *head = ptr->next;
            ptr->next = NULL;
            free(ptr);
            return;
        }
        else 
        {
            prev->next = ptr->next;
            ptr->next = NULL;
            free(ptr);
            return;
        }
    }
}

int isLinkedListSorted(struct Node*head)
{
    if(head == NULL)
    {
        return 1;
    }
    else 
    {
        int curr = head->data;
        head = head->next;
        while(head)
        {
            if(head->data < curr)
            {
                return 0;
            }
            curr = head->data;
            head = head->next;
        }
        return 1;
    }
}


void removeDuplicatesFromSortedLinkedList(struct Node*head)
{
    if(head == NULL)
    {
        return;
    }
    else 
    {
        struct Node*prev = head;
        struct Node*ptr = (head)->next;
        while(ptr)
        {
            if(ptr->data == prev->data)
            {
                prev->next = ptr->next;
                free(ptr);
                ptr = prev->next;
            }
            else 
            {
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
}


// Write a program for reversing a linked list
void reverseLinkedListUsingArray(struct Node**head)
{
    
}


int main()
{
    struct Node*head = NULL;
    int n = 0;
    printf("Enter the number of nodes in the linked list\n");
    scanf("%d" , &n);

    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the linked list\n");
    for(int i = 0;i<n;i++)
    {
        scanf("%d" , &arr[i]);
    }

    createLinkedList(arr , n , &head);

    printf("Printing the elements of the linked list\n");
    displayLinkedList(head);

    return 0;
}