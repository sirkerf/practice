#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*このコードはデータファイルを取り込むためのものである
このコードの下にJacobi Method 及び LUMethodのコードを書き加えることで使いたいプログラムが完成する*/
int main(int argc,char *argv[]){

         FILE *filename;
	 char line[256];
	 char space[]=" ";
	 char *ends;
	 char c;
	 int i=0;
	 int j=0;
	 int k=0;
	 int n;
	 double sum;
	 double *data;
	 double **datas;
	 double *answer;
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
     for(i=0;i<n;i++){
       for(j=0;j<n;j++){
	 printf("x_%d_%d = %lf \n",i+1,j+1,datas[i][j]);
       }
     }
     return 0;
}
