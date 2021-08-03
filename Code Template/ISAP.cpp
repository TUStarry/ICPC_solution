#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 5005*2;
int tot = 1, head[M], cur[M], to[M], nxt[M], dep[M], gap[M];
ll val[M];
int n, m, s, t;
void addE(int u, int v, ll w){
    to[++tot] = v, val[tot] = w, nxt[tot] = head[u], head[u] = tot;
    to[++tot] = u, val[tot] = 0, nxt[tot] = head[v], head[v] = tot; 
}
void bfs()//倒着搜索
{
    queue<int> q; 
    q.push(t);//汇点t点入栈 
    for(int i=1;i<=tot;i++) dep[i] = -1;//把深度变为-1(0会导致gap崩坏) 
    for(int i=1;i<=tot;i++) gap[i] = 0;
    dep[t] = 0; //汇点深度为0 
    gap[0] = 1;//深度为0的点有1个 
    while (!q.empty())
    {
        int front = q.front(); 
        q.pop();
        for (int i = head[front]; i != 0; i = nxt[i])
        {
            if (val[i] == 0 && dep[to[i]] == -1)//dep[to[i]]==-1相当于to[i]点没有搜索过 
            {
                dep[to[i]] = dep[front] + 1;
                ++(gap[dep[to[i]]]);
                q.push(to[i]);
            }
        }//直到所有点都被遍历过 
    }
    return;
}//从t到s跑一遍bfs，标记深度

ll dfs(int p = s, ll flow = 1e18)
{
    if (p == t) return flow;
    ll used = 0;
    for (int i = cur[p]; i != 0; i = nxt[i])
    {
        cur[p] = i;
        ll  v = to[i];
        if (dep[v] + 1 == dep[p] && val[i] > 0)//注意这里的条件
        {//如果这条边的残量大于0,且没有断层
            int k = dfs(v, min(val[i], flow - used));
            used += k;
            val[i] -= k;
            val[i ^ 1] += k;
            if (used == flow) return flow;
        }
    }
    //如果已经到了这里，说明该点出去的所有点都已经流过了
    //并且从前面点传过来的流量还有剩余
    //则此时，要对该点更改dep
    //使得该点与该点出去的点分隔开
    if (--gap[dep[p]] == 0) dep[s] = n;//出现断层，无法到达t了
    ++dep[p];//层++ 
    ++gap[dep[p]];//层数对应个数++
    return used;
}

ll isap()
{
    bfs();//一次BFS构建分层图
    ll max_flow = 0;
    while (dep[s] < n)
    {
        for(int i=1;i<=tot;i++) cur[i] = head[i];
        max_flow += dfs();
    }
    return max_flow;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while(m--)
    {
        int u, v; ll w;
        scanf("%d%d%lld", &u, &v, &w);
        addE(u, v, w);
    }
    printf("%lld", isap());
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