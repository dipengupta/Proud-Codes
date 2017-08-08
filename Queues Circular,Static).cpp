/*
This is the complete implementation for a circular, static queue.
Coded by Dipen.
*/
#include<iostream>
using namespace std ;

#define SIZE 5
int queue[SIZE] ;
int rear=-1, front=-1 ;


void traverse ()
{
    cout<<"The queue is : " ;
    int x ;
    if (front==-1 && rear==-1)
        cout<<"Empty Queue!"<<endl ;
    else
    {
        if (front<=rear)
            for (x=front; x<=rear; x++)
                cout<<queue[x]<<"   " ;
        else
            {
            for (x=front; x<SIZE; x++)
                cout<<queue[x]<<"   " ;

            for (x=0; x<=rear; x++)
                cout<<queue[x]<<"   " ;
            }
    }
}


int insert ()
{
    int x ;

    if (front==0 && rear==SIZE-1)
        {
            cout<<"Overflow!!!"<<endl ;
            return -1 ;
        }
    else
        if(front==-1 && rear==-1)
            {
                front=0 ;
                rear=0 ;
                cout<<"Enter element : " ;
                cin>>x ;
                queue[rear]=x ;
            }
        else
            if (rear==SIZE-1 && front!=0)
            {
                rear=0 ;
                cout<<"Enter element : " ;
                cin>>x ;
                queue[rear]=x ;
            }

            else
            {
                rear++ ;
                cout<<"Enter element : " ;
                cin>>x ;
                queue[rear]=x ;
            }

    traverse() ;
    return 0 ;
}


void kill ()
{
    if (front==-1 && rear==-1)
        cout<<"Underflow!!"<<endl ;
    else
       {
        cout<<queue[front]<<" has been deleted!!"<<endl ;

        if (front==rear)
            front=rear=-1 ;
        else
        {
            if (front==
                SIZE-1)
                front=0 ;
            else
                front++ ;
        }

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
