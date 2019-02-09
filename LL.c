/*
  Author: Alex Shershnov
  Purpose: Implement a linked list in C. Gain better understanding
  of memory manipulation.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

//Adding to the front of the list
void addFront(struct Node **top, int data)
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = *top;
  *top = newNode;
}

//Print list
void printList(struct Node *node)
{
  printf("Printing a list: ");
  while(node != NULL)
    {
      printf("%d ", node -> data);
      node = node -> next;
    }
  printf("\n");
}

//Adding to the back of the list
void addBack(struct Node **top, int data)
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = NULL;
  if(*top == NULL)
    addFront(top, data);
  else
    {
      struct Node *tmp_node = *top;
      while(tmp_node -> next != NULL)
	  tmp_node = tmp_node -> next;
      tmp_node -> next = newNode;
    }
}

//Reversing the list
void reverseList(struct Node **top)
{
  printf("Reversing a list..\n");
  struct Node *curr = *top;
  struct Node *next = curr -> next;
  struct Node *prev = NULL;
  while(curr != NULL)
    {
      next = curr -> next;
      curr -> next = prev;
      prev = curr;
      curr = next;
    }
  *top = prev;
  
}

//Inserting after Kth element
void insertAfterKthElem(struct Node **top, int k, int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = NULL;  
  struct Node *tmp_node = *top;
  while(tmp_node != NULL)
    {
      if(tmp_node -> data == k)
	{
	  newNode -> next = tmp_node -> next;
	  tmp_node -> next = newNode;
	  return;
	}
      tmp_node = tmp_node -> next;
    }
}

//Inserting a node before Kth element
void insertBeforeKthElem(struct Node **top, int k, int data)
{
  struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode -> data = data;
  newNode -> next = NULL;
  struct Node *curr = *top;
  struct Node *prev = NULL;
  if(curr -> next == NULL)//If the list is empty
    {
      newNode -> next = curr;
      *top = newNode;
    }
  else if(curr -> data == k)//If k is 1st elem, new element is top
    {
      newNode -> next = curr;
      *top = newNode;
    }
  else
    {
      while(curr != NULL)//Otherwise linearly search the list
	{
	  if(curr -> data == k)
	    {
	      prev -> next = newNode;
	      newNode -> next = curr;
	      return;
	    }
	  prev = curr;
	  curr = curr -> next;
	}
    }
}

//Delete a particular node
void deleteNode(struct Node **top, int k)
{
  struct Node *curr = *top;
  struct Node *prev = NULL;
  if(curr -> next == NULL)//If there is only one element in the list
    {
      free(curr);
      *top = NULL;
      return;
    }
  else if(curr -> data == k)//If the element to be removed is head
    {
      *top = curr -> next;
      free(curr);
      return;
    }
  while(curr != NULL)//Otherwise check the list
    {
      if(curr -> data == k)
	{
	  prev -> next = curr -> next;
	  free(curr);
	  return;
	}
      prev = curr;
      curr = curr -> next;
    }
}
int main()
{
  struct Node *head = NULL;  
  int arr[] = {1,2,3,4,5,6,7,8,9,10};//Just a test array
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++)
    addBack(&head, arr[i]);
  printList(head);
  reverseList(&head);
  printList(head);
  return 0;
}
