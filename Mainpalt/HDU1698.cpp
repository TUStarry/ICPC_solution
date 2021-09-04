#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
inline int read()
{
    int fu = 1, num = 0;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num*10)+(ch-'0');ch=getchar();}
    return num*fu;
}
const int maxn = 1e5 + 5;
struct Segmenttree{
    int l, r;
    int val, lazy;
}t[maxn*4];
void Build(int p, int l, int r){
    t[p].r = r; t[p].l = l;
    if(l == r){
        t[p].val = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    Build(ls, l, mid);
    Build(rs, mid+1, r);
    t[p].val = t[ls].val + t[rs].val;
}
void pushdown(int p){
    if(t[p].lazy){
        t[ls].val = t[p].lazy * (t[ls].r - t[ls].l + 1);
        t[rs].val = t[p].lazy * (t[rs].r - t[rs].l + 1);
        t[ls].lazy = t[p].lazy;
        t[rs].lazy = t[p].lazy;
        t[p].lazy = 0;
    }
}
void Updata(int p,int x, int y, int val){
    if(x==t[p].l && t[p].r==y){
        t[p].val = val*(t[p].r - t[p].l + 1);
        t[p].lazy = val;
        return;
    }
    pushdown(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if(y <= mid) Updata(ls, x, y, val);
    else if (mid < x) Updata(rs, x, y, val);
    else{
        Updata(ls,x,mid,val);
        Updata(rs,mid+1,y,val);
    }
    t[p].val = t[ls].val + t[rs].val;
}
void fd(int p)
{
    if(t[p].r == t[p].l){
        cout << t[p].l << " : " << t[p].val<<endl;
        return;
    }
    fd(ls);
    fd(rs);
}
int main()
{
    int T = read();
    for(int i=1;i<=T;i++)
    {
        int n = read();
        Build(1, 1, n);
        int q = read();
        while(q--)
        {
            int x = read(), y = read(), op = read();
            Updata(1,x, y,op);
        }
        printf("Case %d: The total value of the hook is %d.\n",i, t[1].val);
        //fd(1);
        for(int i=0;i<n*4;i++)
            t[i].l = t[i].lazy = t[i].r = t[i].val = 0;
        
    }

    return 0;
}