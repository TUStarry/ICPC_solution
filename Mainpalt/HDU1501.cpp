#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int dp[maxn][maxn], cases = 1;;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cout<<"Data set "<<cases++<<": ";
        int len1 = s1.length(), len2 = s2.length(), len = s3.length();
        if(len1 + len2 != len)
        {
            cout<<"no"<<endl;
            continue;
        }
        for(int i=0;i<maxn;i++)
            for(int j=0;j<maxn;j++)
                dp[i][j] = 0;
        dp[0][0] = 1;
        for(int i=0;i<=len1;i++)
            for(int j=0;j<=len2;j++)
            {
                if(i==0 && j==0) continue;
                if(i != 0 && dp[i-1][j] == 1 && s1[i-1] == s3[i+j-1])
                {
                    dp[i][j] = 1;
                    continue;
                }

                if(j != 0 && dp[i][j-1] == 1 && s2[j-1] == s3[i+j-1])
                    dp[i][j] = 1;
            }
        if(dp[len1][len2] == 1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}