#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
struct Node
{
    int vis[26];
    int fail;
    int end;
} ac[maxn];
int cnt = 0;
void insert(string s)
{
    int cur = 0;
    for (auto c : s)
    {
        if(!ac[cur].vis[c - 'a'])   
            ac[cur].vis[c - 'a'] = ++cnt;
        cur = ac[cur].vis[c - 'a'];
    }
    ac[cur].end ++;
}

string str;
int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> str;
            insert(str);
        }
        
        cin >> str;
    }
    return 0;
}