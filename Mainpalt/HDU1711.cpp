#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 99999;
int mainstr[maxn];
int patstr[maxn];
int nex[maxn],n, m;
void getnext()
{
    nex[0] = -1;
    for(int i=0,j=-1;i<m;)
    {
        if(j==-1||patstr[i] == patstr[j]) nex[++i] = ++j;
        else j = nex[j];
    }
}
int Kmp()
{
    getnext();
    for(int i=0,j=0;i<n;)
    {
        if(j==-1||mainstr[i] == patstr[j])
        {
            if(j == m - 1)
            {
                return i-m+2;
            }
            else
                i++,j++;
        }
        else
            j = nex[j];
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&mainstr[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&patstr[i]);
        printf("%d\n",Kmp());
    }
    return 0;
}
