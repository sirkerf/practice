#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
  double  h;//刻み幅h
  double  t;//求めたいt
  double  s;//現在時刻、グラフの横軸に使う
  double *x;//x(t+h)の列を格納する配列
  double *y;//y(t+h)の列を格納する配列
  int     i;//カウンタ

  printf("求めたい実数を入力せよ："); scanf("%lf",&t);
  printf("刻み幅を0より大きく1未満であるような実数で入力せよ："); scanf("%lf",&h);

  x=(double*)malloc(sizeof(double)*((t/h)+1));//指定した数の分だけ配列になるメモリを確保する
  y=(double*)malloc(sizeof(double)*((t/h)+1));//上に同じ
 
  x[0]=1;//x(0)=1
  y[0]=0;//x'(0)=0

  for(i=0;i<((t/h)+1);i++){
    x[i+1]=((1/(1+(h*h)))*x[i])+((h/(1+(h*h)))*y[i]);
    y[i+1]=((1/(1+(h*h)))*y[i])-((h/(1+(h*h)))*x[i]);
  }

  s=0.0;

  for(i=0;i<((t/h)+1);i++){
    printf("%.5lf %.16lf\n",s,x[i]);//sは時刻
    s+=h;
  }

  return(0);
}
