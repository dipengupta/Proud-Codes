/*
This is a code which implements a few selected functions of circular link lists.
Coded by Dipen.
*/

#include<iostream>
#include<malloc.h>
using namespace std ;

struct node
{
    int data ;
    struct node *next ;
}*start=NULL, *current, *newnode;


void traverse() // has prob with one element.
{
    cout<<"The circular link list is : " ;
    struct node *p=start ;

    if (start==NULL)
        cout<<"Empty List!!"<<endl ;
    else
    {
        cout<<p->data<<"    " ;
        p=p->next ;
        while(p!=start)
        {
            cout<<p->data<<"    " ;
            p=p->next ;
        }
    }

    cout<<endl ;
}


void create()
{
    char ch ;
    do
    {

    newnode=(struct node*)malloc(sizeof(struct node)) ;
    cout<<"Enter data : " ;
    cin>>newnode->data ;
    newnode->next=start ;

    if (start==NULL)
    {
        start=newnode ;
        current=newnode ;
    }

    else
    {
        current->next=newnode ;
        current=current->next ;
    }

    cout<<"Make another? Y/N? : " ;
    cin>>ch ;
    cout<<endl ;
    }
    while(ch!='n') ;

    traverse() ;
}


void ins_first()
{
    newnode=(struct node*)malloc(sizeof(struct node)) ;
    cout<<"Enter data : " ;
    cin>>newnode->data ;

    struct node *p=start ;
    while (p->next!=start)
        p=p->next ;

    p->next=newnode ;
    newnode->next=start ;
    start=newnode ;

    traverse() ;
}

void ins_last()
{
    newnode=(struct node*)malloc(sizeof(struct node)) ;
    cout<<"Enter data : " ;
    cin>>newnode->data ;

    struct node *p=start ;
    while (p->next!=start)
        p=p->next ;

    p->next=newnode ;
    newnode->next=start ;

    traverse() ;
}


void del_first()
{
    cout<<start->data<<" has been deleted!"<<endl ;

    struct node *p=start ;
    while (p->next!=start)
        p=p->next ;

    start=start->next ;
    p->next->next=NULL ;
    p->next=start ;

    traverse() ;
}



void del_last()
{


    struct node *p=start,*p1 ;
    while (p->next!=start)
    {
        p1=p ;
        p=p->next ;
    }
    cout<<p->data<<" has been deleted!"<<endl ;

    p->next=NULL ;
    p1->next=start ;

    traverse() ;
}

int main()
{
    create() ;
    ins_first() ;
    ins_last() ;
    del_first() ;
    del_last() ;
    return 0 ;
}
