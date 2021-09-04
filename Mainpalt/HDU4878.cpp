#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 99999;
char mainstr[maxn];
char patstr[maxn];
int nex[maxn], ans = 0;
void get_next()
{
    nex[0] = -1;
    for(int i=0,j=-1;patstr[i];)
    {
        if(j==-1|| patstr[i] == patstr[j]) nex[++i] = ++j;
        else j = nex[j];
    }
}
void Kmp()
{
    get_next();
    int len = strlen(patstr), j = -1;
    char ch = getchar();
    while(ch != EOF)
    {
        ch = tolower(ch);
        if(j==-1 || ch ==patstr[j])
        {
            if(j == len-1)
            {
                ans++;
                j = 0;
                ch = getchar();
            }
            else
            {
                ch = getchar();
                j++;
            }
        }
        else
            j = nex[j];
    }
}
int main()
{
    strcpy(patstr,"doge");
    Kmp();
    printf("%d\n",ans);
    return 0;
}
