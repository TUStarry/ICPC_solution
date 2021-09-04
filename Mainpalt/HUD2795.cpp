#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct SegmentTree{
    int l, r;
    int size;
}tr[800005];
int h,w,n,ans,ww;

inline int read()
{
    int fu = 1, num = 0;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fu=-1;ch=getchar();}
    while('0'<=ch&&ch<='9'){num=(num*10)+(ch-'0');ch=getchar();}
    return num*fu;
}

void Build(int p, int l, int r)
{
    tr[p].l = l;
    tr[p].r = r; 
    tr[p].size = w;
    if(l == r) return;
    int mid = (l + r) >> 1;
    Build(p<<1, l, mid);
    Build(p<<1|1, mid+1, r);    
}

void Updata(int p)
{
	if (tr[p].l == tr[p].r)
	{
		tr[p].size -= ww;
        //cout<<tr[p].l<<endl;
		printf("%d\n",tr[p].l);
		return;
	}	
	
	if (tr[p << 1].size >= ww) Updata(p << 1);
	else Updata(p << 1|1);
	if (tr[p << 1].size >= tr[p << 1|1].size)  tr[p].size = tr[p << 1].size;
	else  tr[p].size = tr[p << 1|1].size;
}

int main()
{
	while (~scanf("%d%d%d",&h,&w,&n))
	{
		if (h > n) h = n;
		Build(1,1,h);
		for (int i = 1; i <= n; i++)
		{
			ww = read();
			if (tr[1].size >= ww) Updata(1);
			else printf("-1\n");
		}
	}
	return 0;
}