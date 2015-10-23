#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(int argc,char** argv){
  double sum,r,a,mem;
  r=atof(argv[1]);
  a=atof(argv[2]); 
  int i;
  if(r>=1){
    printf("Error\n");
    return(-1);}
  sum=a;//初項を代入
  i=0;//カウンタ
  while(1){
    printf("r=%.10f sum=%.10f i=%d\n",r,sum,i);
    mem=sum;
    sum+=r;
    r*=atof(argv[1]);
    i+=1;
    if(mem-sum==0)break;
  }
  return(0);
}
/*
等比数列の和の公式は、|r|<1の場合は
a/(1-r)で求めることができる.
proof
等比数列の一般項がar^(n-1)で書き表されていたとき,そのn項までの和は
a+ar+ar^2+...+ar^(n-1)である.これはa((r^n)-1)/(r-1)とまとめることができる.(これを(i)とする)
ところで,数列のn項目の和は無限級数をn項目で打ちきったものと考えられるので,(i)を用いて問題の級数は
lim[n→∞]a((r^n)-1)/(r-1)と書ける.
|r|<1であることからこの極限の値は-a/(r-1)となり,つまりa/(1-r)となる.□
*/
