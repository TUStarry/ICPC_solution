#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010, E = 200010;
int n, m, s, t;
ll head[N];
ll to[E], nxt[E], val[E];
int tot = 1;//反向边操作，起始为1
bool vis[N];//限制增广路不要重复走点，否则很容易爆栈 
void addE(int u, int v, ll w) {
	to[++tot] = v, val[tot] = w;//真实数据
	nxt[tot] = head[u], head[u] = tot; //在表头x处插入
}
ll dfs(int u, ll flow) 
{//注意，在走到汇点之前，无法得知这次的流量到底有多少 
	if (u == t)//走到汇点才return一个实实在在的流量 
		return flow;
	vis[u] = true;
	for (int i = head[u]; i; i = nxt[i]) 
    {
		int p = to[i];
		if (val[i] == 0 || vis[p])//无残量，走了也没用 
			continue;
		int res = 0;
		if ((res = dfs(p, min(flow, val[i]))) > 0) 
        {//顺着流过去，要受一路上最小容量的限制
			val[i] -= res;//此边残余容量减小
			val[i ^ 1] += res;//以后可以顺着反向边收回这些容量，前提是对方有人了 
			return res;
		}
	}
	return 0;//我与终点根本不连通
}
int main() 
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	while(m--)
    {
		int u, v; ll w;
		scanf("%d%d%lld", &u, &v, &w);
		addE(u, v, w);
		addE(v, u, 0);//反向边初始化为0
	}
	ll res = 0, maxflow = 0;
	while (memset(vis, 0, sizeof(vis)) && (res = dfs(s, 1e18/*水库无限*/)) > 0)
		maxflow += res;//进行若干回合的增广
	printf("%lld\n", maxflow);
	return 0;
}
/*
4 5 4 3
4 2 30
4 3 20
2 3 20
2 1 30
1 3 40
*/