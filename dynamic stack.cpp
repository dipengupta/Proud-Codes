#include<iostream>
#include<malloc.h>

using namespace std ;
int flag=0 ;

struct node
{
    int data ;
    node *next ;
}*start=NULL, *newnode, *current;


void push ()             // insert first of link list!
{
   int x ;
   flag=0 ;

   newnode=(struct node*)malloc(sizeof(struct node)) ;
   cout<<"Enter data : " ;
   cin>>newnode->data ;

   if (start==NULL)
   {
       start=newnode ;
       current=newnode ;
       start->next=NULL ;
   }

   else
   {
       start=newnode ;
       newnode->next=current ;
       current=start ;
   }

}


void pop ()              //delete first of link list!!
{
    struct node *p=start ;

    if (start->next=NULL)
        flag=1 ;

    if (flag==1)
    {
        cout<<"Underflow!!"<<endl ;
    }

    else
    {
      cout<<p->data<<" has been deleted!!"<<endl ;
      p=p->next ;
      start=p ;
    }

}



void traverse()
{
    cout<<"The stack (opening from left) is : "<<endl ;
    struct node *ptr ;
    ptr=start ;
    do
    {
        cout<<ptr->data<<"  " ;
        ptr=ptr->next ;
    }
    while (ptr!=NULL) ;
    cout<<endl ;
}


int main()
{
    push() ;
    push() ;
    traverse() ;
    pop() ;
    traverse() ;
    return 0 ;
}
