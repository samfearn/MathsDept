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

  //  m=1;
  //  m=5;
    m=11;
  // m=50;

  ofstream out ("out");
  h=2.0/(1.0*n);

   for(i=0;i<=n;i++){
     x=h*i-1.0;
     f=sqrt(x*x);

     fs=0.5;
     for(j=1;j<=m;j++){
       a=2.0/pow(pi*j,2)*(pow(-1.0,j)-1.0);     
       fs=fs+a*cos(j*pi*x);
     }

     out << x << " " << f << " " << fs << "\n";

   }

}

   
