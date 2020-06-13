int a, b, c;
float m, n;
int b[10][10];// test3 conflict declare
int d[10][10];

// int test(int a); // 未实现函数声明

// typedef struct
// {
// 	int a;
// 	int b;
// }_TestStruct; // 未实现typedef

struct node{
	int a;
	int b;
};


//double *f, g;
int fibo(int a)
{
    // _TestStruct tt; // 未实现typedef
    struct node tt;

    if ((--a) == 1 || a == 2)
		return 1;
	return fibo(a - 1) + fibo(a - 2);
	//just Test
	if (a > 10)
	return fibo(a - 1, a - 2);//test6 too many arguments
		//
	if (b > 100)
		return fibo(a - 1) + fibo(a - 2);
	else
	{
		b--;
	}

        fibo(tt); //test 7

        a = 1;
        b = 2;
        tt.a = d[a][b];// test 9
        return 0;
}
char testf()
{
    return 'a';
    
}
int main(int argc)
{
       
      
	int m=10, n, i;
	i = 1;
	while ((i+1) <= m)
	{
		n = fibo(i);
		i = i + 1;
                if(i>10)
                     {
			break; //test18
		      }
                else
                  continue; // test19
	}
        n = fibo; // test 5
	return 1;

}

