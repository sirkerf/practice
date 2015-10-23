#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc,char *argv[]){
  double x[];
  double a[][];
  double i,j;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      x[i]  = a[i][n];
      x[i] -= a[i][j];
    }
      x[i] /= a[i][i];
    if(x[i]-x[i-1]<0.001)
      break;
  }

  return 0;}
