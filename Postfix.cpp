/*

This is code for dynamic implementation for infix to postfix expression.
It uses a link list and three stacks, all dynamic. LL is to store the expression.
Stack 1 is the operator stack, and  stack 2 is the output stack. Stack 3 is to
reverse the order of stack 2 (purely for display purposes).

Had fun doing this.

Coded by Dipen.

*/

#include<iostream>
#include<malloc.h>
using namespace std ;


int priority(char x, char y)
{
    if (y=='(')
        return 0 ;
    if ( x==y || (x=='*' && y=='/') || (x=='+' && y=='-') )
        return 1 ;      // 1 means pop operator
    if ( (x=='^' && (y=='/' || y=='*')) || (x=='^' && (y=='+' || y=='-')) || ((x=='*' || x=='/') && (y=='+' || y=='-')) )
        return 1 ;
    else
        return 0 ;      // 0 means add operator to stack 1
}

// LL start


struct node
{
    char data ;
    node *next ;
}*start=NULL, *current, *newnode ;


void ll_traverse ()
{
    cout<<"\nThe Expression is : "<<endl ;
    struct node *ptr ;
    ptr=start ;
    do
    {
        cout<<ptr->data ;
        ptr=ptr->next ;
    }
    while (ptr!=NULL);
    cout<<endl ;
}


void ll_insert()
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
}


void ll_in_first ()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data='(' ;
    newnode->next=start ;
    start=newnode ;
}



void ll_in_last ()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=')' ;

    struct node *po=start ;
    while (po->next!=NULL)
        po=po->next ;

    po->next=newnode ;
    newnode->next=NULL ;
}



// LL end


// Stack 2 (output) start


struct op_stack_node
{
    char data ;
    op_stack_node *next ;
}*op_node_top=NULL, *op_stack_newnode ;


/*
// just for reference

void op_stack_traverse()
{
    op_stack_node *p=op_node_top ;

    if (p==NULL)
        cout<<"Empty Stack!!!" ;
    else
    {
        while(p!=NULL)
        {
            cout<<p->data ;
            p=p->next ;
        }
    }

    cout<<endl ;
}


*/

void op_push(char x)
{
    op_stack_newnode=(struct op_stack_node*)malloc(sizeof(struct op_stack_node)) ;
    op_stack_newnode->data = x ;

    if (op_node_top==NULL)
    {
        op_node_top=op_stack_newnode ;
        op_stack_newnode->next=NULL ;
    }

    else
    {
        op_stack_newnode->next=op_node_top ;
        op_node_top = op_stack_newnode ;
    }
}



// Stack 2 end


// Stack 1 start

struct stack_node
{
    char data ;
    stack_node *next ;
}*node_top=NULL, *stack_newnode ;



void stack_traverse()
{
    stack_node *ptr=node_top ;
    while(ptr!=NULL)
    {
        cout<<ptr->data ;
        ptr=ptr->next ;
    }

    cout<<endl ;
}



void push(char x)
{
    stack_newnode=(struct stack_node*)malloc(sizeof(struct stack_node)) ;
    stack_newnode->data=x ;

    if (node_top==NULL)
    {
        node_top=stack_newnode ;
        stack_newnode->next=NULL ;
    }

    else
    {
        if (x==')')   // pop everything till '(' to output stack
        {
            while (node_top->data!='(')
            {
                op_push(node_top->data) ;
                node_top=node_top->next ;
            }
            node_top=node_top->next ;
        }

        else
        {
                if (priority(node_top->data,x)==1)
                {
                    op_push(node_top->data) ;
                    node_top->data=x ;
                }

                else
                {
                    stack_newnode->next = node_top ;
                    node_top=stack_newnode ;
                }
        }


    }
}



// Stack 1 end




// display_stack start


struct dp_stack_node
{
    char data ;
    dp_stack_node *next ;
}*dp_node_top=NULL, *dp_stack_newnode ;



void dp_stack_traverse()
{
    dp_stack_node *p1=dp_node_top ;
    while(p1!=NULL)
    {
        cout<<p1->data ;
        p1=p1->next ;
    }

    cout<<endl ;
}


void dp_push(char x)
{
    dp_stack_newnode=(struct dp_stack_node*)malloc(sizeof(struct dp_stack_node)) ;
    dp_stack_newnode->data = x ;

    if (dp_node_top==NULL)
    {
        dp_node_top=dp_stack_newnode ;
        dp_stack_newnode->next=NULL ;
    }

    else
    {
        dp_stack_newnode->next=dp_node_top ;
        dp_node_top = dp_stack_newnode ;
    }
}



// display_stack end



void transfer()
{
    while (op_node_top!=NULL)
    {
        dp_push(op_node_top->data) ;
        op_node_top=op_node_top->next ;
    }
}


int main()
{
    ll_insert() ;
    ll_in_first() ;
    ll_in_last() ;
    ll_traverse() ;

    while (start!=NULL)
    {
        if (start->data=='^' || start->data=='*' || start->data=='/' || start->data=='+' || start->data=='-' || start->data=='(' || start->data==')' )
            push(start->data) ; // push to stack 1
        else
            op_push(start->data) ; // push to output stack

        start=start->next ;
    }

    stack_traverse() ;

    transfer() ;

    cout<<endl ;
    cout<<"Postfix Expression is : " ;
    dp_stack_traverse() ;

    return 0 ;
}
