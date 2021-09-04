#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 9999;
char mainstr[maxn];
char patstr[maxn];
int nex[maxn];
inline int read()
{
    int num = 0, fu = 1;
    char ch = getchar();
    while('0'>ch||ch>'9') {if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num<<3)+(num<<1)+(ch^48);ch=getchar();}
    return num*fu;
}
void get_next()
{
    nex[0] = -1;
    for(int i=0,j=-1;patstr[i];)
        if(j==-1||patstr[i]==patstr[j]) nex[++i] = ++j;
        else j = nex[j];
}
void Kmp()
{
    get_next();
    int lenpatstr = strlen(patstr), ans = 0;
    for(int i=0,j=0;mainstr[i];)
    {
        if(j==-1||patstr[j] == mainstr[i])
            if(j==lenpatstr-1) ans++,j=0,i++;
            else i++, j++;
        else
            j = nex[j];
    }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%s%s",mainstr,patstr) == 2)
        Kmp();

    return 0;
}