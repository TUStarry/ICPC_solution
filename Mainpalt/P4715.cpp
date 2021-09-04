#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1024;
struct BinaryTree{
    int data;
    int l, r;
    int id;
}t[maxn*4];
int a[maxn];
void Build(int p,int l,int r)
{
    t[p].l = l, t[p].r = r;
    if(l == r){t[p].data = a[l];t[p].id = l;return;}
    int mid = (l + r) / 2;
    Build(p*2,l,mid);
    Build(p*2+1,mid+1,r);
    if(t[p*2].data > t[p*2+1].data){
        t[p].data = t[p*2].data;
        t[p].id = t[p*2].id;
    }
    else{
        t[p].data = t[p*2+1].data;
        t[p].id = t[p*2+1].id;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    n = (1<<n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    Build(1,1,n);
    if(t[2].data > t[3].data) cout<<t[3].id<<endl;
    else cout<<t[2].id<<endl;
    return 0;
}

