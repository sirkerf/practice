#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(int argc, char *argv[]){
  double more;
  int size;
  int i,j,k;
  double **a;
  double sum;

  for(i=0;i<size;i++){

    //L成分のlを計算する
    for(j=0;j<size;j++){
     sum=0;
        for(k=0;k<j;k++){
        sum += (a[i][k]*a[k][j]);
        }
     a[i][j] -= sum;
     }

    //U成分のuを計算する
    for(j=i+1;j<size;j++){
     sum=0;
        for(k=0;k<i;k++){
        sum += (a[i][k]*a[k][j]);
        }
	a[i][j] =((a[i][j] - sum)/a[i][i]);
    }
  }  
  //Ux=yとおき、Ly=bを解く手順
  for(i=0;i<size;i++){
    sum=0;
    for(j=0;j<i;j++){
      sum += (a[i][j]*a[i][size]);
    }
    a[i][size]=((a[i][size]-sum)/a[i][i]);
  }


  //Ux=yを解きます
  for(i=size;i>0;i--){
    sum=0;
   }


return(0);
}
