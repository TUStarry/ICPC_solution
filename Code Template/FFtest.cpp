#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int E = 5005*2;
int n, m, s, t;
int head[E], to[E], nxt[E];
ll val[E];
bool vis[E];
int tot = 1;
void addE(int u, int v, ll w){
    to[++tot] = v, val[tot] = w, nxt[tot] = head[u], head[u] = tot;
    to[++tot] = u, val[tot] = 0, nxt[tot] = head[v], head[v] = tot;
}
ll dfs(int u, ll flow)
{
    if(u == t) return flow;
    vis[u] =true;
    for(int i=head[u]; i; i=nxt[i])
    {
        int p = to[i];
        if(vis[p] || val[i] == 0) continue;
        ll res = 0;
        if((res = dfs(p, min(flow, val[i]))) > 0)
        {
            val[i] -= res;
            val[i^1] += res;
            return res;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while(m--){
        int u, v; ll w;
        scanf("%d%d%lld", &u, &v, &w);
        addE(u, v, w);
    }
    ll maxflow = 0, flow = 0;
    while(memset(vis, 0, sizeof(vis)) && (flow = dfs(s, 1e18)) > 0){
        maxflow += flow;
    }
    cout << maxflow;
    return 0;
}