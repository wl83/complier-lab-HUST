int a, b, c;
float m, n;
int d[10][10];


// typedef struct
// {
// 	int a;
// 	int b;
// }TestStruct; // 未实现typedef

struct node{
	int a;
	int b;
};


int fibo(int a) // 16
{
    //    TestStruct tt;
	struct node tt; // 24
    if (a == 1 || a == 2) // 32
		return 1; // 36
	else if (a >= 3){  // 40
		tt.a = d[1][2]; // 48
	    c = d[1][2]; // 56
	    return fibo(a-1) + fibo(a-2); // 56+28 = 84
	}
    return 0; // 88
}

int main(int argc)
{
	int i;
	
	for(i = 1; i < 10; i++)
	{
		if(i > 9)
		{
			fibo(i);
			break;
		} 
		else
		{
			fibo(i);
			continue;
		}
		i++;
	}
	return 1;
}

