/*This is a comprehensive program for all the operations on a link list.
Coded by Dipen */

#include<iostream>
#include<malloc.h>
using namespace std ;

struct node
{
    int data ;
    node *next ;
}*start=NULL, *current, *newnode ;


void traverse ()
{
    cout<<"\nThe Link List is : "<<endl ;
    struct node *ptr ;
    ptr=start ;
    do
    {
        cout<<ptr->data<<"  " ;
        ptr=ptr->next ;
    }
    while (ptr!=NULL);
}


void in_first ()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    cout<<"\n\nEnter element to add at the first position : " ;
    cin>>newnode->data ;
    newnode->next=start ;
    start=newnode ;
}

void in_last ()
{
    newnode=(struct node*)malloc(sizeof(struct node)) ;
    cout<<"\nEnter element to add at the last position : " ;
    cin>>newnode->data ;
    /*
    struct node *ptr ;
    ptr=start ;
    while (ptr!=NULL)
        ptr=ptr->next ;
    */
    newnode->next=NULL ;
    current->next=newnode ;
    current=newnode ;
}


void in_before ()
{
    int x ;
    cout<<"\nEnter element before which new node is to be inserted : " ;
    cin>>x ;
    struct node *ptr1,*ptr2 ;
    ptr1=start ;
    ptr2=start ;

    while (ptr1->data!=x)
        ptr1=ptr1->next ;
    while (ptr2->next!=ptr1)
        ptr2=ptr2->next ;

   newnode=(struct node*)malloc(sizeof(struct node)) ;
   cout<<"Enter data of the new node : " ;
   cin>>newnode->data ;

   newnode->next=ptr1 ;
   ptr2->next=newnode ;
}


void in_after()
{
    int x ;
    cout<<"\nEnter element after which new node is to be inserted : " ;
    cin>>x ;
    struct node *ptr=start ;

    while (ptr->data!=x)
        ptr=ptr->next ;

   newnode=(struct node*)malloc(sizeof(struct node)) ;
   cout<<"Enter data of the new node : " ;
   cin>>newnode->data ;

   newnode->next=ptr->next ;
   ptr->next=newnode ;
}

void del_first ()
{
  cout<<"\nNow, first element is going to be deleted.."<<"\n" ;
  struct node *ptr ;
  ptr=start ;
  cout<<ptr->data<<" has been deleted"<<endl ;
  start=ptr->next ;
}


void del_last ()
{
  cout<<"\nNow, last element is going to be deleted.."<<"\n" ;
  struct node *ptr ;
  ptr=start ;
  while (ptr->next!=current)
  {
     ptr=ptr->next ;
  }
  cout<<current->data<<" has been deleted"<<endl ;
  ptr->next=NULL ;
  current=ptr ;
}


void del_ele()
{
    int x ;
    cout<<"\nEnter element which is to be deleted : " ;
    cin>>x ;

    struct node *ptr1,*ptr2 ;
    ptr1=start ;
    ptr2=start ;

    while (ptr1->data!=x)
        ptr1=ptr1->next ;
    while (ptr2->next!=ptr1)
        ptr2=ptr2->next ;

    ptr2->next=ptr1->next ;
    cout<<ptr1->data<<" has been deleted"<<endl ;
}


void del_after ()
{
    int x ;
    cout<<"\nEnter element after which node is to be deleted : " ;
    cin>>x ;
    struct node *ptr=start ;

    while (ptr->data!=x)
        ptr=ptr->next ;

    cout<<ptr->next->data<<" has been deleted"<<endl ;
    ptr->next = ptr->next->next ;
}


void del_before ()
{
  int x ;
  cout<<"Enter element before which node is to be deleted : " ;
  cin>>x ;

  struct node *ptr1=start, *ptr2=start ;
  do
  {
    ptr1=ptr1->next ;
  }
  while (ptr1->next->data!=x) ;

  while (ptr2->next!=ptr1)
    ptr2=ptr2->next ;

  cout<<ptr1->data<<" has been deleted!" ;
  ptr2=ptr1->next ;
}

int main ()
{
    char ch ;

    do
    {
        newnode=(struct node*)malloc(sizeof(struct node)) ;

        cout<<"Enter data : " ;
        cin>>newnode->data ;

        newnode->next=NULL ;

        if (start==NULL)
        {
            start=newnode ;
            current=newnode ;
        }

        else
        {
            current->next=newnode ;
            current=newnode ;
        }

        cout<<"Make a new node? Y/N : " ;
        cin>>ch ;
    }
    while (ch!='n') ;

        traverse () ;
    in_first () ;
        traverse () ;
        cout<<endl ;
    in_last () ;
        traverse () ;
        cout<<endl ;
    del_first () ;
        traverse () ;
        cout<<endl ;
    del_last () ;
        traverse () ;
        cout<<endl ;
    in_before() ;
        traverse () ;
        cout<<endl ;
    in_after() ;
        traverse () ;
        cout<<endl ;
    del_ele() ;
        traverse () ;
        cout<<endl ;
    del_after() ;
        traverse () ;
        cout<<endl<<endl ;
    del_before() ;
        traverse () ;
        cout<<endl ;



    return 0 ;
}
