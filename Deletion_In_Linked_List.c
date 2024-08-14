//  CASE : 
//         [1]  Deletion The First Node
//         [2]  Deleting a node in between
//         [3]  Delete a last node given
//         [4]  Delete a node with a given key/value



#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void LinkedListTraversal(struct node * ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d\n", ptr->data);
        ptr = ptr->next;
    }
    
}


//  Case 1  : Delete The First Elemet From The Linked List

struct node * DeleteFirstElemet(struct node *head)
{
    struct node *ptr = head;
    head = head -> next;
    free(ptr);              // free means delete pointer
    return head;
};


//  Case 2 : Deleteing Node In between

struct node * DeleteAtIndex(struct node * head , int index)
{
    struct node *p = head;
    struct node *q = head -> next;

    for (int i = 0; i < index - 1; i++)
    {
       p = p-> next;
       q = q-> next;
    }

    p -> next = q -> next;
    free(q);
    return head;
    
}



// Case 3 : Delete The Last Node

struct node * DeleteLastNode(struct node * head)
{
    struct node *p = head;
    struct node *q = head->next;

    while (q -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }
    
     p -> next = NULL;
     free(q);
     return head;
}


//   Case 4 :  Delete a node with a given key/value
struct node  * DeleteAtLast(struct node * head , int value)
{
    struct node * p = head;
    struct node * q = head->next;

    while (q -> data != value && q -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }

    if (q -> data == value)
    {
        p -> next = q -> next;
        free(q);
    }

    return head;
    
    

}



int main()
{
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;


    // Allocate memory for the nodes 

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));


    //  link first node to the second

    head ->  data = 2;
    head ->next = second;

    // Link second node to third

    second -> data = 4;
    second -> next = third;

    // Link Third node to fourth

    third -> data = 6;
    third -> next = fourth;

    // terminate here linked list

    fourth -> data = 8;
    fourth -> next = NULL;


    printf(" Linked List Before deletion \n");
    LinkedListTraversal(head);


    // head = DeleteFirstElemet(head);
    // head = DeleteAtIndex(head , 1);
    // head = DeleteLastNode(head);
    head = DeleteAtLast(head ,2);
    printf("Linked List After Deletion\n");
    LinkedListTraversal(head);


    return 0;

}