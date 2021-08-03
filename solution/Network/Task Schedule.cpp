// Difficulty: 2
// Title: Task Schedule
// Score: HDU - 3572
// 最大流 + 判断满流
// 从模板题进阶的必写题目，很经典的任务分配
// 建图步骤如下：
// 1.设置一个超级源点sp和一个超级汇点tp
// 2.我们将n个任务分别与源点sp链接，第i个任务的流量就是pi
// 3.将任务和时间链接，时间就是一天一个节点，流量为1，这是因为一个任务一天只能由一个机器完成
// 4.最后将时间和汇点tp相链接，流量大小为m，代表一天只能完成m个任务
// 最后跑一遍Dinic或者ISAP就可以了
// 没有写弧优化
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=250050;
int head[maxn], deep[maxn], vis[maxn];
struct Edge{
    int to, nxt;
    ll val;
}edge[maxn];
int n, m, tot, sp, tp;
void addE(int u, int v, ll w){
    edge[tot].to = v; edge[tot].val = w; edge[tot].nxt = head[u]; head[u] = tot++;
    edge[tot].to = u; edge[tot].val = 0; edge[tot].nxt = head[v]; head[v] = tot++;
}
bool bfs()
{
    queue <int> q;
    memset(deep,0,sizeof(deep));
    deep[sp] = 1;
    q.push(sp);
    while(!q.empty())
    {
        int nownode = q.front(); q.pop();
        for(int i=head[nownode];i!=-1;i=edge[i].nxt)
        {
            int to = edge[i].to;
            if(deep[to] == 0 && edge[i].val > 0)
            {
                deep[to] = deep[nownode]+1;
                q.push(to);
                if(to == tp) return true;
            }
        }
    }
    return false;
}
int dfs(int u,ll b)
{
    if(u == tp) return b;
    int rest = 0;
    for(int i=head[u];i!=-1 && rest<b;i=edge[i].nxt)
    {
        int to=edge[i].to;
        if(edge[i].val>0 && deep[to]==deep[u]+1)
        {
            ll k = dfs(to,min(edge[i].val,(ll)b-rest));
            rest += k;
            edge[i].val -= k;
            edge[i ^ 1].val += k;
        }
    }
    if(!rest) deep[u]=0;
    return rest;
} 
ll dinic()
{
    ll maxflow=0, flow;
    while(bfs())
        while(flow = dfs(sp, 1e18))
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