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


int fibo(int a)
{
    //    TestStruct tt;
	struct node tt;
      if (a == 1 || a == 2){
		  return 1;
	  }
						// return fibo(a - 1) + fibo(a - 2);
	    if (a>=3)
	    	{
	    		tt.a = d[1][2];
	    		c = d[1][2];
	    		return fibo(a-1) + fibo(a-2);
	    	}
        return 0;
}

int main(int argc)
{
	int i, temp;
	
	for(i = 1;i<10;i++)
	{
		if(i>9)
			{
				temp = fibo(i);
				write(temp);
				break;
			} 
			else
			{
					temp = fibo(i);
					write(temp);
					continue;
			}
			i++;
	}
	return 1;
}

