// 题意为，每个Hero有DPS和HP两个属性，每个时刻都受到HP>0的敌人的攻击，而自己每个时刻只能攻击一个敌人，使其HP减一。问自己打败所有敌人消耗最小的HP量。
// 贪心策略：需要首先消灭HP小且DPS大的敌人，因此我们按Hero的 DPS/HP 值从大到小排序，依次消灭。
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 24;
struct Node{
	int DPS;
	int HP;
	int stime;
	double c;
}a[MAXN];
bool cmp(Node x, Node y) {
	return x.c > y.c;
}
int main() 
{
	int n;
	while(cin>>n) 
    {
		for(int i=0; i<n; i++) {
			cin>>a[i].DPS>>a[i].HP;
			a[i].c = a[i].DPS * 1.0 / a[i].HP;
		}
		sort(a, a+n, cmp);
		for(int i=0; i<n; i++) {
			a[i].stime = a[i-1].stime + a[i].HP;
		}
		int ans = 0;
		for(int i=0; i<n; i++) {
			ans += a[i].stime * a[i].DPS;
		}
		cout<<ans<<endl;
	}
	return 0;
}
