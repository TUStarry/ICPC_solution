#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
int a[101][101],d[101];
bool v[101];
void dijkstra(){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[1] = 0;
    for(int i=1;i<=n;i++)
    {
        int x = 0;
        for(int j=1;j<=n;j++) 
            if(!v[j] && (x==0 || d[x]>d[j])) x = j;
        v[x] = 1;
        for(int j=1;j<=n;j++)
            d[j] = min(d[j], d[x]+a[x][j]);
    }
}
int main(){
    while(~scanf("%d%d",&n,&m))
    {
        if (n==0 && m==0) break;
        memset(a,0x3f,sizeof(a));
        for(int i=1;i<=n;i++)
            a[i][i] = 0;
        for(int i=1;i<=m;i++){
            int x, y, z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y] = min(a[x][y], z);
            a[y][x] = min(a[y][x], z);
        }
        dijkstra();
        printf("%d\n",d[n]);
    }
    return 0;
}