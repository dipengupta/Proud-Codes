/*
This is a program for dynamic implementation of queues. Coded by Dipen.
*/

#include<iostream>
#include<malloc.h>
using namespace std ;

struct node
{
    int data ;
    struct node *next ;
}*start=NULL, *newnode, *current ;


void traverse()
{
    cout<<"The Queue is : " ;
    struct node *p=start ;
    if (p==NULL)
        cout<<"Empty Queue!!"<<endl ;
    else
    {

        while (p!=NULL)
        {
            cout<<p->data<<"    " ;
            p=p->next ;
        }

    }
    cout<<endl ;
}


void create()
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


    traverse() ;
}


void kill()
{
    if (start==NULL)
        cout<<"UNDERFLOW!!!"<<endl ;
    else
    {
    cout<<start->data<<" has been deleted!"<<endl ;
    start=start->next ;
    }

    traverse() ;
}



int main()
{
    int o ;
    char ch ;
    do
    {
    cout<<"Press 1 to Push"<<endl ;
    cout<<"Press 2 to Pop"<<endl ;
    cout<<"Press 3 to Traverse"<<endl ;
    cin>>o ;
    switch(o)
        {
            case(1) : create() ; break ;
            case(2) : kill() ; break ;
            case(3) : traverse() ; break ;
            default : cout<<"SHDGKIUGSF!!!" ;
        }
    cout<<"Continue? Y/N : " ;
    cin>>ch ;
    }
    while (ch!='n') ;
    return 0 ;
}
