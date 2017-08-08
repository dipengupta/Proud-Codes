/*

This is the code for Breadth First Traversal in graphs.
Done using an adjacency matrix. Coded by Dipen.

*/
#include<iostream>
using namespace std ;

#define MAX 4

void bfs(int adj_m[][MAX], int visited[], int start)
{
    int qu[MAX], r=-1, f=-1, x ;
    qu[++r]=start ;
    visited[start]=1 ;
    while(r!=f)
    {
        start=qu[++f] ;
        cout<<char(start+65) ;

        for (x=0; x<MAX; x++)
        {
            if(adj_m[start][x]==1 && visited[x]==0)
            {
                qu[++r]=x ;
                visited[x]=1 ;
            }
        }
    }
}


int main()
{
    int visited[MAX]={0} ;
    int adj_m[MAX][MAX],x,y ;

    cout<<"Enter adjacency matrix : "<<endl ;
    for (x=0; x<MAX; x++)
        for(y=0; y<MAX; y++)
            cin>>adj_m[x][y] ;

    cout<<endl ;

    bfs(adj_m, visited, 0) ;

    return 0 ;
}
