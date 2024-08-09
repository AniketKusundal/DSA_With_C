
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};


void LinkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element Is :%d\n" , ptr->data);
        ptr = ptr->next;
    }
    
}


//  Case 1 : Insertion At The Begining 

struct node * InsertAtFirst (struct node *head , int data)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data=data;
    ptr->next=head;
    return ptr;
}


// Case 2 : Insert In B/w

struct node * InsertAtIndex(struct node *head, int data , int index)
{
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;              // Here we can declare oor rquest to heap to iinitalize the p new pointer or element
    int  i = 0;

    while (i != index -1)
    {
        p = p -> next;
        i++;
    }

    ptr ->data = data;
    ptr ->next = p -> next;
    p->next=ptr;
    return head;
    
}



// Case 3 : Insert At The End

struct node * InsertAtEnd(struct node *head , int data)
{
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    ptr -> data = data;
    struct node *p = head;
    

    while (p->next != NULL)
    {
        p = p ->next;
        p->next=ptr;
        ptr->next=NULL;;
        return head;
    
    }
}



struct node *InsertAfterNode(struct node *head , struct node *previousNode , int data)
{
    struct node *ptr =(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next = previousNode->next;
    previousNode->next=ptr;
    return head;
}


int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate memory for nodes in the linked list in the heap
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // Link first and second node
    head->data = 8;
    head->next = second;

    // Link second and third node
    second->data = 10;
    second->next = third;

    // Link third to fourth
    third->data = 20;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 30;
    fourth->next = NULL;

    printf("Linked list before Insertion\n");
    LinkedListTraversal(head);

    // Insert at the beginning
    printf("\nLinked list after insertion at the beginning\n");
    head = InsertAtFirst(head, 99);
    LinkedListTraversal(head);

    // Insert at the end
    printf("\nLinked list after insertion at the end\n");
    head = InsertAtEnd(head, 50);
    LinkedListTraversal(head);

    return 0;
}
