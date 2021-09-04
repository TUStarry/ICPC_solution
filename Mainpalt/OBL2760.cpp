#include<iostream>
using namespace std;
int n;
int mp[105][105];
int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=i;j++)
        cin >> mp[i][j];
    for(int i=n-1;i>=1;i--)
    for(int j=1;j<=i;j++)
        mp[i][j] += max(mp[i+1][j], mp[i+1][j+1]);
    cout<<mp[1][1];
    return 0;
}