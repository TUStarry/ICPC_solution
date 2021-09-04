#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 3000;
int n, k;
int mp[maxn][maxn];
int vis[maxn][maxn];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool check(int x, int y){
    if(x>=1 && x<=n && y>=1 && y<=n) return true;
    else return false;
}
int dfs(int x, int y)
{
	if (vis[x][y])	return vis[x][y];
	int sum = 0;      
	for(int i=0;i<4;i++)
        for(int j=1;j<=k;j++) 
        {
            int xx = x + j * dx[i];//只能水平跑！！！！
            int yy = y + j * dy[i];
            if(check(xx, yy) == false) break;
            else if(mp[xx][yy] > mp[x][y]) 
                sum = max(sum, dfs(xx,yy));            
        }
    vis[x][y] = sum + mp[x][y];
	return vis[x][y]; 
}
int main()
{
    while(scanf("%d%d", &n, &k) != EOF)
    {
        if(n == -1 && k == -1) break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d", &mp[i][j]);
                vis[i][j] = 0;
            }
        cout<<dfs(1, 1)<<endl;  
    }
    return 0;
}