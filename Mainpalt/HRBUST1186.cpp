#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5 + 9;
const int inf=0x3f3f3f3f;
int dp[maxn];
int arr[maxn];
int main()
{
	int l, s, t, n;
	while(scanf("%d%d%d%d", &l, &s, &t, &n) != EOF)
	{
		int len = l + t;
		for(int i=0;i<=l;i++) dp[i] = inf;
		for(int i=1;i<=t;i++) dp[i + l] = 0;
		for(int i=0;i<=l;i++) arr[i] = 0;
		for(int i=0;i<n;i++)
		{
			int tt;
			scanf("%d", &tt);
			arr[tt]++;
		}
		for(int i=l; i >= 0; i--)
			for(int j=s; j<=t; j++)
			{
				dp[i] = min(dp[i], dp[i+j]);
				if (arr[i])
					dp[i] += arr[i];
			}
		printf("%d\n", dp[0]);
	}
}