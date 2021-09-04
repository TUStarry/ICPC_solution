#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
struct Node
{
    int fail;
    int vis[26];
    int end;
} ac[maxn];
int cnt = 0;
void insert(string s)
{
    int cur = 0;
    for (auto c : s)
    {
        if (!ac[cur].vis[c - 'a'])
            ac[cur].vis[c - 'a'] = ++cnt;
        cur = ac[cur].vis[c - 'a'];
    }
    ac[cur].end++;
}
void get_fail()
{
    queue<int> q;
    ac[0].fail = 0;
    for (int i = 0; i < 26; i++)
    {
        if (ac[0].vis[i])
        {
            ac[ac[0].vis[i]].fail = 0;
            q.push(ac[0].vis[i]);
        }
    }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (ac[u].vis[i])
            {
                ac[ac[u].vis[i]].fail = ac[ac[u].fail].vis[i];
                q.push(ac[u].vis[i]);
            }
            else
                ac[u].vis[i] = ac[ac[u].fail].vis[i];
        }
    }
}
int ac_query(string s)
{
    int cur = 0, ans = 0;
    for (auto c : s)
    {
        cur = ac[cur].vis[c - 'a'];
        for (int j = cur; j && ac[j].end != -1; j = ac[j].fail)
        {
            ans += ac[j].end;
            ac[j].end = -1;
        }
    }
    return ans;
}
string s;
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        insert(s);
    }
    get_fail();
    cin >> s;
    cout << ac_query(s) << endl;
    return 0;
}