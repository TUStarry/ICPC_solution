#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 3333;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, tot;
struct Node{
    int x, y;
};
bool check(int x, int y)
{
    if(0<=x && 0<=y && x<m&&y<n) return true;
    else return false;
}
void bfs(int x, int y)
{
    queue<Node>q;
    q.push({x, y});
    vis[x][y] = true;
    tot++;
    while(q.size())
    {
        Node nownode = q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int xx = nownode.x + dx[i];
            int yy = nownode.y + dy[i];
            if(check(xx, yy) && !vis[xx][yy] && mp[xx][yy]!='#')
            {
                vis[xx][yy] = true;
                tot++;
                q.push({xx, yy});
            }
        }
    }
}
int main()
{
    while(scanf("%d%d", &n,&m) != EOF)
    {
        if(n==0&&m==0) break;
        tot = 0;
        for(int i=0;i<m;i++)
            scanf("%s",mp[i]);
        int x,y;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(mp[i][j] == '@')
                    x = i, y = j;
                vis[i][j] = false;                
            }
        bfs(x, y);
        cout<< tot<<endl;
    }
    return 0;
}
/*
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 33;
char mp[maxn][maxn];
int dfs(int x, int y)
{
    if (mp[x][y] != '#')
    {
        mp[x][y] = '#';
        return 1+dfs(x-1,y)+dfs(x+1,y)+dfs(x,y-1)+dfs(x,y+1);    
    }
    return 0;
}
int main()
{
    int n, m, x, y, ans;
    while (scanf("%d%d",&n,&m) != EOF)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                mp[i][j] = '#';
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                cin>>mp[i][j];
                if (mp[i][j] == '@') {
                    x=i; y=j;    
                }
            }
        }
        ans = dfs(x,y);
        cout<<ans<<endl;
    }
    return 0;
}
*/