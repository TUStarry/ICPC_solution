#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long int ll;
inline ll read(){
    ll num = 0, fu = 1;
    char ch = getchar();
    while(ch<'0'||'9'<ch){if(ch=='-') fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
    return num;
}
ll power(ll a, ll b, ll m){
	ll ans = 1 % m;
    for(;b;b>>=1){
        if (b&1)
            ans = ans * a % m;
        a = a * a % m;
    }
	return ans;
}
int main(){
    int t = read();
	while(t--){
		ll m = read(), h = read(), ans = 0;
		while(h--){
			ll a = read(), b = read();
			ans += power(a,b,m) % m;
		}
		printf("%lld\n",ans%m);
	}
    return 0;
}
