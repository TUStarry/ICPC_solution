#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 2e5;
const int inf = 0x3f3f3f3f;
int dp[maxn];
int arr[maxn];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0;i<n;i++) scanf("%d", &arr[i]);
	for(int i=0;i<=m;i++) dp[i] = inf;
    dp[0] = 0;
	for (int i=0;i<n;i++) dp[arr[i]] = 1;
	for (int i=1;i<=m;i++)
		for (int j=0;j<n;j++)
			dp[i + arr[j]] = min(dp[i + arr[j]], dp[i] + 1);
	if (dp[m] == inf) dp[m] = -1;
	printf("%d\n", dp[m]);
}