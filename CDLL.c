#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*prv;
    struct node*next;
};
struct node*head=NULL;

struct node*getnode();
void create(int n);
void display();
void insert_begin();
void insert_end();
void delete_begin();
void delete_end();
void insert_p();
void delete_p();


int main()
{
    int ch,n;
    do{
    printf("\nEnter choice\n1.Create\n2.Display\n3.Insert at beginning\n4.Insert at end\n5.Delete at beginning\n6.Delete at end\n7.Insert at given position\n8.Delete at given position\n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1:
              printf("\nEnter no of nodes:");
              scanf("%d",&n);
              create(n);
              break;       
        case 2:
              display();
              break;        
        case 3:
              insert_begin();
              display();
              break;
        case 4:
              insert_end();
              display();
              break;        
        case 5:
              delete_begin();
              display();
              break;        
        case 6:
              delete_end();
              display();
              break;        
        case 7:
              insert_p();
              display();
              break;
        case 8:
              delete_p();
              display();
              break;
      }
    }while(ch);
  return 0;
}

struct node*getnode()
{
    struct node*new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&new->data);
    new->prv=NULL;
    new->next=NULL;
    return new;
}

void create(int n)
{
  int i;
  struct node *new;
  struct node *temp;
  for(i = 0; i < n; i++)
  {
    new= getnode();
    if(head== NULL)
    {
      head= new;
      new->prv=head;
      new->next=head;
    }
    else
    {
      new->prv = head ->prv;
      new->next=head;
      head->prv->next= new;
      head->prv = new;
    }
  }
}

void display()
{
    struct node*temp;
    temp=head;
    do
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    while(temp != head);
}

void insert_begin()
{
  struct node *new;
  new = getnode();
  if(head == NULL)
  {
    head = new;
    new->prv=head;
    new->next=head;
  }
  else
  {
    new->prv = head ->prv;
    new -> next= head;
    head->prv->next=new;
    head ->prv = new;
    head = new;
  }
}


void insert_end()
{
  struct node*new,*temp;
  new=getnode();
  if(head==NULL)
  {
    head=new;
    new->prv=head;
    new->next=head;
  }
  else
  {
    new->prv =head->prv;
    new->next=head;
    head->prv->next= new;
    head->prv= new;
  }
}

void delete_begin()
{
  struct node*temp;
  if(head==NULL)
    printf("EMPTY");
  else
  {
    temp = head;
    head= head-> next;
    temp->prv-> next=head;
    head->prv= temp->prv;
    free(temp);
  }
}

void delete_end()
{
  struct node*temp;
  if(head==NULL)
    printf("EMPTY");
  else
  {
    temp =head;
    while(temp->next!=head)
    temp = temp ->next;
    temp -> prv->next= temp ->next;
    temp ->next-> prv= temp ->prv;
    free(temp);
    temp=NULL;
  }
}

void insert_p()  
{  
  struct node *ptr = (struct node *)malloc(sizeof(struct node));  
  struct node *temp,*new;   
  int i, loc;  
  new=getnode();
  if(ptr == NULL)  
  {  
    printf("\n OVERFLOW");  
  }  
  else  
  {  
    printf("\nEnter the location\n");  
    scanf("%d",&loc);  
    temp=head;  
    for(i=0;i<loc-2;i++)  
    {  
      temp = temp->next;  
      if(temp == NULL)  
      {  
        printf("\ncan't insert\n");  
        return;  
      }  
    }  
    ptr=new; 
    ptr->next = temp->next;  
    ptr -> prv = temp;  
    temp->next = ptr;  
    temp->next->prv=ptr;  
    printf("Node Inserted\n");  
  }  
}  


void delete_p( )  
{  
  struct node *temp;
  int i,p;
  printf("position:");
  scanf("%d",&p);
  temp = head;
  for(i=0; i<p-1; i++)
  {
    temp = temp->next;
  }
  if(temp != NULL)
  {
    temp->prv->next = temp->next;  
    temp->next->prv = temp->prv;   
    free(temp); 
  }
  else  
  {
    printf("Invalid position!\n");
  }
}






