#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 1510;
int f[N][2];
int head[N],to[N*2],nxt[N*2],tot;
void addE(int u,int v){
	to[tot] = v; nxt[tot] = head[u]; head[u] = tot++;
}
void dfs(int u,int fa){
	f[u][0] = 0;
	f[u][1] = 1;
	for(int i=head[u]; i!=-1; i=nxt[i])
    {
		int tonode = to[i];
		if(tonode == fa) continue;
		dfs(tonode,u);
		f[u][0] += f[tonode][1];
		f[u][1] += min(f[tonode][0],f[tonode][1]);
	}
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
    {
		memset(head,-1,sizeof(head));
		tot = 0;
		for(int i=1;i<=n;i++)
        {
			int k, u, v;
			scanf("%d:(%d)",&u,&k);
			while(k--)
            {
				scanf("%d",&v);
				addE(u,v);
				addE(v,u);
			}
		}
		dfs(0, 0);
		int ans = min(f[0][0],f[0][1]);
		cout<<ans<<endl;
	}
	return 0;
}
