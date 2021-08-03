#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, M = 2*5005;//由于有反向边的存在我们要开2倍的边
int head[M];
int to[M], nxt[M], pre[M];// 记录前驱，便于找到最长路的实际方案
ll val[M], incf[M];//incf是增广路上各边最小剩余容量
int tot = 1;
int n, m, s, t;
ll maxflow;
bool vis[N];//限制增广路不要重复走点
void addE(int u, int v, ll w){//两种写法都是可以的
    to[++tot] = v, val[tot] = w, nxt[tot] = head[u], head[u] = tot;//正向边
    //to[++tot] = u, val[tot] = 0, nxt[tot] = head[v], head[v] = tot;//反向边
}
bool bfs()
{
    memset(vis,false,sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = true;
    incf[s] = 1e18;//增广路上各边最小剩余容量
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i])
            if(val[i])
            {
                int v = to[i];
                if(vis[v]) continue;//已经访问过了
                incf[v] = min(incf[x], val[i]);
                pre[v] = i;
                q.push(v);
                vis[v] = true;
                if(v == t) return true;
            }
    }
    return false;
}
void updata()//更新增广路及其反向边的剩余容量
{
    ll x = t;
    while(x != s)
    {
        ll i = pre[x];
        val[i] -= incf[t];
        val[i ^ 1] += incf[t]; //方向边也要更新 xor 1 的技巧
        x = to[i ^ 1];
    }
    maxflow += incf[t];
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    memset(head, 0, sizeof(head));
    while(m--)
    {
        int u, v; ll w;
        scanf("%d%d%lld", &u, &v, &w);
        addE(u, v, w); 
        addE(v, u, 0);
    }
    maxflow = 0;
    while(bfs()) updata();
    printf("%lld\n", maxflow);
    return 0;
}