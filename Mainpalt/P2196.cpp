#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 25;
int arr[maxn];
int dp[25];
int pre[25];
int mp[maxn][maxn];
void print(int cur){
    if(pre[cur] == 0){
        cout<<cur;
        return;
    }
    print(pre[cur]);
    cout<<' '<<cur;
}
int main()
{
    int n, cur;
    scanf("%d", &n);
    memset(pre, 0, sizeof(pre));
    for(int i=1;i<=n;i++)
        scanf("%d", &arr[i]);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
                scanf("%d", &mp[i][j]); 
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[j][i])
            {
                dp[i] = max(dp[i], dp[j]); 
                if(dp[i] == dp[j]) pre[i] = j;
            }
        }
        dp[i] += arr[i];
        ans = max(ans, dp[i]);
        if(ans == dp[i]) cur = i;
    } 
    print(cur);
    cout << endl << ans << endl;
    return 0;
}