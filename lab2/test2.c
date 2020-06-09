// int   a=10; 没有实现全局变量声明时赋值
int a;
float b, c;
int  f1(int x,int y){
    char  a='a';
    //    double c; 没有实现double
    float c;
	a='b';
    { float a=5.0;
		b=a*10+c;
         }
         { 
             int f;
	     f=10;
         }
     }
char d;
int  main(int a,int b){
        return 1;
    }
