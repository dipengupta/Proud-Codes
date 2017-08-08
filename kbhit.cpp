/* This code is my first code that gets close to a game. You have to press
the keyboard as fast as you can. I used the "kbhit()" function.
Inspired by Roshan, Coded by Dipen */
#include<iostream.h>
#include<conio.h>
void main ()
{
int x ;
char y,p ;
do
{
 clrscr () ;
 x=1 ;
 while (!kbhit())
  {
	cout<<x<<"\n" ;
	x++ ;
  }
 if (kbhit())
 cout<<"You took "<<x<<" computer unit time!"<<"\n" ;

 cout<<"Do you want to continue? Y/N"<<"\n" ;
 p=getch() ;
 y=getch() ;
}
while(y=='y') ;
cout<<"Thanks for using this. Made by Dipen :D" ;
}                                                   //Code Close
