/*
This is the complete implementation for a linear, static queue.
Coded by Dipen.
*/
#include<iostream>
using namespace std ;

#define SIZE 3
int queue[SIZE] ;
int rear=-1, front=-1 ;


void traverse ()
{
    cout<<"The queue is : " ;
    int x ;
    if (front==-1 || front>rear)
        cout<<"Empty Queue!"<<endl ;
    else
    {
        for (x=front; x<=rear; x++)
            cout<<queue[x]<<"   " ;
    }
}


int insert ()
{
    int x ;

    if (rear==SIZE-1)
        {
            cout<<"Overflow!!!"<<endl ;
            return -1 ;
        }
    else
        if (front==-1 && rear==-1)
            front=rear=0 ;
        else
            rear++ ;

    cout<<"Enter element : " ;
    cin>>x ;
    queue[rear]=x ;

    traverse() ;
    return 0 ;
}


void kill ()
{
    if (front==-1)
        cout<<"Underflow!!"<<endl ;
    else
       {
        cout<<queue[front]<<" has been deleted!!"<<endl ;
        front++ ;

        if (front>rear)
            front=rear=-1 ;
       }

    traverse() ;
}



int main ()
{
    int opt ;
    char ch ;
    do
    {
        cout<<"Press 1 to insert element"<<endl ;
        cout<<"Press 2 to delete element"<<endl ;
        cout<<"Press 3 to traverse queue"<<endl ;

    cin>>opt ;
    switch (opt)
    {
        case (1) : insert() ; break ;
        case (2) : kill() ; break ;
        case (3) : traverse() ; break ;
        default : cout<<"Enter valid input!!!"<<endl ;
    }

    cout<<endl<<"Want to continue? Y/N : " ;
    cin>>ch ;

    }
    while (ch!='n') ;

    return 0 ;
}
