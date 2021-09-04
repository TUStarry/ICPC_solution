#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 5e5 + 5;
struct Tire
{
    int nxt[maxn][26], cnt;
    bool vis[maxn];
    void init()
    {
        memset(nxt, 0, sizeof(nxt));
        memset(vis, false, sizeof(vis));
        cnt = 1;
    }
    void insert(const string &s)
    { // 插入字符串
        int cur = 1;
        for (auto c : s)
        {
            if (!nxt[cur][c - 'a'])
                nxt[cur][c - 'a'] = ++cnt;
            cur = nxt[cur][c - 'a'];
        }
    }
    int find_prefix(const string &s)
    {
        int cur = 1;
        for (auto c : s)
        {
            if (!nxt[cur][c - 'a'])
                return 0;
            cur = nxt[cur][c - 'a'];
        }
        if (vis[cur] == true)
            return 1;
        vis[cur] = true;
        return 2;
    }
} tr;
string str1;
int main()
{
    int t;
    scanf("%d", &t);
    tr.init();
    while (t--)
    {
        cin >> str1;
        tr.insert(str1);
    }
    scanf("%d", &t);
    while (t--)
    {
        cin >> str1;
        int ans = tr.find_prefix(str1);
        if (ans == 1)
            printf("REPEAT\n");
        else if (ans == 2)
            printf("OK\n");
        else if (ans == 0)
            printf("WRONG\n");
    }
    return 0;
}