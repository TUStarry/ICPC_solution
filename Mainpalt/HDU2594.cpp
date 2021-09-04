#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e7+5;
char list1[maxn], list2[maxn];
int nxt[maxn];
void getnxt(){
    int i = 1, j = 0, len = strlen(list1);
    nxt[0] = -1;
    while(i < len) {
        if(j==-1||list1[i]==list1[j])  nxt[++i] = ++j;
        else j = nxt[j];
    }
}
 
int main ()
{
    while(~scanf("%s%s",list1,list2))
    {
        int len1=strlen(list1),len2=strlen(list2);
        strcat(list1,list2);
        getnxt();
        int ans = nxt[strlen(list1)];
        while(ans>len2||ans>len1) ans = nxt[ans];
        if(ans==0) printf("0\n");
        else
        {
            list1[ans] = 0;
            printf("%s %d\n",list1,ans);
        }
    }
    return 0;
}