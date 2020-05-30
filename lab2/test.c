// 函数参数与局部变量重复 V
// 赋值表达式不是左值 V
// 返回值类型错误 V
// int f2(int a,int b)
// {
//     int a,b;
//     a+b=10;
//     (a+b)++;
//     ++a++;
//     return 12.3;
// }

// break不在循环语句中
// continue不再循环语句中
// int f3()
// {
//     int a,b;
//     if (a-12.3) 
//         continue;
//     else   
//         break;
//     while ( a || f3()) 
//     {
//         while (1) 
//             break;
//         continue;
//     }
//     for(a=1;a>0 && f3()>0;a++)
//  	    if (a+b==0.0) 
//             break;
//     return 1;
// }

// 结构体不是左值 2
// x不是结构体
// m.a不是结构体
// 缺少return
// float f4(float x) 
// {
//     struct A{
//         int a;
//         float b;
//         char c;
//     } m;
//     int a;
//     m=12;
//     m++;
//     m.b=17;
//     x.a=m.b;
//     m.d=m.a.a;
// }

// 返回值类型不匹配
// a不是数组
// f5不是数组
// 数组下标不是整型表达式
// int f5(int a)  
// {
//     float x[10][20],y=12.3;
//     x=a[1]+f5[1];
//     x[1]=x[1][y]+x[1+1][1];
//     return y;
// }

int f1(int a, int y){
    return 0;
}
