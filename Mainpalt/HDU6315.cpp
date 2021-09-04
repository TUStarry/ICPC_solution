/*
HDU - 6315
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#define lson p*2
#define rson p*2+1
using namespace std;
inline int read(){
	int fu = 1, num = 0;
	char ch = getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fu=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') {num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
const int MAXN = 1e5+99;
int b[MAXN];
struct SegmentTree{
	int l, r;
	int minb, maxa;
	int lazy, sum;
}t[MAXN*4];
void lazytag(int p){
	if(t[p].lazy){
		t[lson].maxa += t[p].lazy;
		t[rson].maxa += t[p].lazy;
		t[lson].lazy += t[p].lazy;
		t[rson].lazy += t[p].lazy;
		t[p].lazy = 0;
	}
}
void build(int l, int r, int p){
	t[p].l = l, t[p].r = r;
	t[p].sum = 0, t[p].lazy = 0;
	t[p].maxa = 0;
	if(l == r){
		t[p].minb = b[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(l, mid, lson);
	build(mid+1, r, rson);
	t[p].maxa = max(t[lson].maxa, t[rson].maxa);
	t[p].minb = min(t[lson].minb, t[rson].minb);
}
 
void add(int p, int l, int r){
	int ll = t[p].l;
	int rr = t[p].r;
	if(l <= ll && rr <= r){
		t[p].maxa++;
		if(t[p].maxa < t[p].minb)	{
			t[p].lazy++;
			return ;
		}
		if(ll == rr && t[p].maxa >= t[p].minb){
			t[p].sum++;
			t[p].minb += b[ll];
			return ;
		}
	}
	lazytag(p);
	int mid = (ll + rr)>>1;
	if(l <= mid)
		add(lson, l, r);
	if(r > mid)
		add(rson, l, r);
	t[p].maxa = max(t[lson].maxa, t[rson].maxa);
	t[p].sum = t[lson].sum + t[rson].sum;
	t[p].minb = min(t[lson].minb, t[rson].minb);
}
 
int query(int p, int l, int r){
	int ll = t[p].l, rr = t[p].r;
	if(l <= ll && rr <= r)
		return t[p].sum;
	lazytag(p);
	int mid = (ll + rr)>>1;
	int val = 0;
	if(l <= mid)
		val += query(lson, l, r);
	if(r > mid)
		val += query(rson, l, r);
	return val;
}
int main(){
	int n, m;
	while(scanf("%d %d", &n, &m) != EOF){
		for(int i = 1; i <= n; i++)
			b[i] = read();
		build(1, n, 1);
		char ch[6];
		int l, r;
		while(m--)	{
			scanf("%s %d %d", ch, &l, &r);
			if(strcmp(ch, "add") == 0)
				add(1, l, r);
			else
				printf("%d\n",query(1, l, r)); 			
		}
	}
	return 0;
}
