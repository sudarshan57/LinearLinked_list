//SUDARSHAN PANDEY
//Linear Linked List All Function
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//Linked List Declaration Info and Next(address)
typedef struct nodetype
{ int info;
struct nodetype *next;
}node;
//Function Prototype
void CreateEmptyList(node **head);
void TraverseInOrder(node *head);
void InsertAtBegining(node **head,int item);
void TraverseInRevOrder(node *head);
void InsertAtEnd(node **head,int item);
void InsertSpecific(node *head,int item,int after);
void *Search_UnsortedList(node *head,int item);
void DeleteFromBeginning(node **head);
void DeleteFromEnd(node **head);
void DeleteAfterElement(node *head,int after);
void *Search_SortedList(node *head,int item);
void main()
{ node *head;
  int choice,element,after;
  clrscr();
  CreateEmptyList(&head);
  while(1)
  {printf("\n Operation Available Are \n");
   printf("\n Press 1 for Inserting at Begining");
   printf("\n Press 2 for Traverse In Order");
   printf("\n Press 3 for Traverse Reverse In Order");
   printf("\n Press 4 for Insert At Last");
   printf("\n Press 5 for Insert At Specific Node");
   printf("\n Press 6 for Search In Unsorted List");
   printf("\n Press 7 for Delete from Beginning");
   printf("\n Press 8 for Delete from end");
   printf("\n Press 9 for Delete Specific");
   printf("\n Press 10 for Search In Sorted List");
   printf("\n Enter Your Choice");
   scanf("%d",&choice);
   switch(choice)
   { case 1: printf("\n Enter element");
	     scanf("\n %d",&element);
	     InsertAtBegining(&head,element);
	     break;
     case 2: if(head==NULL)
	     printf("\n List is Empty");
	     else
	     TraverseInOrder(head);
	     break;
     case 3: if(head==NULL)
	     printf("\n List is Empty");
	     else
	     TraverseInRevOrder(head);
	     printf("\n Press Any Key to continue");
	     break;
     case 4: printf("\n Enter Element");
	     scanf("\n %d",&element);
	     InsertAtEnd(&head,element);
	     break;
     case 5: printf("\n Enter the element and node after which the new element will be inserted");
	     scanf("\n %d %d",&element,&after);
	     InsertSpecific(head,element,after);
	     break;
     case 6: printf("\n Enter Item to search");
	     scanf("%d \n,&element");
	     Search_UnsortedList(head,element);
	     break;
     case 7: DeleteFromBeginning(&head);
	     break;
     case 8: DeleteFromEnd(&head);
	     break;
     case 9: printf("\n Enter element and after which element is to delete");
	     scanf(" \n %d",&element,&after);
	     DeleteAfterElement(head,after);
	     break;
     case 10:printf("\n Enter the item to search");
	     scanf("\n %d",&element);
	     Search_SortedList(head,element);
	     printf("\n Press any key to continue");
	     getch();
	     break;
    default: exit(0);
    }
  }
 }
//Function body starts
void CreateEmptyList(node **head)
{ *head=NULL;
}
void InsertAtBegining(node **head,int item)
{ node *ptr;
  ptr=(node *)malloc(sizeof(node));
  ptr->info=item;
  if(*head==NULL)
  ptr->next=NULL;
  else
  ptr->next=*head;
  *head=ptr;
}
void TraverseInOrder(node *head)
{ while(head!=NULL)
  {printf("\n %d",head->info);
    head=head->next;
    }
  }
void TraverseInRevOrder(node *head)
{if(head->next!=NULL)
   TraverseInRevOrder(head->next);
   {printf("\n %d",head->info);
}   }
void InsertAtEnd(node **head,int item)
{ node *ptr;
  ptr=(node *)malloc(sizeof(node));
  ptr->info=item;
  ptr->next=NULL;
  if(*head==NULL)
  {*head=ptr;
  }
  else
 { ptr=*head;
  while(ptr->next!=NULL)
  ptr=ptr->next;
  ptr->next=(node *)malloc(sizeof(node));
    ptr=ptr->next;
    ptr->info=item;
    }
    printf("\n item inserted %d",item);
    }
 void *Search_UnsortedList(node *head,int item)
 {
   while((head!=NULL) &&(head->info!=item))
   head=head->next;
   return head;
 }
void *Search_SortedList(node *head,int item)
{ while(head!=NULL)
   {  if(head->info==item)
	return head;
      else if(item<head->info)
      return NULL;
      else
      head=head->next;
    }
    return NULL;
  }
void InsertSpecific(node *head,int item,int after)
{ node *ptr,*loc;
  loc=Search_UnsortedList(head,after);
  if(loc==(node *)NULL)
     return;
  ptr=(node *)malloc(sizeof(node));
  ptr->info=item;
  ptr->next=loc->next;
  loc->next=ptr;
printf("\n Element Inserted Successfully %d",item);
}
void DeleteFromBeginning(node **head){
node *ptr;
if(*head==NULL)
return;
else{
ptr=*head;
*head=(*head)->next;
free(ptr);
}
void DeleteFromEnd(node **head)
{
node *ptr, *loc;
  if(*head==NULL)
    return head;
    elseif((*head)->next==(node*) NULL){
      ptr=*head;
      *head=NULL;
      free(ptr);
      }
      else{
      loc=*head;
      ptr=(*head)->next;
      while(ptr->next!=NULL){
      loc=ptr;
      ptr=ptr->next;
      }
      loc->next=NULL;
      free(ptr);
      }
      }
   void DeleteAfterElement(node *head,int after)
   {  node *ptr,*loc;
      loc=Search_UnsortedList(head,after);
      if(loc==(node *)NULL)
      return;
      ptr=loc->next;
      loc->next=ptr->next;
      free(ptr);
}      }