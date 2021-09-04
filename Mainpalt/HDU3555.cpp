#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 500005;
int a[20];
ll dp[20][2];

ll dfs(int cur, int st,  int lim)
{
	if (cur < 0)return 1;
	if (~dp[cur][st] && !lim)return dp[cur][st];
	ll rest = 0;
	int temp = lim ? a[cur] : 9;
	for (int i = 0; i <= temp; i++)
	{
		if ((st && i == 9) )continue;
		rest += dfs(cur - 1, i==4, lim && i == a[cur]);
	}
	if (!lim)
		dp[cur][st] = rest;
	return rest;
}

ll solve(ll num)
{
	if (num < 0)return 0;
	int len;
	for (len = 0; num; num /= 10) a[len++] = num % 10;
	return dfs(len - 1, 0, 1);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	ll  m;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> m;
		ll r = m - (solve(m) - 1);
		
		cout << r  << endl;
	}
}