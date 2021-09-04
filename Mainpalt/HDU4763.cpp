#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
char patstr[maxn];
int nex[maxn];
void getnext(int len)
{
    nex[0] = -1;
    for(int i=0,j=-1;i<len;)
        if(j==-1||patstr[j]==patstr[i]) nex[++i] = ++j;
        else j = nex[j];
    for(int i=0;i<len;i++)
        cout<<nex[i]<<" ";
    cout<<endl;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",patstr);
        int ans = 0,len = strlen(patstr);
        getnext(len);

    }
    return 0;
}
