#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc,char *argv[]){

         FILE *filename;
	 char line[256];
	 char space[]=" ";
	 char c;
	 int i=0;
	 int j=0;
	 int k=0;
	 int n;
	 double sum;
	 double *data;
	 double **datas;
	 double *answer;
	 clock_t start,finish;
     /*引数は２*/
     if(argc!=2){
       printf("Operand Error\n");
       return -1;
     }
     /*ファイルを読み込む*/
     if((filename=fopen(argv[1],"r")) == NULL){
       printf("File does not exist\n");
       return -1;
     }
     /*配列のためのメモリを確保する*/
     /*ダブルポインタを使うのは二次元配列のため*/
       fgets(line,(int)sizeof(line),filename);
       n = atoi(line);
       printf("%d\n",n);
       answer = (double*)malloc(sizeof(double)*n);
       datas = (double**)malloc(sizeof(double*)*n);
       
      for(i=0;i<n;i++){
	 datas[i] = (double*)malloc(sizeof(double)*(n+1));
      }

      i=0;//nのままになっているのでここで0に戻す
      j=0;
      k=0;
      while((c=fgetc(filename)) != EOF){
       line[k]=c;
       k++;
       if(c == ' '){
	line[k-1] = '\0';
        datas[i][j]=atof(line);
	j++;
	k=0;
       }else if(c == '\n'){
	 line[k-1] = '\0';
	 datas[i][j] = atof(line);
	 i++;
	 j=0;
	 k=0;
       }
     }
  
     
     //ここからLU
      start = clock();
    for(i=0;i<n;i++){
    //L成分のlを計算する
    for(j=0;j<=i;j++){
     sum=0.0;
        for(k=0;k<j;k++){
        sum += (datas[i][k]*datas[k][j]);
        }
     datas[i][j] -= sum;
     }

    //U成分のuを計算する
    for(j=i+1;j<n;j++){
     sum=0.0;
        for(k=0;k<i;k++){
        sum += (datas[i][k]*datas[k][j]);
        }
	datas[i][j] =((datas[i][j] - sum)/datas[i][i]);
    }
  }

  //Ux=yとおき、Ly=bを解く手順
  for(i=0;i<n;i++){
    sum=0.0;
    for(j=0;j<i;j++){
      sum += (datas[i][j]*datas[j][n]);
    }
    datas[i][n]=((datas[i][n]-sum)/datas[i][i]);
  }

  //Ux=yを解きます
  for(i=n-1;i>=0;i--){
    sum=0.0;
    for(j=i+1;j<n;j++){
      sum += (datas[i][j]*datas[j][n]);
   }
    datas[i][n] = (datas[i][n] - sum);
  }
  finish = clock();

  for(i=0;i<n;i++)
    {printf("x_%d=%lf,\n",i+1,datas[i][n]);}
  printf("計算時間：%f\n",((double)finish-(double)start)/CLOCKS_PER_SEC);
return (0);
}
