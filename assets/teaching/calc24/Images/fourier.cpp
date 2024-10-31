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

  // m=1;
  //  m=6;
    m=11;
  // m=50;

  ofstream out ("out");
  h=2.0*pi/(1.0*n);

   for(i=0;i<=n;i++){
     x=h*i-pi;
     f=x;

     fs=0.0;
     for(j=1;j<=m;j++){
       b=2.0/(1.0*j)*pow(-1.0,j+1);     
       fs=fs+b*sin(j*x);
     }

     out << x << " " << f << " " << fs << "\n";

   }

}

   