/*
HDU - 5775
���ÿһ�����ܵ������������ҵ�λ�ò�
��ð�������Ǵ�С����ģ��������ƣ��������ơ�
���ÿһ�����ұ��ж���С�����������������ڵ�λ�ü����ܵ��������λ��
��ߵĻ����Ϳ����ڵ�λ�ú�������Ĵ�С��˭С������
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
const int maxn = 100010 ;
int bit[maxn], a[maxn], ans[maxn], n;
int lowbit(int x){
	return x&(-x);
}

void add(int x, int k){
	for(;x<=n;x+=lowbit(x))
		bit[x] += k;
}
int ask(int x){
    int ans = 0;
    for(;x;x-=lowbit(x))
        ans += bit[x];
    return ans;
}

int main()
{
    int t = read(), total = 1;

    while(t--){
        memset(bit,0,sizeof(bit));
        n = read();
        for(int i=1;i<=n;i++)
            a[i] = read();
        for(int i=n;i>=1;i--) {
            int l = min(i,a[i]);
            int r = i + ask(a[i]);
            add(a[i],1);
            ans[a[i]] = r - l;
        }
        printf("Case #%d:",total++);
        for(int i=1;i<=n;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}

