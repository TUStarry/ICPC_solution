#include<iostream>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int fu = 1, num = 0;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num*10)+(ch-'0');ch=getchar();}
    return num*fu;
}
int main()
{
    while(1)
    {
        int t = read();
        cout<<t<<endl; 
    }
    return 0;
}