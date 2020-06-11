int a,b,c;
float m,n;
int fibo(int a)
{
    if (a == 1 || a == 2) return 1;
    return fibo(a-1)+fibo(a-2);
}