#include<stdio.h>
#include<stdlib.h>
int main(int argc,char** argv){
  double sum,x,mem,y;
  int i,n;
  n=1;
  x=atof(argv[1]);
  sum=1.0;
  while(1){//e^x
    printf("sum=%.20f \n",sum);
    mem=sum;
    x=x/(double)n;
    sum+=x;
    n+=1;
    if(sum-mem==0){break;}
  }

  putchar('\n');
  n=2;
  x=atof(argv[1]);
  sum=x;
  y=x;
  mem=0;
  while(1){//sinx
    y*=((-1)*(x*x))/(double)((2*n-1)*(2*n-2));
    sum+=y;
    if(y-mem==0){break;}
    mem=y;
    printf("sum=%.40f \n",sum);
    n+=1;
  }
  printf("sum=%.40f \n",sum);

  putchar('\n');
  n=1;
  x=atof(argv[1]);
  sum=1.0;
  y=1.0;
  mem=0;
  while(1){//cosx
    y*=((-1)*(x*x))/(double)((2*n)*(2*n-1));
    sum+=y;
    if(y-mem==0){break;}
    mem=y;
    printf("sum=%.40f \n",sum);
    n+=1;
  }
  printf("sum=%.40f \n",sum);
  return(0);
}
