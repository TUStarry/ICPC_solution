// 题目大意：一套牌最大多有M*N张，一共M个人玩，玩N轮。每一轮出牌数值最大的人获胜。给出你被分到的牌，问在N轮中，你最少能赢几轮。（也就是自己稳赢的情况数）
// 简单的说就是，不用管对方有什么牌，我每次从大到小依次出我有的牌，对方都会尽量出比我大的牌来赢我。如果对方没有比我这张牌大的，那他就出一张最小的牌减少损失。
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
const int maxn = 1010;
int a[maxn];
int n, m;
bool cmp(int x, int y) {
	return x > y;
}
int main() 
{
	int x;
	int cases = 1;
	while(cin>>n>>m && n+m) 
    {
		for(int i=0; i<m; i++) cin>>a[i];
		sort(a, a+m, cmp);
		int fail = 0;
		for(int i=0; i<m; i++) 
			if(a[i] < m*n-i-fail) 
				fail++;
		cout<<"Case "<<cases<<": ";
		cases++;
		cout<<m-fail<<endl;
	}
	return 0;
}
