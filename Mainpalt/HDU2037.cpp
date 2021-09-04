// 题意为给出n个节目的起始和结束时间，问最多能完整观看的节目数量。
// 贪心策略为：按照节目的结束时间从小到大排序。
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct Node{
	int s, e;
}a[maxn];
bool cmp(Node x, Node y) {
	if(x.e != y.e) return x.e < y.e;
	else return x.s > y.s;
}
int main() 
{
	int n;
	while(cin>>n && n) 
    {
		for(int i=0; i<n; i++) cin>>a[i].s>>a[i].e;
		sort(a, a+n, cmp);
		int ans = 1;
		int tmp = a[0].e;
		for(int i=1; i<n; i++) {
			if(a[i].s >= tmp) 
            {//注意：这里是和tmp比较，而不是和a[i-1].e比较！
				ans++;
				tmp = a[i].e;  
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}