// to create a Linked list of n numbers
// print the Linked List
// insert a new Node 
// delete a node

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int number;
    struct Node *next;
};

struct Node *head; // keeps the address of the first node

void print_linked()
  {
      struct Node *traverse;
      traverse = head;
      while(traverse!=NULL)
      {
        printf(" %d ->",traverse->number);
        traverse = traverse -> next;
      }
      printf(" NULL ");
  }

void insert(int nth,int m)
  {
    struct Node *traverse = head;
    for(int i = 0; i < nth - 1; i++)
      {
        traverse = traverse -> next;
      }
        
    struct Node *Temp = (struct Node*)malloc(sizeof(struct Node));
    Temp->number = m;
    Temp->next   = traverse -> next;
    traverse -> next = Temp;

  }

  void delete(int kth)
  {
      struct Node *traverse = head;
      for(int i = 0;i < kth - 1;i++)
        {
            traverse = traverse -> next;
        }
       struct Node *copy = traverse; 
       traverse   = traverse -> next;
       copy->next = traverse -> next;
       free(traverse);
  
  }

int main()
  {
      int length;scanf("%d",&length);
      head = NULL;
      struct Node* temp_add ;
      
      for(int i = 0; i <= length ; i++)
        {
           struct Node *Temp =(struct Node*)malloc(sizeof(struct Node));
           Temp->number = i;
           Temp->next   = NULL;
           if(head == NULL)
             {
               head = Temp;
             }
           else{
               temp_add -> next = Temp; // previous node -> next = current node
             }
            temp_add = Temp;// temp_add stores the address of previous node

        }
        insert(10,5);
        delete(3);
        print_linked();
 
  }