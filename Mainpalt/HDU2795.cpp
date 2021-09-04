#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using  namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
struct Node{
	int l, r;
	int val;
}tr[maxn << 2];
void Bulid(int p, int l, int r, int val){
	tr[p].l = l; 
	tr[p].r = r;
	tr[p].val = val;
	if(l == r) return;
	int mid = (l + r) >> 1;
	Bulid(p*2, l, mid, val);
	Bulid(p*2+1, mid+1, r, val);
}
void modify(int p, int val){
	if(tr[p].l == tr[p].r){
		printf("%d\n", tr[p].l);
		tr[p].val -= val;
		return;
	}
	if(val <= tr[p*2].val) modify(p*2, val);
	else modify(p*2|1, val);
	tr[p].val = tr[p*2].val > tr[p*2+1].val ? tr[p*2].val : tr[p*2+1].val;
}
int main()
{
	int h, w, n, ww;
	while(scanf("%d%d%d", &h, &w, &n) != EOF)
	{
		if(h > n)	h = n;
		Bulid(1, 1, h, w);
		while(n--){
			scanf("%d", &ww);
			if(tr[1].val >= ww) modify(1,ww);
			else printf("-1\n");
		}
	}
	return 0;
}