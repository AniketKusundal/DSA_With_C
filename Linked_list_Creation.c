//  Creating And Traversal  Of Linked List

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


void LinkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element  Is\n  %d" , ptr->data);
        ptr = ptr->next;
    }
    
}

int main()
{

    struct node  *head;
    struct node *second;
    struct node *third;


    //  Allocate a memorry for nodes in the linked list in the heap

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));


    //  link first and second node

    head ->data=8;
    head -> next=second;

    // Link second and third node

    second ->data=10;
    second->next=third;

    // terminate the link list 

    third->data=20;
    third->next=NULL;


    LinkedListTraversal(head);
    return 0;

}