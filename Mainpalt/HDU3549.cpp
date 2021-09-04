#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int M = 5005*2;
int head[M], to[M], nxt[M], d[M], now[M]/*当前弧优化*/;
ll val[M], flow, maxflow;
int tot = 1, n, m, s, t;
void addE(int u, int v, ll w){
    to[++tot] = v, val[tot] = w, nxt[tot] = head[u], head[u] = tot;
    to[++tot] = u, val[tot] = 0, nxt[tot] = head[v], head[v] = tot; 
}
bool bfs()//在残量网络上构造分层图，返回是否搜索到了汇点
{
    memset(d,0,sizeof(d));//初始化分层
    queue<int> q;
    q.push(s);
    d[s] = 1; // 源点是第一层
    now[s] = head[s];//当前弧优化
    while(q.size())
    {
        int x = q.front();q.pop();
        for(int i=head[x]; i; i=nxt[i])
        {
            int p = to[i];
            if(val[i] && !d[p])//当前的剩余容量不为0 && 该节点是没有分层的，也就是新的节点
            {
                q.push(p);
                now[p] = head[p];//继承head的信息
                d[p] = d[x] + 1;//更新分层图
                if (p == t) return true;
            }
        }
    }
    return false;
}
int dfs(int u, ll flow)//先BFS分层，再DFS寻找增广路, 找一条链 S -> T
{//flow是u收到的流量，不一定可以全部都用掉
    if(u == t) return flow;
    ll rest = flow, k, i;//k是v真正输出到汇点的流量
    for(i=now[u];i && rest;i=nxt[i])
    {
        if(val[i] && d[to[i]] == d[u]+1)//仅允许流向下一层
        {
            k = dfs(to[i], min(rest, val[i]));//受到一路上最小流量的限制
            if(!k) d[to[i]] = 0;//剪枝，去掉增广完毕的点
            val[i] -= k;
            val[i ^ 1] += k;
            rest -= k;
        }        
    }
    now[u] = i;//当前弧优化，避免重复遍历从u出发不可扩展的边
    return flow - rest;
}
void dinic()
{
    ll flow = 0;
    while(bfs())//BFS分层
        while(flow = dfs(s, 1e18))//DFS寻找增广路
            maxflow += flow;    
}
void init()
{
    for(int i=1;i<=tot;i++)
        head[i] = to[i] = nxt[i] = d[i] = now[i] = 0;
}
int main()
{
    int tt;
    cin >> tt;
    int cur = 1;
    while(tt--)
    {
        scanf("%d%d", &n ,&m);
        s = 1; 
        t = n;
        init();tot = 1;maxflow = 0;
        while(m--)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addE(u, v, w);
        }
        dinic();
        printf("Case %d: ", cur++);
        cout << maxflow << endl; 
    }

    return 0;
}
