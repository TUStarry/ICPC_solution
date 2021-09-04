#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
typedef long long ll;
inline int read(){
    int num = 0, fu =1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9') {num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return fu*num;
}
int main()
{
    int T = read();
    while(T--)
    {
        int n = read(), m = read(), total = 0;
        for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        for(int k=0;k<=n;k++)
        {
            cout<<i<<" "<<j<<" "<<k<<endl;
            if(i+k+j > n) continue;
            if(i+k+j == n &&i+j*2+k*5==m)
                total++;
        }
        printf("%d\n",total);
    }
    return 0;
}

