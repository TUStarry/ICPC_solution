#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s, k, ans;
        cin >> s;
        ans = s;
        int len = s.size(), cur = 0;
        for(int i=1; i<len; i++)
        {
            k = s.substr(i,len)+s.substr(0,i);
            if(k < ans)
                ans = k, cur = i;
        }
       cout << cur + 1 << endl;
    }
    return 0;
}

