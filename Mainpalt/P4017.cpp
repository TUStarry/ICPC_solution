#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn = 5005;
const int mod = 80112002;
int n, m;
int mp[maxn][maxn];
int out[maxn], in[maxn];
int f[maxn];
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        while(m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            mp[a][b] = 1;
            in[b]++;
            out[a]++;
        }
        queue<int>q;
        for(int i = 1; i <= n; i++)
            if(in[i] == 0){
                q.push(i);
                f[i] = 1;
            }
        int ans = 0;
        while(q.size())
        {
            int front = q.front();q.pop();
            for(int i = 1; i <= n; i++)
            {
                if(mp[front][i] == 0) continue;
                f[i] += f[front];
                f[i] %= mod;
                in[i]--;
                if(in[i] == 0)
                {
                    if(out[i] == 0)
                    {
                        ans += f[i];
                        ans %= mod;
                        continue;
                    }
                    q.push(i);
                }
            }
        } 
        cout << ans << endl;       
    }
    return 0;
}