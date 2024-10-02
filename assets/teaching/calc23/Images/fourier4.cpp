/* c++ code to output data for fourier series plots*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

const int n=1000;
const double pi=4.0*atan(1.0);

double f,fs,a,b;
double h;

int  main()
{
  int i,m,j;
  double x;

    m=1;
  //  m=5;
  //  m=11;
  // m=50;

  ofstream out ("out");
  h=1.0/(1.0*n);

   for(i=0;i<=n;i++){
     x=h*i-0.0;
     f=0.0;
     if(x<0){f=0;}

     fs=0;
     for(j=1;j<=m;j++){
       a=8.0/pow(pi*(2.0*j-1.0),2)*pow(-1.0,j+1);
       //       b=1.0/(pi*j)*pow(-1.0,j+1);    
       fs=fs+a*sin((2.0*j-1.0)*pi*x);
     }

     out << x << " " << f << " " << fs << "\n";

   }

}

   
