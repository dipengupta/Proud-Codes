/*
This is the code to perform various functions in efficient
binary trees. Coded by Dipen.
*/

#include<iostream>
#include<malloc.h>

using namespace std ;

struct node
{
    int data ;
    struct node *left ;
    struct node *right ;
} *tree=NULL, *newnode, *nodeptr, *parentptr ;


void pre_order_traverse(struct node *tree)
{
    if (tree!=NULL)
    {
        cout<<tree->data<<" " ;
        pre_order_traverse(tree->left) ;
        pre_order_traverse(tree->right) ;
    }
}


void in_order_traverse(struct node *tree)
{
    if (tree!=NULL)
    {
        in_order_traverse(tree->left) ;
        cout<<tree->data<<" " ;
        in_order_traverse(tree->right) ;
    }
}


void post_order_traverse(struct node *tree)
{
    if (tree!=NULL)
    {
        post_order_traverse(tree->left) ;
        post_order_traverse(tree->right) ;
        cout<<tree->data<<" " ;
    }
}


void tree_insert()
{
    newnode=(struct node*)malloc(sizeof(struct node)) ;
    cout<<"Enter value : " ;
    cin>>newnode->data ;
    newnode->left=NULL ;
    newnode->right=NULL ;

    if (tree==NULL)
        tree=newnode ;
    else
    {
        parentptr=NULL ;
        nodeptr=tree ;

        while (nodeptr!=NULL)
        {
            parentptr=nodeptr ;
            if (newnode->data < nodeptr->data)
                nodeptr=nodeptr->left ;
            else
                nodeptr=nodeptr->right ;
        }

        if (newnode->data < parentptr->data)
            parentptr->left = newnode ;
        else
            parentptr->right = newnode ;
    }

}


void kill_zero(struct node *ptr, struct node *ptr1) // assuming ptr1 (parent to the node-to-be-killed) has 2 children
{                                                   // this code works properly
    if (ptr1->left==ptr)
        ptr1->left=NULL ;

    if (ptr1->right=ptr)
        ptr1->right=NULL ;
}

void kill_one(struct node *ptr, struct node *ptr1)
{
    struct node *p ;
    p=ptr->left==NULL? ptr->right : ptr->left ; // p points to node-to-be-killed's child.
                                                // this part works properly
    if (ptr1->left==ptr)
        ptr1->left=p ;
    else
        ptr1->right=p ;

    ptr->left=NULL ;
    ptr->right=NULL ;
}


void kill_two(struct node *ptr) //not complete......
{
    struct node *temp1,*temp2 ; //temp2 will be the parent of temp1 (temp 1 is highest ele)
    temp1=ptr->left ;   // i need to find the largest value in left sub-tree.
    temp2=ptr ;

    while (temp1->right!=NULL)
    {
        temp2=temp1 ;
        temp1=temp1->right ;
    }

    ptr->data=temp1->data ;

    if (temp1->left==NULL && temp1->right==NULL)    // temp1 is leaf node
        kill_zero(temp1, temp2) ;

    else
        kill_one(temp1, temp2) ;

}


void tree_delete()
{
    struct node *ptr=tree, *ptr1=NULL ;  //ptr1 is pre-ptr
    int x ;

    if (ptr==NULL)
        cout<<"Empty Tree!!"<<endl ;
    else
    {
        cout<<"Enter element to delete : " ;
        cin>>x ;

        while (ptr->data!=x)
        {
            if (x<ptr->data)
            {
                ptr1=ptr ;
                ptr=ptr->left ;
                if (ptr==NULL)
                    break ;
            }

            if (x>ptr->data)
            {
                ptr1=ptr ;
                ptr=ptr->right ;
                if (ptr==NULL)
                    break ;
            }

        }

        // now ptr should point to the desired node (to be killed)

        if (ptr==NULL)
            cout<<"Element not found!!"<<endl ;
        else
        {
            cout<<ptr->data<<" has been deleted!"<<endl ;

            if (ptr->left==NULL && ptr->right==NULL) // leaf node
                kill_zero(ptr,ptr1) ;
            else
                if (ptr->left!=NULL && ptr->right!=NULL) // two children
                    kill_two(ptr) ;
                else
                    kill_one(ptr,ptr1) ;  // one child
        }

    }
}



int height (struct node *tree)
{
    int left_height, right_height ;
    if (tree==NULL)
        return 0 ;
    else
    {
        left_height=height(tree->left) ;
        right_height=height(tree->right) ;

        if (left_height > right_height)
            return left_height+1 ;
        else
            return right_height+1 ;
    }
}


int total_nodes(struct node *tree)
{
    if (tree==NULL)
        return 0 ;
    else
        return(total_nodes(tree->left) + total_nodes(tree->right) + 1) ;
}


int smallest_ele(struct node *tree)
{
    if (tree==NULL || tree->left==NULL)
        return tree->data ;
    else
        return smallest_ele(tree->left) ;
}


int largest_ele(struct node *tree)
{
    if (tree==NULL || tree->right==NULL)
        return tree->data ;
    else
        return largest_ele(tree->right) ;
}


int main ()
{
    int opt ;
    char ch ;
    do
    {
        cout<<"Press 1 to insert element in tree"<<endl ;
        cout<<"Press 2 for pre-order traversal of tree"<<endl ;
        cout<<"Press 3 for in-order traversal of tree"<<endl ;
        cout<<"Press 4 for post-order traversal of tree"<<endl ;
        cout<<"Press 5 to find height of tree"<<endl ;
        cout<<"Press 6 to find total number of nodes of tree"<<endl ;
        cout<<"Press 7 to find smallest element of tree"<<endl ;
        cout<<"Press 8 to find largest element of tree"<<endl ;
        cout<<"Press 9 to delete an element"<<endl ;

    cin>>opt ;
    switch (opt)
    {
        case (1) : tree_insert() ; break ;
        case (2) : pre_order_traverse(tree) ; break ;
        case (3) : in_order_traverse(tree) ; break ;
        case (4) : post_order_traverse(tree) ; break ;
        case (5) : cout<<"Height is : "<<height(tree)<<endl ; break ;
        case (6) : cout<<"Total nodes are : "<<total_nodes(tree)<<endl ; break ;
        case (7) : cout<<"Smallest element is : "<<smallest_ele(tree)<<endl ; break ;
        case (8) : cout<<"Largest element is : "<<largest_ele(tree)<<endl ; break ;
        case (9) : tree_delete() ; break ;
        default : cout<<"Enter valid input!!!"<<endl ;
    }

    cout<<endl<<"Want to continue? Y/N : " ;
    cin>>ch ;
    cout<<endl ;

    }
    while (ch!='n') ;

    return 0 ;
}
