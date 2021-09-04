#include<bits/stdc++.h>  
using namespace std;
int year,month;   
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //定义月份对应天数数组
int main()
{
    cin>>year>>month;   //输入年和月
    if((year%4==0&&year%100!=0)||year%400==0)a[2]=29;   //判断闰年
    cout<<a[month];   //直接输出
    return 0;   
}
