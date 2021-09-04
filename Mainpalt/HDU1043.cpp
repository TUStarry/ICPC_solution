#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
const int  maxn = 362880+5;
using namespace std;
static const int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
struct Node{
    string path;
    int cantor_hash;
    int pos;
};
Node now, net;
queue<Node>q;
int dt[][4] = {{1,0},{-1,0},{0,1},{0,-1}};
char op[5] = "udlr";
int lis[9], cantor0_9 = 46234;
string path[maxn];
int vis[maxn];
int cantor(int *a)
{
    int ans = 1;
    for (int i=0;i<9;++i)
    {
        int cnt = 0;  
        for (int j = i + 1; j < 9; ++j)
            if (a[j] < a[i]) cnt++;
        ans += fac[9-i-1] * cnt; 
    }
    return ans; 
}
void decantor(int x, int *a)
{
    vector<int> v;  
    for(int i=0; i<9; i++) v.push_back(i);
    for(int i=0; i<9; i++)
    {
        int r = x % fac[9-i-1];
        int t = x / fac[9-i-1];
        x = r;
        sort(v.begin(),v.end());
        a[i]=v[t]; 
        v.erase(v.begin()+t);   
    }
}
void bfs()
{
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<8; i++) lis[i] = i + 1;
    lis[8] = 0;
    now.pos = 8;
    now.cantor_hash = cantor0_9;
    now.path = "";
    path[cantor0_9] = "";
    vis[cantor0_9] = 1;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int tx=now.pos/3+dt[i][0];
            int ty=now.pos%3+dt[i][1];
            if(tx>=0&&ty>=0&&tx<=2&&ty<=2)
            {
                net=now;
                net.pos=tx*3+ty;
                decantor(now.cantor_hash-1,lis);
                swap(lis[now.pos],lis[net.pos]);
                net.cantor_hash=cantor(lis);
                if(!vis[net.cantor_hash])
                {
                    vis[net.cantor_hash]=1;
                    net.path=op[i]+net.path;
                    q.push(net);
                    path[net.cantor_hash]=net.path;
                }
            }
        }
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    bfs();
    char x;
    while(cin >> x)
    {
        if(x == 'x') now.pos = lis[0] = 0;
        else lis[0] = x - '0';
        for(int i=1;i<9;i++)
        {
            cin >> x;
            if(x == 'x') {
                now.pos = i;
                lis[i] = 0;
            }
            else lis[i]=x-'0';
        }
        now.cantor_hash = cantor(lis);
        if(!vis[now.cantor_hash]) cout<<"unsolvable"<<endl;
        else cout<<path[now.cantor_hash]<<endl;
    }
    return 0;
}