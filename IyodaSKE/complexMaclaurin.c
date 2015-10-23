#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct FCOMPLEX {double r,i;} fcomplex;

//複素数の四則演算である
int main(int argc,char** argv){ 
  fcomplex x,y,z;
  double w,v,a,b;
  int i,j,k,l,n;
  int mem=0;
  int sum=0;

  x.r=atof(argv[1]);
  x.i=atof(argv[2]);
  y.r=atof(argv[3]);
  y.i=atof(argv[4]);
  
  fcomplex Cadd(fcomplex x, fcomplex y){
    fcomplex z;
    z.r=x.r+y.r;
    z.i=x.i+y.i;
    return(z);  
  }
   printf("z=%f+%fi\n",z.r,z.i);
  
  fcomplex Csub(fcomplex x ,fcomplex y){
    fcomplex z;
    z.r=x.r-y.r;
    z.i=x.i-y.i;
    return(z);
  }
  
  fcomplex Cmul(fcomplex x, fcomplex y){
    fcomplex z;
    z.r=(x.r*y.r)-(x.i*y.i);
    z.i=(x.r*y.i)+(x.i*y.r);
    return(z);
  }
  
  fcomplex Cdiv(fcomplex x, fcomplex y){
    fcomplex z;
    z.r=((x.r*y.r)+(x.i*y.i))/(y.r*y.r)+(y.i*y.i);
    z.i=((x.i*y.r)-(x.r*y.i))/(y.r*y.r)+(y.i*y.i);
    return(z);
  }
  
  fcomplex Cexp(fcomplex x){
    fcomplex z;
    z.r=exp(x.r)*cos(x.i);
    z.i=exp(x.r)*sin(x.i);
    return(z);
  }
  /*以下の複素数を用いたe^(a+bi)のマクローリン展開は
(e^a)*(e^ib)=(e^a)(cosb+isinb)という式変形を経て求められたものである
(e^a)を求めwに保存した後(cosb+isinb)を求めvに保存する
wとvをCmulで計算する
その後cosxとsinxを求めるものであるが、sinxには((e^ix)-(e^-ix))/2i という形で
分母に複素数がやってくるのでCdivで計算する
そうすると求まる
*/
  putchar('\n');
  n=2;
  x=atof(argv[1]);
  sum=x;
  y=x;
  mem=0;
  while(1){//isinb
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
  while(1){//cosb
    y*=((-1)*(x*x))/(double)((2*n)*(2*n-1));
    sum+=y;
    if(y-mem==0){break;}
    mem=y;
    printf("sum=%.40f \n",sum);
    n+=1;
  }
  printf("sum=%.40f \n",sum);



  return 0;
}
