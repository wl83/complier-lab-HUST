int a, b, c;
float m, n;
int b[10][10];// test3 conflict declare
int d[10][10];

// int test(int a); 没有实现该功能

// typedef struct 没有实现typedef
// 修改struct定义
struct node
{
	int a;
	int b;
};

//double *f, g;
int fibo(int a)
{
    // _TestStruct tt;
	struct node tt;
    
	test1(c);//test 2
	if (a == 1 || a == 2)
		return 1;
	return 
		fibo(a - 1) + fibo(a - 2);
	//just Test
	if (a > 10)
		return 
			fibo(a - 1, a - 2);//test6 too many arguments
		//
	if (b > 100)
		return fibo(a - 1) + fibo(a - 2);
	else
	{
		b--;
	}

    fibo(tt); //test 7

    c = a[8]; // test8
    m = 0.8;
    n = 0.9;
    c = d[m][n];// test 9
    c.a; //test 10;
    a = tt.c ;  //test 11
	tt++; //test 14
	break; // test 18
        return 0;
}
void testf()
{
    return 'a';
    
}// test 16

int  testff()
{
     int i;
     i++;
}// test 17

int main(int argc)
{
    int m=10, n, i;
	test1 = 0;//test1 
	i = 1;
    n = m(); //test 4
    (n+1) = m; // test 12
    --(n+1);  //test13
    a = m; // test 15
    continue; //test 19
	while (i <= m)
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

