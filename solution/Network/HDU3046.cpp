// Difficulty: 2
// Title: Pleasant sheep and big big wolf
// Score: HDU - 3046
// 网络流最小割基础题，难的是建图
// 这个问题可以转换为最少去掉多少条边可以使图不连通
// 将源点和2链接，容量大小为inf
// 1链接上汇点，容量大小为inf
// 然后图中的相邻的边相连，大小为1
// 之后跑一遍Dinic或者ISAP
// 应该使需要弧优化的
// 初始化不要memset，会炸
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=250050;
ll inf = 1e18;
int head[maxn], to[maxn], nxt[maxn], deep[maxn], /*now[maxn],*/ vis[maxn]/*当前弧优化*/;
ll val[maxn];
int tot, n, m, sp, tp, now[maxn], node;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void init(int _node, int s, int t){
    for(int i=0;i<maxn;i++) head[i] = -1;
    sp = s, tp = t, tot = 0, node = _node;
}
void addE(int u, int v, ll w){
    to[tot] = v, val[tot] = w, nxt[tot] = head[u], head[u] = tot++;
    to[tot] = u, val[tot] = 0, nxt[tot] = head[v], head[v] = tot++; 
}
bool bfs()//在残量网络上构造分层图，返回是否搜索到了汇点
{
    for(int i=0;i<node;i++) deep[i] = 0;//初始化分层
    queue<int> q;
    q.push(sp);
    deep[sp] = 1; // 源点是第一层
    while(!q.empty())
    {
        int nownode = q.front(); q.pop();
        for(int i=head[nownode]; i != -1; i=nxt[i])
        {
            int tonode = to[i];
            if(val[i] && !deep[tonode])//当前的剩余容量不为0 && 该节点是没有分层的，也就是新的节点
            {
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
    for(i=now[u];i!=-1 && rest < flow; i=nxt[i])
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
    
    return rest;
}
ll dinic()
{
    ll flow = 0, maxflow = 0;
    while(bfs()){
        for(int i=0;i<node;i++) now[i] = head[i];
        while(flow = dfs(sp, 1e18))//DFS寻找增广路
            maxflow += flow;
    } 
    return maxflow;
}

int main()
{
    int T = 0, num;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        init(n*m+2, 0, n*m+1);
        for(int i=0;i<n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%d", &num);
                if (num == 1) addE(i*m+j,tp,inf); //连向汇点，大小为inf
                else if (num == 2) addE(sp, i*m+j,inf); //从源点连向该点，大小为inf
                for(int k=0;k<4;k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0 && x<n && y>0 && y<=m)
                        addE(i*m+j,x*m+y,1);
                }
            }
        printf("Case %d:\n%d\n",++T,dinic());

    }
    
    return 0;
}