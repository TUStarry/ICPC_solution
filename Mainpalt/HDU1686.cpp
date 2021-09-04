#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
char mainstr[maxn];
char patstr[maxn];
int nex[maxn];
void getnext()
{
    nex[0] = -1;
    for(int i=0,j=-1;patstr[i];)
    {
        if(j==-1||patstr[i] == patstr[j]) nex[++i] = ++j;
        else j = nex[j];
    }
}
void Kmp()
{
    getnext();
    int len = strlen(patstr),ans = 0;
    for(int i=0,j=0;mainstr[i];)
    {
        if(j==-1||mainstr[i]==patstr[j])
        {
            if(len-1 == j)
            {
                j = nex[j];
                ans++;

            }
            else
                i++,j++;
        }
        else
            j = nex[j];
    }
    printf("%d\n",ans);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%s",patstr);
        scanf("%s",mainstr);
        Kmp();
    }
    return 0;
}
