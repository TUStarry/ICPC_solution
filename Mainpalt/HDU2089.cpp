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
		if ((st && i == 2)||(i==4) )continue;
		rest += dfs(cur - 1, i==6, lim && i == a[cur]);
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
	int n, m;
	while (cin>>n>>m)
	{
		if (n == 0 && m == 0)break;
		int r = (solve(m) );
		int l = solve(n-1) ;
		int sum = m + 1 - n;
		cout << r-l << endl;
	}
    return 0;
}