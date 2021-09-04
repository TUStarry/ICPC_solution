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
const int maxn = 50050;
int a[maxn];
struct SegmentTree{
	int l, r;
	int dat, lazy;
}t[maxn*4 + 2];
void Build(int p,int l,int r){
	t[p].l = l, t[p].r = r;
	if (l == r){
		t[p].dat = a[l];
		return;
	}
	int mid = (l + r) / 2;
	Build(lson, l, mid);
	Build(rson, mid+1, r);
	t[p].dat = t[lson].dat + t[rson].dat;
}
void lazytag(int p){
	if(t[p].lazy){
		t[lson].dat += t[p].lazy * (t[lson].r - t[lson].l + 1);
		t[rson].dat += t[p].lazy * (t[rson].r - t[rson].l + 1);
		t[lson].lazy += t[p].lazy;
		t[rson].lazy += t[p].lazy;
		t[p].lazy = 0;
	}
}
void Add(int p, int x, int k){
	if (t[p].l == t[p].r){
		t[p].dat += k;
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid)
		Add(lson, x, k);
	else if (mid < x)
		Add(rson, x, k);
	t[p].dat = t[lson].dat + t[rson].dat;
}
int query(int p,int x, int y){
	if(x <= t[p].l && t[p].r <= y)
		return t[p].dat;
	int mid = (t[p].l + t[p].r) >> 1;
	int val = 0;
	if (x <= mid)
		val += query(lson, x, y);
	if(mid < y)
		val += query(rson, x, y);
	return val;
}
int main(){
	int T = read(), total = 1;
	while(T--){
		printf("Case %d:\n",total++);
		int n = read();
		for(int i=1;i<=n;i++)
			a[i] = read();
		Build(1,1,n);
		char ch[6];
		while(~scanf("%s", ch)){
			if (ch[0] == 'E')
				break;
			else{
				int x = read(), k = read();
				if (ch[0] == 'A')
					Add(1, x, k);
				else if (ch[0] == 'S')
					Add(1, x, -k);
				else if (ch[0] == 'Q')
					printf("%d\n",query(1, x, k));
			}
		}
	}
	return 0;
}
