/*


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
typedef long long ll;
inline int read(){
	int fu = 1, num = 0;
	char ch = getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fu=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') {num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
const int maxn =100005;
ll a[maxn], ans = 0;
int n,m;

struct SegmentTree{
    int minn,maxx;
    int lazy;
}t[maxn*4];
unsigned int X,Y,Z;
unsigned int fx(){
    X = X ^ (X << 11);
    X = X ^ (X >> 4);
    X = X ^ (X << 5);
    X = X ^ (X >> 14);
    unsigned int tt = X ^ (Y ^ Z);
    X = Y;
    Y = Z;
    Z = tt;
    return Z;
}
void push_up(int p){
    t[p].maxx = max(t[lson].maxx,t[rson].maxx);
    t[p].minn = min(t[lson].minn,t[rson].minn);
}
void build(int l,int  r,int p){
    t[p].lazy = -1;
    if(l == r){
        t[p].maxx = 0, t[p].minn = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(p);
}
void lazytag(int p){
    if(t[p].lazy){
        t[lson].maxx = max(t[p].lazy,t[lson].maxx);
        t[rson].maxx = max(t[p].lazy,t[rson].maxx);
        t[lson].minn = max(t[p].lazy,t[lson].minn);
        t[rson].minn = max(t[p].lazy,t[rson].minn);
        t[lson].lazy = max(t[p].lazy,t[lson].lazy);
        t[rson].lazy = max(t[p].lazy,t[rson].lazy);
        t[p].lazy = 0;
    }
}
void update(int L,int R,int l,int r,int p,int v){
    if(l == r){
        t[p].minn = max(v,t[p].minn);
        t[p].maxx = max(v,t[p].maxx);
        return ;
    }
    if(L <= l && R >= r){
        if(t[p].maxx <= v){
            t[p].maxx = v;
            t[p].minn = v;
            t[p].lazy = max(t[p].lazy,v);
            return;
        }
        if(t[p].minn >= v) 
			return;
    }
    if(t[p].minn >= v) 
		return;
    lazytag(p);
    int mid = (l +  r) >> 1;
    if(L <= mid) 
		update(L,R,l,mid,lson,v);
    if(R>mid) 
		update(L,R,mid+1,r,rson,v);
    push_up(p);
}
int add(int p, int l,int r,int k){
    if (l == r)
         return t[p].minn;
    int mid = (l + r) >> 1;
    lazytag(p);
    if(k <= mid) 
		return add(lson,l,mid,k);
    else 
		return add(rson,mid+1,r,k);
}
int main(){
    int T = read();
    while(T--){
        ans = 0;
        scanf("%d%d%u%u%u",&n,&m,&X,&Y,&Z);
        build(1,n,1);
        for(int i=1;i<=m;i++){
            int l = fx() % n + 1;
            int r = fx() % n +1 ;
            int v = fx() % (1<<30);
            if(l > r) 
				swap(l,r);
            update(l,r,1,n,1,v);
        }
        for(int i=1;i<=n;i++)
            ans^=1ll*i*add(1,1,n,i);
        printf("%lld\n",ans);
    }
    return 0;
}
