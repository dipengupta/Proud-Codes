/*

This is a classic and a very simple version of towers of Hanoi.
This was made solely for Turbo C IDE as a project in Computer Graphics.
It took me about 6-9 hours to create, and it incorporates <graphics.h> methods
with dynamic stacks and a universal matrix.

The user needs to move the blocks from rod 1 and get them to rod 3 in the same order.
The game terminates when such a formation is detected.

Reach rod represnts a dynamic stack, which in turn updates the global matrix, which 
in turn displays the appropriate bar on the screen.

This was a nice weeknd project, nothing great I know, but I enjoyed doing it.

Coded by Dipen.

*/


#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<alloc.h>

//----------------------------------------------------------

void update_scene(int a1, int a2, int a3, int b1, int b2, int b3, int c1, int c2, int c3);

int mat[3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};


struct node_A
{
	int data ;
	struct node_A *next ;
}*top_A=NULL,*newnode_A;


struct node_B
{
	int data ;
	struct node_B *next ;
}*top_B=NULL,*newnode_B;


struct node_C
{
	int data ;
	struct node_C *next ;
}*top_C=NULL,*newnode_C;




void push_A(int x)
{
	newnode_A = (struct node_A*)malloc(sizeof(struct node_A)) ;

	newnode_A->data = x ;

	if (top_A==NULL)
	{
		top_A = newnode_A ;
		top_A->next = NULL ;
	}

	else
	{
		newnode_A->next = top_A ;
		top_A = newnode_A ;
	}

}


void push_B(int x)
{
	newnode_B = (struct node_B*)malloc(sizeof(struct node_B)) ;

	newnode_B->data = x ;

	if (top_B==NULL)
	{
		top_B = newnode_B ;
		top_B->next = NULL ;
	}

	else
	{
		newnode_B->next = top_B ;
		top_B = newnode_B ;
	}

}


void push_C(int x)
{
	newnode_C = (struct node_C*)malloc(sizeof(struct node_C)) ;

	newnode_C->data = x ;

	if (top_C==NULL)
	{
		top_C = newnode_C ;
		top_C->next = NULL ;
	}

	else
	{
		newnode_C->next = top_C ;
		top_C = newnode_C ;
	}

}




void traverse_A()
{
	if (top_A==NULL)
	{
		mat[0][0] = 0 ;
		mat[1][0] = 0 ;
		mat[2][0] = 0 ;
	}

	else
	{
		int ctr = 0 ;
		struct node_A *ptr1=top_A,*ptr=top_A ;
		while (ptr!=NULL)
		{
			ctr++ ;
			ptr=ptr->next ;
		}

		for(int p=0; p<3-ctr; p++)
			mat[p][0] = 0 ;

		for (int p1=3-ctr; p1<3; p1++)
		{
			mat[p1][0] = ptr1->data ;
			ptr1 = ptr1->next ;
		}
	}

}



void traverse_B()
{
	if (top_B==NULL)
	{
		mat[0][1] = 0 ;
		mat[1][1] = 0 ;
		mat[2][1] = 0 ;
	}

	else
	{
		int ctr = 0 ;
		struct node_B *ptr1=top_B,*ptr=top_B ;
		while (ptr!=NULL)
		{
			ctr++;
			ptr=ptr->next ;
		}

		for(int p=0; p<3-ctr; p++)
			mat[p][1] = 0 ;

		for (int p1=3-ctr; p1<3; p1++)
		{
			mat[p1][1] = ptr1->data ;
			ptr1 = ptr1->next ;
		}
	}
}



void traverse_C()
{
	if (top_C==NULL)
	{
		mat[0][2] = 0 ;
		mat[1][2] = 0 ;
		mat[2][2] = 0 ;
	}

	else
	{
		int ctr = 0 ;
		struct node_C *ptr1=top_C,*ptr=top_C ;
		while (ptr!=NULL)
		{
			ctr++ ;
			ptr=ptr->next ;
		}

		for(int p=0; p<3-ctr; p++)
			mat[p][2] = 0 ;

		for (int p1=3-ctr; p1<3; p1++)
		{
			mat[p1][2] = ptr1->data ;
			ptr1 = ptr1->next ;
		}
	}
}


void traverse()
{
	traverse_A() ;
	traverse_B() ;
	traverse_C() ;
}




void pop (int x, int y)
{

	if (x==1)
	{
		if (y==2)
			push_B(top_A->data) ;
		if (y==3)
			push_C(top_A->data) ;
		top_A=top_A->next ;
	}

	if (x==2)
	{
		if (y==1)
			push_A(top_B->data) ;
		if (y==3)
			push_C(top_B->data) ;
		top_B=top_B->next ;
	}

	if (x==3)
	{
		if (y==1)
			push_A(top_C->data) ;
		if (y==2)
			push_B(top_C->data) ;
		top_C=top_C->next ;
	}

}




//-----------------------------------------------------------



float sign(float p1, float p2)
{
	if (p2==p1)
	return(0) ;

	if (p2-p1 < 0)
	return (-1) ;
	else
	return (1) ;
}


void bres(float x, float y, float x1, float y1)
{
	float dx,dy,e,sign_x,sign_y ;
	int exchange = 0 ;

	dx = abs(x1-x) ;
	dy = abs(y1-y) ;

	sign_x = sign(x,x1) ;
	sign_y = sign(y,y1) ;

	if (dy > dx)
	{
		float temp ;
		temp = dx ;
		dx = dy ;
		dy = temp ;
		exchange = 1 ;
	}

	e = (2*dy)-dx ;
	putpixel(x,y,RED) ;

	for(int q=0; q<dx; q++)
	{
		while(e>0)
		{
			if (exchange==1)
				x+=sign_x ;
			else
				y+=sign_y ;

			e-=(2*dx) ;
		}

		if(exchange==1)
			y+=sign_y ;
		else
			x+=sign_x ;

		e+=(2*dy) ;
		putpixel(x,y,RED) ;
	}

}



//-----------------------------------------------------------



void build_base()
{
	setbkcolor(7);
	//rectangle(0,0,600,350);
	bres(0,0,600,0) ;
	bres(600,0,600,350) ;
	bres(600,350,0,350) ;
	bres(0,350,0,0) ;

	//bar3d(150,80,170,350, 15, 1) ;
	bres(150,50,150,350);

	//bar3d(300,80,320,350, 15, 1) ;
	bres(300,50,300,350);

	//bar3d(435,80,455,350, 15, 1) ;
	bres(450,50,450,350);

	//rectangle(0,375,600,400) ;
	bres(0,375,600,375) ;
	bres(600,375,600,450) ;
	bres(600,450,0,450) ;
	bres(0,450,0,375) ;
}


void build_starting_scene()
{

	push_A(3) ;
	push_A(2) ;
	push_A(1) ;

	traverse() ;

	update_scene(mat[0][0],mat[1][0],mat[2][0],mat[0][1],mat[1][1],mat[2][1],mat[0][2],mat[1][2],mat[2][2]);

}



void update_scene(int a1, int a2, int a3, int b1, int b2, int b3, int c1, int c2, int c3)
{
	clrscr() ;
	build_base() ;
	outtextxy(270,5,"Towers of hanoi");

	switch(a1)
	{
		case (0) : 	break ;
		case (1) :	bar3d(145,115,155,155, 15, 1) ;	break ;
		case (2) :	bar3d(130,115,170,155, 15, 1) ;	break ;
		case (3) :	bar3d(110,115,190,155, 15, 1) ;	break ;
		//default :	{	}
	}


	switch(a2)
	{
		case (0) : 	break ;
		case (1) :	bar3d(145,195,155,235, 15, 1) ;	break ;
		case (2) :	bar3d(130,195,170,235, 15, 1) ;	break ;
		case (3) :	bar3d(110,195,190,235, 15, 1) ;	break ;
		//default :	{	}
	}


	switch(a3)
	{
		case (0) : 	break ;
		case (1) :	bar3d(145,275,155,315, 15, 1) ;	break ;
		case (2) :	bar3d(130,275,170,315, 15, 1) ;	break ;
		case (3) :	bar3d(110,275,190,315, 15, 1) ;	break ;
	       //	default :	{	}
	}


	switch(b1)
	{
		case (0) : 	break ;
		case (1) :	bar3d(295,115,305,155, 15, 1) ;	break ;
		case (2) :	bar3d(280,115,320,155, 15, 1) ;	break ;
		case (3) :	bar3d(260,115,340,155, 15, 1) ;	break ;
		//default :	{	}
	}


	switch(b2)
	{
		case (0) : 	break ;
		case (1) :	bar3d(295,195,305,235, 15, 1) ;	break ;
		case (2) :	bar3d(280,195,320,235, 15, 1) ;	break ;
		case (3) :	bar3d(260,195,340,235, 15, 1) ;	break ;
	       //	default :	{	}
	}


	switch(b3)
	{
		case (0) : 	break ;
		case (1) :	bar3d(295,275,305,315, 15, 1) ;	break ;
		case (2) :	bar3d(280,275,320,315, 15, 1) ;	break ;
		case (3) :	bar3d(260,275,340,315, 15, 1) ;	break ;
	       //	default :	{	}
	}


	switch(c1)
	{
		case (0) : 	break ;
		case (1) :	bar3d(445,115,455,155, 15, 1) ;	break ;
		case (2) :	bar3d(430,115,470,155, 15, 1) ;	break ;
		case (3) :	bar3d(410,115,490,155, 15, 1) ;	break ;
		//default :	{	}
	}


	switch(c2)
	{
		case (0) : 	break ;
		case (1) :	bar3d(445,195,455,235, 15, 1) ;	break ;
		case (2) :	bar3d(430,195,470,235, 15, 1) ;	break ;
		case (3) :	bar3d(410,195,490,235, 15, 1) ;	break ;
	       //	default :	{	}
	}


	switch(c3)
	{
		case (0) : 	break ;
		case (1) :	bar3d(445,275,455,315, 15, 1) ;	break ;
		case (2) :	bar3d(430,275,470,315, 15, 1) ;	break ;
		case (3) :	bar3d(410,275,490,315, 15, 1) ;	break ;
	       //	default :	{	}
	}

}




void move()
{
	int from, to ;
	outtextxy(5,400,"From : ");
	cin>>from ;
	outtextxy(5,420,"To : ");
	cin>>to ;


	pop(from,to) ;
	traverse() ;

	update_scene(mat[0][0],mat[1][0],mat[2][0],mat[0][1],mat[1][1],mat[2][1],mat[0][2],mat[1][2],mat[2][2]);
}



//-----------------------------------------------------------

void main()
{
	clrscr() ;
	int gd=DETECT, gm ;
	initgraph(&gd, &gm,"C:\\TC\\BGI");

	build_starting_scene() ;
	int steps = 0 ;

	while(1)
	{
		move() ;
		steps++ ;
		if(mat[0][2]==1 && mat[1][2]==2 && mat[2][2]==3)
		{
			clrscr() ;
			cout<<"You Won!"<<endl ;
			cout<<"You took "<<steps<<" steps!" ;
			break ;
		}
	}

	getche() ;
	closegraph() ;
}