#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=250050;
int head[maxn], to[maxn], nxt[maxn], deep[maxn], /*now[maxn],*/ vis[maxn]/*当前弧优化*/;
ll val[maxn];
int tot, n, m, sp, tp;
void addE(int u, int v, ll w){
    to[tot] = v, val[tot] = w, nxt[tot] = head[u], head[u] = tot++;
    to[tot] = u, val[tot] = 0, nxt[tot] = head[v], head[v] = tot++; 
}
bool bfs()//在残量网络上构造分层图，返回是否搜索到了汇点
{
    memset(deep,0,sizeof(deep));//初始化分层
    queue<int> q;
    q.push(sp);
    deep[sp] = 1; // 源点是第一层
    //now[sp] = head[sp];//当前弧优化
    while(!q.empty())
    {
        int nownode = q.front(); q.pop();
        for(int i=head[nownode]; i != -1; i=nxt[i])
        {
            int tonode = to[i];
            if(val[i] && !deep[tonode])//当前的剩余容量不为0 && 该节点是没有分层的，也就是新的节点
            {
                //now[p] = head[p];//继承head的信息
                deep[tonode] = deep[nownode] + 1;//更新分层图
                q.push(tonode);
                if (tonode == tp) return true;
            }
        }
    }
    return false;
}
int dfs(int u, ll flow)//先BFS分层，再DFS寻找增广路, 找一条链 S -> T
{//flow是u收到的流量，不一定可以全部都用掉
    if(u == tp) return flow;
    ll rest = 0, i;//k是v真正输出到汇点的流量
    for(i=head[u];i!=-1 && rest < flow; i=nxt[i])
    {
        int tonode = to[i];
        if(val[i] && deep[tonode] == deep[u]+1)//仅允许流向下一层
        {
            ll k = dfs(tonode, min(val[i],flow - rest ));//受到一路上最小流量的限制
            if(!k) deep[tonode] = 0;//剪枝，去掉增广完毕的点
            val[i] -= k;
            val[i ^ 1] += k;
            rest += k;
        }        
    }
    //now[u] = i;//当前弧优化，避免重复遍历从u出发不可扩展的边
    return rest;
}
ll dinic()
{
    ll flow = 0, maxflow = 0;
    while(bfs())//BFS分层
        while(flow = dfs(sp, 1e18))//DFS寻找增广路
            maxflow += flow;
    return maxflow;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int CASE=1;CASE<=T;CASE++)
    {
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));        
        scanf("%d%d",&n,&m);
        tot = 0, sp = 0, tp = n + 500 + 1;//初始化
        int sumday = 0;
        for(int i=1;i<=n;i++)
        {
            int pi, si, ei;
            scanf("%d%d%d",&pi, &si, &ei);
            sumday += pi;
            addE(sp, i, pi);
            for(int j=si;j<=ei;j++)
            {
                addE(i,n+j,1);
                vis[j]=1;
            }
        }
        for(int i=1;i<=500;i++)
            if(vis[i])
                addE(n+i,tp,m);
        printf("Case %d: ",CASE);
        if(sumday == dinic()) printf("Yes\n\n");
        else printf("No\n\n");
    }
    return 0;
}
