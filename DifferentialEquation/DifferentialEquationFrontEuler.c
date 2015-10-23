#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){

  double  h;//刻み幅
  double  t;//求める実数
  double *x;//x(t+h)となる配列
  double  s=0.0;//現在の時間
  int     i;//カウンタ

    printf("求めたい実数を入力せよ：");                              scanf("%lf",&t);
    printf("刻み幅を0より大きく1未満であるような実数で入力せよ：");     scanf("%lf",&h);

      x=(double*)malloc(sizeof(double)*((t/h)+1));
      x[0]=0.0;//x(0)=0である

      for(i=0.0;i<(t/h)+1;i++){
      x[i+1]=x[i]+(h)*(2.0)*(s);
      s+=h;
      }

      s=0;

    for(i=0;i<((t/h)+1);i++){
      printf("%.16f %.16f\n",s,x[i]);//sは時刻
      s+=h;
    }

  return(0);
}
