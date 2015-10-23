#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main(int argc,char *argv[]){

      double *x;
      double *oldx;
      double max=0.0;
      FILE *filename;
      char line[256];
      char space[]=" ";
      char c;
      int i=0;
      int j=0;
      int k=0;
      int n;
      double sum;
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
      x = (double*)malloc(sizeof(double)*n);
      oldx = (double*)malloc(sizeof(double)*n);
      
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

      i=0;
      j=0;
      
      for(i=0;i<n;i++){
	oldx[i] = 0.0;
      }
      
      //ここからヤコビ
      start = clock();
      for(k=0;k<1000;k++){
	for(i=0;i<n;i++){
	  x[i] = datas[i][n];
	  for(j=0;j<n;j++){
	    if(i != j){
	      x[i] -= datas[i][j]*oldx[j];
	    }
	  }
	  x[i] /= datas[i][i];
	  
	  //収束条件
	  
	  if(max < fabs(x[i] - oldx[i])){
	    max = fabs(x[i] - oldx[i]);
	  }
	}
	if(max<0.000001) break;
	for(i=0;i<n;i++)
	  oldx[i] = x[i];

      }
      finish=clock();
      
      printf("%d\n",n);
      for(i=0;i<n;i++){
	printf("x_%d=%lf\n",i+1,x[i]);
      }
       for(i=0;i<n;i++){
	free(datas[i]);
      }
 
       printf("計算時間：%f\n",((double)finish-(double)start)/CLOCKS_PER_SEC);     
      free(datas);
      free(answer);
      free(x);
      free(oldx);
      
      return 0;
}
