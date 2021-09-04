#include<iostream>
#include<cstdio>
const int maxn = 5005;
using namespace std;
inline int read()
{
    int fu = 1, num = 0;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num*10)+(ch-'0');ch=getchar();}
    return num*fu;
}
int a[maxn];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int cnt = 0;
        for(int i=0;i<n;i++) a[i] = read();
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        if(a[i] > a[j]) cnt++;
        int minn = cnt;
        for(int i = 0; i < n; i++)    
        {
            cnt += n - a[i] - a[i] - 1;
            if(minn > cnt) minn = cnt;
        }
        printf("%d\n", minn);
    }         
    return 0;
}