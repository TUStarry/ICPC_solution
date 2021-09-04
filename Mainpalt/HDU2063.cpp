#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1050;
int mp[maxn][maxn];
int match[maxn],vis[maxn],k,n,m;
bool dfs(int u)
{
	for(int i=1;i<=n;i++)
		if(vis[i]==0 && mp[u][i]==1)
		{
			vis[i] = 1;
			if(match[i]==0||dfs(match[i]))
			{
				match[i]=u;
				return true;
			}
		}
	return false;
}
int main()
{
	while(scanf("%d",&k) != EOF && k)
	{
		scanf("%d%d",&m, &n);
		int x, y;
		for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                mp[i][j] = 0;
		while(k--)
		{
			scanf("%d%d",&x, &y);
			mp[x][y] = 1;
		}
		int tot=0;
		for(int i=0;i<maxn;i++) match[i] = 0;
		for(int i=1;i<=m;i++)
		{
			for(int i=0;i<maxn;i++) vis[i] = 0;
			if(dfs(i))
                tot++;
		}
		printf("%d\n",tot);
	}
	return 0;
}