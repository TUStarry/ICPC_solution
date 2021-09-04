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
	for(int i=1;i<=m;i++)
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
	int T;
    scanf("%d", &T);
	while(T--)
	{
		for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                mp[i][j] = 0;
        scanf("%d%d",&n, &m);
        for(int i=1;i<=n;i++)
        { 
        	int t;
            scanf("%d",&t);
            while(t--)
            {
                int x; 
                scanf("%d",&x);
            	mp[i][x] = 1;
        	}
        }
        int tot=0;
		for(int i=0;i<maxn;i++) match[i] = 0;
		for(int i=1;i<=n;i++)
		{
			for(int i=0;i<maxn;i++) vis[i] = 0;
			if(dfs(i))tot++;
		}
		if(tot==n)
        printf("YES\n");
        else printf("NO\n");
	}
	return 0;
}