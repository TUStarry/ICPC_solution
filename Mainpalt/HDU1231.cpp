#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = (1 << 29);
int dp[10005], n;
int main()
{
    while (scanf("%d", &n), n)
    {
        int flag = 1, st, ed, ans = -maxn;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &dp[i]);
            if (flag && dp[i] >= 0)
                flag = 0;
        }
        if (flag)
        {
            ans = 0;
            st = 1;
            ed = n;
        }
        else
        {
            int sum = 0;
            st = ed = 1;
            for (int i = 1, j = 1; i <= n; i++)
            {
                sum += dp[i];
                if (sum > ans)
                {
                    st = j;
                    ed = i;
                    ans = sum;
                }
                if (sum < 0)
                {
                    sum = 0;
                    j = i + 1;
                }
            }
        }
        printf("%d %d %d\n", ans, dp[st], dp[ed]);
    }
    return 0;
}