/* This is version 1.1.0 This version sees the inculsion of numbers.
This required relatively less time to make. Completed/Coded on 19.12.2013
(Took us about 1 week). Coded by Ankur and Dipen */


/* This is our font_project. This required collaboration over dropbox.
This inputs a string and converts it into the 'Star' font. We made use of
modular programming and this is by FAR the biggest code we have ever made.
Completed on 5.12.2013 (Took us about 1 month)
Coded by Dipen and Ankur */
#include<iostream>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

using namespace std ;

/* This is the code for "A". This time, I REALLY am on fire!!!!.
Coded by Dipen */
void letter_a ()
{
int n,x,y,z,p,a,b ;
n=5 ;
p=n-1 ;

for (x=1; x<=n; x++)              // For loop for upper triangle
 {
  for (y=1; y<=p; y++)
  cout<<" " ;

  p-- ;

  for (z=1; z<=2*x-1; z++)
    {
     if (z==1 || z==2*x-1)
     cout<<"*" ;

     else
     cout<<" " ;
    }
  cout<<"\n" ;
 }



for (a=1; a<=n+1; a++)            // For loop for lower part
 {
  for (b=1; b<=2*n-1; b++)
    {
     if (a==2)
      {
        if (b%2==0)
        cout<<" " ;

        else
        cout<<"*" ;
      }
     else
      {
        if (b==1 || b==2*n-1)
        cout<<"*" ;

        else
        cout<<" " ;
      }
    }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;

}                                 // Code Close





/* This is the code to print the letter "B". I'm on fire!!!
Coded by Dipen */
void letter_b ()
{
int n,x,y;
n=11 ;                                  // Makes sense for n>5
for (x=1; x<=n; x++)                      // Use only odd n values
 {
  for (y=1; y<=n-2; y++)
    {
     if (x>1 && x!=(n/2)+1 & x<n)
      {
        if (y==1 || y==n-2)
        cout<<"*" ;

        else
        cout<<" " ;
      }

     else
      {
        if (y==n-2)
        cout<<" " ;

        else
        cout<<"*" ;
      }
    }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}




void letter_c ()
{

 int i,j,n;
 n=9 ;
 for(i=0;i<1;i++)
  {
    for(j=0;j<n;j++)
     cout<<"*";
  }
    cout<<endl;
  for(i=0;i<n-1;i++)
  {
      cout<<"*";
      cout<<endl;
     }
 for(i=0;i<1;i++)
  {
    for(j=0;j<n;j++)
     cout<<"*";
  }

cout<<"\n" ;
cout<<"\n" ;
}





void letter_d ()
{
 int i,j,n,p;
 n=5 ;
    p=1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p+2;
  }
  p=2*n-1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p-2;
  }

cout<<"\n" ;
cout<<"\n" ;
}




/* This is the code for the letter "E". Coded by Dipen */
void letter_e ()
{
int n,x,y,p ;
n=9 ;
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n; y++)
    {
     if (x==1 || x==n)
     cout<<"*" ;

     else
     {
      if (y==1)
      cout<<"*" ;

      else
        {
         if ( x==(n/2)+1 )
          {
            if (y<n-1)
            cout<<"*" ;
          }
        }
     }
    }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}





/* This is the code for the letter "F". Coded by Dipen */
void letter_f ()
{
int n,x,y,p ;
n=9 ;
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n; y++)
    {
     if (x==1)
     cout<<"*" ;

     else
     {
      if (y==1)
      cout<<"*" ;

      else
        {
         if ( x==(n/2)+1 )
          {
            if (y<n-1)
            cout<<"*" ;
          }
        }
     }
    }


  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}




void letter_g ()
{
 int i,j,n;
 n=8 ;
 for(i=0;i<1;i++)
  {
    for(j=0;j<n;j++)
     cout<<"*";
  }
    cout<<endl;
  for(i=0;i<=n-1;i++)
  {
      cout<<"*";
      if(i==n-2)
      {
        for(j=1;j<=n-4;j++)
         cout<<" ";
        for(j=n-2;j<=n;j++)
         cout<<"*";
        }
        if(i==n-1)
        {
         for(j=1;j<=n-2;j++)
          cout<<" ";
         for(j=n-1;j<n;j++)
          cout<<"*";
        }
      cout<<endl;
     }
 for(i=0;i<1;i++)
  {
    for(j=0;j<n;j++)
     cout<<"*";
  }

cout<<"\n" ;
cout<<"\n" ;
}




/* This is the code to print the letter "H". Coded by Dipen */
void letter_h ()
{
int n,x,y ;
n=10 ;                             // Makes sense when n>3


if (n%2==1)                          // For odd n values
{                                    // If start
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n; y++)
    {
     if (x==(n/2)+1)
     {
      if (y%2==0)
      cout<<" " ;

      else
      cout<<"*" ;
     }

     else
      {
        if (y==1 || y==n)
        cout<<"*" ;

        else
        cout<<" " ;
      }
    }
  cout<<"\n" ;
 }
}                                    // If close

else                                 // For even n values
{                                    // Else Start
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n; y++)
    {
     if (x==(n/2)+1)
     cout<<"*" ;

     else
      {
        if (y==1 || y==n)
        cout<<"*" ;

        else
        cout<<" " ;
      }
    }
  cout<<"\n" ;
 }
}                                    // Else close

cout<<"\n" ;
cout<<"\n" ;
}                                    // Code close





void letter_i ()
{
 int i,j,n;
 n=9 ;
 for(i=0;i<1;i++)
  {
    for(j=0;j<n;j++)
     cout<<"*";
  }
    cout<<endl;
  for(i=0;i<n-1;i++)
    {
     for(j=0;j<(n/2);j++)
      cout<<" ";
      cout<<"*";
      cout<<endl;
     }
 for(i=0;i<1;i++)
  {
    for(j=0;j<n;j++)
     cout<<"*";
  }

cout<<"\n" ;
cout<<"\n" ;
}




void letter_j ()
{
 int i,j,n;
 n=9 ;
 for(i=0;i<1;i++)
  {
    for(j=0;j<n;j++)
     cout<<"*";
  }
    cout<<endl;
  for(i=0;i<n-1;i++)
    {
     for(j=0;j<(n/2);j++)
      cout<<" ";
      cout<<"*";
      cout<<endl;
     }
 for(i=0;i<1;i++)
  {
    for(j=0;j<n/2;j++)
     cout<<"*";
  }

cout<<"\n" ;
cout<<"\n" ;
}




void letter_k ()
{
 int i,j,n,p;
 n=5;
 p=2*n-1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p-2;
  }
  p=1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p+2;
  }

cout<<"\n" ;
cout<<"\n" ;
}




void letter_l ()
{
 int i,n,j ;
 n=9;
 for(i=0;i<n;i++)
  {
    cout<<"*";
    cout<<endl;
    }
    if(i==n)
     for(i=0;i<1;i++)
      {
        for(j=0;j<n;j++)
         cout<<"*";
      }

cout<<"\n" ;
cout<<"\n" ;
}





/* This is the code for the letter 'M'. It is the third last code!!!!
Coded by Dipen */
void letter_m ()
{
int n,x,y ;
n=9 ;                               // Use odd n values
for (x=1; x<=n; x++)                   // Makes sense after n=5
 {
  for (y=1; y<=n; y++)
    {
     if (x==1)                          // Top line
      {
        if (y%2!=1)
        cout<<" " ;

        else
        cout<<"*" ;
      }
                                                    // Mid section
     if (x>1 && x<=(n/2)+1)
      {
        if (y==(n/2)+1 || y==1 || y==n)
        cout<<"*" ;

        else
        cout<<" " ;
      }

     else if (x!=1)                     // Remaining part
      {
        if (y==1 || y==n)
        cout<<"*" ;

        else
        cout<<" " ;
      }

    }
  cout<<"\n" ;
 }                                     // For loop close

cout<<"\n" ;
cout<<"\n" ;
}                                                // Code close




/* This is the code for 'N'. It was surprisingly easy!
Coded by Dipen */
void letter_n ()
{
int n,x,y ;
n=9 ;                             // This requires a larger n value
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n; y++)
    {
     if (x==y || y==1 || y==n)
     cout<<"*" ;

     else
     cout<<" " ;
    }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}




/* This is the code for the letter "O". Coded by Dipen */
void letter_o ()
{
int n,x,y ;
n=10 ;
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n; y++)
    {
     if (x>1 && x<n)
      {
        if (y==1 || y==n)
        cout<<"*" ;

        else
        cout<<" " ;
      }
     else
      {
      if (y==1 || y==n)
      cout<<" " ;

      else
      cout<<"*" ;
      }
    }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}




/* This code is for the letter "P". Coded by Ankur */
void letter_p ()
{
 int i,j,n,p;
 n=5;
    p=1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p+2;
  }
  p=2*n-1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p-2;
  }
 for(i=1;i<=n;i++)
 {
  cout<<"*";
  cout<<endl;
 }

cout<<"\n" ;
cout<<"\n" ;
}





/* This is another lengthy code for a letter. It is for the letter "Q".
Coded by Dipen */
void letter_q ()
{                                          // Code start
int n,x,y ;
n=9 ;                                   // Use odd n values

if (n%2==1)
{                                     // For odd n values

for (x=1; x<=n+1; x++)
 {                                         // For loop start
  for (y=1; y<=n+1; y++)
    {

     if (x<=n && y<=n)                      // Big if start
      {
        if (x==1 || x==n)                    // Spacing for the top and bottom
         {
          if (y%2==0)
          cout<<" " ;

          else
          cout<<"*" ;
         }
        else
         {

          if (y==1 || y==n)
          cout<<"*" ;

          else
            {
             if (x==n-1 && y==n-1)            // Special Case
             cout<<"*" ;
             else
             cout<<" " ;
            }

         }
      }                                     // Big if close

     else
      {
        if (x==n+1 && y==n+1)                // Another Special Case
        cout<<"*" ;

        else
        cout<<" " ;
      }
    }
  cout<<"\n" ;
 }                                         // For loop close

}

else
{                                    // For even n values
for (x=1; x<=n+1; x++)
 {                                         // For loop start
  for (y=1; y<=n+1; y++)
    {

     if (x<=n && y<=n)                      // Big if start
      {
        if (x==1 || x==n)
        cout<<"*" ;

        else
         {

          if (y==1 || y==n)
          cout<<"*" ;

          else
            {
             if (x==n-1 && y==n-1)            // Special Case
             cout<<"*" ;
             else
             cout<<" " ;
            }

         }
      }                                     // Big if close

     else
      {
        if (x==n+1 && y==n+1)                // Another Special Case
        cout<<"*" ;

        else
        cout<<" " ;
      }
    }
  cout<<"\n" ;
 }                                         // For loop close

}


cout<<"\n" ;
cout<<"\n" ;
}                                          // Code Close




void letter_r ()
{
 int i,j,n,p;
 n=5;
    p=1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p+2;
  }
  p=2*n-1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p-2;
  }
    p=1;
 for(i=1;i<=n;i++)
  {
    for(j=1;j<=p;j++)
     {
      if (j==1 || j==p)
        cout<<"*";
      else
        cout<<" ";
     }
     cout<<endl;
     p=p+2;
  }

cout<<"\n" ;
cout<<"\n" ;
}





/* This is the code for the letter "S". Here, I made it look exactly like a 5.
Coded by Dipen */
void letter_s ()
{
int n,x,y,a,b ;
n=7 ;                              //1st for loop. To make this :
for (x=1; x<n; x++)                   //    ****
 {                                    //    *
  for (y=1; y<=n; y++)                //    *
    {
     if (x==1 || y==1)
     cout<<"*" ;

     else
     cout<<" " ;
    }
  cout<<"\n" ;
 }

for (a=1; a<=n; a++)                    //2nd for loop, for the lower part
 {
  for (b=1; b<=n; b++)                  //   ****
  {                                     //      *
    if (a==1 || b==n || a==n)            //      *
    cout<<"*" ;                          //   ****

    else
    cout<<" " ;
  }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}





void letter_t ()
{
 int i,j,n;
 n=9 ;
 for(i=0;i<1;i++)
  {
    for(j=0;j<n;j++)
     cout<<"*";
  }
    cout<<endl;
  for(i=0;i<n-1;i++)
    {
     for(j=0;j<(n/2);j++)
      cout<<" ";
      cout<<"*";
      cout<<endl;
     }

cout<<"\n" ;
cout<<"\n" ;
}




/* This is the code for the letter "U". Coded by Dipen */
void letter_u ()
{
int n,x,y ;
n=8 ;                              // n makes sense above 3
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n+(n/2); y++)
    {
     if (x>0 && x<n)
      {
        if (y==1 || y==n+(n/2))
        cout<<"*" ;

        else
        cout<<" " ;
      }

     else
      {
        if (y==1 || y==n+(n/2))
        cout<<" " ;

        else
         {
            if (y%2==0)
            cout<<" " ;

            else
            cout<<"*" ;
         }

      }
    }
    cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}




/* This code is to print the letter "V" using stars. Coded by Dipen */
void letter_v ()
{
int n,x,y,p,w ;
n=8 ;
p=2*n-1 ;
for (x=1; x<=n; x++)
 {
  for (w=2; w<=x; w++)
    cout<<" " ;
  for (y=1; y<=p; y++)
    {
     if (y==1 || y==p)
     cout<<"*" ;

     else
     cout<<" " ;
    }
    cout<<"\n" ;
    p=p-2 ;
  }

cout<<"\n" ;
cout<<"\n" ;
}





/* This is the code for the letter 'W'. This is the second last code!!!
Coded by Dipen. */
void letter_w ()
{
int n,x,y ;
n=11 ;                                          // Use odd n values
for (x=1; x<=n; x++)                              // Makes sense for n>5
 {
  for (y=1; y<=n; y++)
	 {

	  if (x>=1 && x<=n/2)                           // The upper empty part
		{
		  if (y==1 || y==n)
		  cout<<"*" ;

		  else
		  cout<<" " ;
		}

	  if (x>n/2 && x<n)                             // The mid part
		{
		  if (y==(n/2)+1 || y==1 || y==n)
		  cout<<"*" ;

		  else
		  cout<<" " ;
		}

	  if (x==n)                                     // Last line
		{
		  if (y==1 || y==n || y==(n/2)+1)
		  cout<<" " ;

		  else
		  cout<<"*" ;
		}

	 }
  cout<<"\n" ;
 }                                                // For loop close

cout<<"\n" ;
cout<<"\n" ;
}                                                 // Code Close






/* This is the code for the letter 'X'. Took me a long time to make it,
but it works perfectly. Coded by Dipen */
void letter_x ()
{
int n,x,y,z,p,q,r,s,a,b,c ;
n=6 ;

p=0 ;
q=2*n-1 ;
r=n-2 ;
s=3 ;

for (x=1; x<=n; x++)                       // Upper triangle
 {
  for (y=1; y<=p; y++)
  cout<<" " ;
  p++ ;

  for (z=1; z<=q; z++)
	 {
	  if (z==1 || z==q)
	  cout<<"*" ;

	  else
	  cout<<" " ;
	 }
  q=q-2 ;
  cout<<"\n" ;
 }


for (a=1; a<=n-1; a++)                     // Reamaining part
 {
  for (b=1; b<=r; b++)
  cout<<" " ;
  r-- ;

  for (c=1; c<=s; c++)
	 {
	  if (c==1 || c==s)
	  cout<<"*" ;

	  else
	  cout<<" " ;
	 }
  s=s+2 ;
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}                                          // Code Close





/* YES!!! I finally did this. This is the code for making the "Y" pattern.
Made using "For" loop. Coded by Dipen */
void letter_y ()
{
int n,x,y,z,p,q,c ;
n=6 ;
p=2*n-1 ;
for(x=1; x<=n; x++)
 {
  for (y=2; y<=x; y++)
  cout<<" " ;

  for (z=1; z<=p; z++)
	 {
	  if (z==1 || z==p)
	  cout<<"*" ;
	  else
	  cout<<" " ;
	 }
  p=p-2 ;
  cout<<"\n" ;
 }

for (q=1; q<=n-1; q++)
 {
  for (c=1; c<=n; c++)
  {
	 if (c==n)
	 cout<<"*" ;

	 else
	 cout<<" " ;
  }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}





/* This is quite a lengthy code for the letter "Z". But anyway, the good thing
is that it works. Coded by Dipen */
void letter_z ()
{
int n,x,y,p,z ;
n=10 ;                                   // Use odd n values
p=n-2 ;                                    // Makes sense when n>=3

if (n%2==1)                                // For odd n values
{                                          // If start

for (x=1; x<=n; x++)                                // Top line
 {
  if (x%2==0)
  cout<<" " ;

  else
  cout<<"*" ;
 }
cout<<"\n" ;

for (x=1; x<=n-2; x++)                              // Mid section
 {
  for (y=1; y<=p; y++)
	 cout<<" " ;
	 cout<<"*" ;
	 p-- ;
  cout<<"\n" ;
 }

for (x=1; x<=n; x++)                                // Last line
 {
  if (x%2==0)
  cout<<" " ;

  else
  cout<<"*" ;
 }

}                                          // If Close


else                                       // For even n values
{                                          // Else start

for (x=1; x<=n; x++)                                // Top line
cout<<"*" ;
cout<<"\n" ;

for (x=1; x<=n-2; x++)                              // Mid section
 {
  for (y=1; y<=p; y++)
	 cout<<" " ;
	 cout<<"*" ;
	 p-- ;
  cout<<"\n" ;
 }

for (x=1; x<=n; x++)                                // Last line
cout<<"*" ;

}                                          // Else Close

cout<<"\n" ;
cout<<"\n" ;
}                                          // Code close





void number_0 ()
{
 int i,j;
 for(i=1;i<=10;i++)
  {
	 for(j=1;j<=10;j++)
	 {
	  if(i<=9&&i>=2)
		if(j==1||j%10==0)
		  cout<<"*";
		else
		  cout<<" ";
	  else
		cout<<"*";
	 }
	 cout<<endl;
  }

cout<<"\n" ;
cout<<"\n" ;
}




void number_1 ()
{
 int n,i,j;
 n=6 ;
 for(i=1;i<=n-1;i++)
 {
  cout<<"*";
 }
 cout<<endl;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<n-1;j++)
	 cout<<" ";
  for(j=n-1;j<n;j++)
	 cout<<"*";
	 cout<<endl;
 }
 for(i=1;i<=2*n-3;i++)
 {
  cout<<"*";
 }

cout<<"\n" ;
cout<<"\n" ;
}




void number_2 ()

{
int n,x,y,a,b ;
n=6 ;                                    // Use only even n values

for (x=1; x<=n; x++)                        // Upper Part
 {
  for (y=1; y<=n; y++)
	 {
	  if (x==1 || x==n)
		{
		  if (y%2==1)
			cout<<"*" ;

		  else
			cout<<" " ;
		}

	  else
		{
		  if (y==n)
			cout<<"*" ;
		  else
			cout<<" " ;
		  }
	 }
  cout<<"\n" ;
 }

for (a=1; a<n; a++)                         // Lower Part
 {
  for (b=1; b<=n; b++)
	 {
	  if (a==n-1)
		{
		  if (b%2==1)
			cout<<"*" ;

		  else
			cout<<" " ;
		}

	  else
		{
		  if (b==1)
		  {
			if (b%2==1)
			 cout<<"*" ;

			else
			 cout<<" " ;
		  }

		  else
		  cout<<" " ;
		}
	 }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}




void number_3 ()
{
 int i,j,n;
 n=6 ;
 for(i=1;i<=n+1;i++)
	 cout<<"*";
	 cout<<endl;
 for(i=1;i<=n-2;i++)
  {
	 for(j=1;j<=n;j++)
	  cout<<" ";
	 for(j=n;j<n+1;j++)
	  cout<<"*";
	  cout<<endl;
	 }
 for(i=1;i<=n+1;i++)
	 cout<<"*";
	 cout<<endl;
 for(i=1;i<=n-2;i++)
  {
	 for(j=1;j<=n;j++)
	  cout<<" ";
	 for(j=n;j<n+1;j++)
	  cout<<"*";
	  cout<<endl;
	 }
  for(i=1;i<=n+1;i++)
	 cout<<"*";
	 cout<<endl;

cout<<"\n" ;
cout<<"\n" ;
}





void number_4 ()
{
{
 int i,j,n;
 n=7 ;
 for(i=1;i<=n;i++)
 { if(i<=n-2)
  {for(j=1;j<=1;j++)
	 cout<<"*";
	 cout<<endl;
	 }
	 if(i>n-2)
	 {
	  for(j=1;j<=n;j++)
		if(j==1||j==n)
		  cout<<"*";
		else
		  cout<<" ";
		  cout<<endl;
	  }
  }
  for(i=1;i<=n;i++)
	 cout<<"*";
	 cout<<endl;
  for(i=1;i<=n-2;i++)
  {
	 for(j=1;j<=n-1;j++)
	  cout<<" ";
	 for(j=n;j<=n;j++)
	  cout<<"*";
	 cout<<endl;
  }
}

cout<<"\n" ;
cout<<"\n" ;
}




/* This is the code for the number '5'. This raises a problem as this is
exactly like 'S'. Gotta see that  later. Coded by Dipen */
void number_5 ()
{
int n,x,y ;
n=9 ;                                       // Only use odd n values
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n; y++)
	 {
	  if ( x==1 || x==(n/2)+1 || x==n )
		{
		  if (y%2==1)
			cout<<"*" ;
		  else
			cout<<" " ;
		}

	  if (x>1 && x<(n/2)+1)
		{
		  if (y==1)
			cout<<"*" ;
		  else
			cout<<" " ;
		}

	  if (x>(n/2)+1 && x<n)
		{
		  if (y==n)
			cout<<"*" ;
		  else
			cout<<" " ;
		}
	 }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}




void number_6 ()
{
 int i,j,n;
 n=7 ;
 for(i=1;i<=n;i++)
	 cout<<"*";
	 cout<<endl;
 for(i=1;i<=n-2;i++)
 {
  for(j=1;j<=1;j++)
	 cout<<"*";
	 cout<<endl;
 }
 for(i=1;i<=n;i++)
  {
	 for(j=1;j<=n;j++)
	 {
	  if(i<=n-1&&i>=2)
		if(j==1||j%n==0)
		  cout<<"*";
		else
		  cout<<" ";
	  else
		cout<<"*";
	 }
	 cout<<endl;
  }

cout<<"\n" ;
cout<<"\n" ;
}




void number_7 ()
{
 int k,i,j,n;
 n=9 ;
 k=n-1;
 for(i=1;i<=n;i++)
  {
	if (i%2!=0)
	 cout<<"*";
	else
	 cout<<" " ;
  }
  cout<<endl;
 for(i=1;i<=n-1;i++)
 {
  for(j=1;j<=k;j++)
	 if(j==k)
	  cout<<"*";
	 else
	  cout<<" ";
	 cout<<endl;
	 k=k-1;
 }

cout<<"\n" ;
cout<<"\n" ;
}




void number_8 ()
{
 int i,j,n;
 n=8 ;
 for(i=1;i<=n;i++)
  cout<<"*";
  cout<<endl;
 for(i=1;i<=n-4;i++)
 {
  for(j=1;j<=n;j++)
  if(j==1||j==n)
	  cout<<"*";
  else
	  cout<<" ";
  cout<<endl;
 }
 for(i=1;i<=n;i++)
  cout<<"*";
  cout<<endl;
 for(i=1;i<=n-4;i++)
 {
  for(j=1;j<=n;j++)
  if(j==1||j==n)
	  cout<<"*";
  else
	  cout<<" ";
  cout<<endl;
 }
  for(i=1;i<=n;i++)
  cout<<"*";
  cout<<endl;

cout<<"\n" ;
cout<<"\n" ;
}





/* This is the code for the number '9'. It is practically the code of '5'
with a little twist. Coded by Dipen */
void number_9 ()
{
int n,x,y ;
n=9 ;                                       // Only use odd n values
for (x=1; x<=n; x++)
 {
  for (y=1; y<=n; y++)
	 {
	  if ( x==1 || x==(n/2)+1 || x==n )
		{
		  if (y%2==1)
			cout<<"*" ;
		  else
			cout<<" " ;
		}

	  if (x>1 && x<(n/2)+1)
		{
		  if (y==1 || y==n)
			cout<<"*" ;
		  else
			cout<<" " ;
		}

	  if (x>(n/2)+1 && x<n)
		{
		  if (y==n)
			cout<<"*" ;
		  else
			cout<<" " ;
		}
	 }
  cout<<"\n" ;
 }

cout<<"\n" ;
cout<<"\n" ;
}









int main ()
{
int p ;
char ch,input[50] ;


do
{

//clrscr () ;

cout<<"This is the 'Star' font project"<<"\n" ;
cout<<"Made by Dipen and Ankur"<<"\n" ;
cout<<"Enter any Alphanumeric String"<<"\n" ;
cin.getline(input,50) ;

for (p=0; input[p]!='\0'; p++)
{
  if (input[p]=='a' || input[p]=='A')
	  letter_a () ;

  if (input[p]=='b' || input[p]=='B')
	  letter_b () ;

  if (input[p]=='c' || input[p]=='C')
	  letter_c () ;

  if (input[p]=='d' || input[p]=='D')
	  letter_d () ;

  if (input[p]=='e' || input[p]=='E')
	  letter_e () ;

  if (input[p]=='f' || input[p]=='F')
	  letter_f () ;

  if (input[p]=='g' || input[p]=='G')
	  letter_g () ;

  if (input[p]=='h' || input[p]=='H')
	  letter_h () ;

  if (input[p]=='i' || input[p]=='I')
	  letter_i () ;

  if (input[p]=='j' || input[p]=='J')
	  letter_j () ;

  if (input[p]=='k' || input[p]=='K')
	  letter_k () ;

  if (input[p]=='l' || input[p]=='L')
	  letter_l () ;

  if (input[p]=='m' || input[p]=='M')
	  letter_m () ;

  if (input[p]=='n' || input[p]=='N')
	  letter_n () ;

  if (input[p]=='o' || input[p]=='O')
	  letter_o () ;

  if (input[p]=='p' || input[p]=='P')
	  letter_p () ;

  if (input[p]=='q' || input[p]=='Q')
	  letter_q () ;

  if (input[p]=='r' || input[p]=='R')
	  letter_r () ;

  if (input[p]=='s' || input[p]=='S')
	  letter_s () ;

  if (input[p]=='t' || input[p]=='T')
	  letter_t () ;

  if (input[p]=='u' || input[p]=='U')
	  letter_u () ;

  if (input[p]=='v' || input[p]=='V')
	  letter_v () ;

  if (input[p]=='w' || input[p]=='W')
	  letter_w () ;

  if (input[p]=='x' || input[p]=='X')
	  letter_x () ;

  if (input[p]=='y' || input[p]=='Y')
	  letter_y () ;

  if (input[p]=='z' || input[p]=='Z')
	  letter_z () ;

  if (input[p]==' ')
	  cout<<endl<<endl<<endl<<endl ;

  if (input[p]=='0')
	  number_0 () ;

  if (input[p]=='1')
	  number_1 () ;

  if (input[p]=='2')
	  number_2 () ;

  if (input[p]=='3')
	  number_3 () ;

  if (input[p]=='4')
	  number_4 () ;

  if (input[p]=='5')
	  number_5 () ;

  if (input[p]=='6')
	  number_6 () ;

  if (input[p]=='7')
	  number_7 () ;

  if (input[p]=='8')
	  number_8 () ;

  if (input[p]=='9')
	  number_9 () ;

}                                          // For Loop Close

cout<<"Want to continue?? Y/N"<<"\a"<<"\n" ;
xyz:
ch=getch() ;
}                                          // Do..while Close

while (ch=='y') ;
if(ch=='n')
  {cout<<"Thanks for using. Made by Dipen and Ankur." ;
  exit(0);}
else
  cout<<"Enter Character y or n "<<endl;
  goto xyz;


return 1 ;

}                                         //Code Close
