/*
HDU - 1754
/ 
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
const int SIZE = 200020;
int n, m;
int arr[SIZE];
struct SegmentTree{
	int l, r;
	int data;
}t[SIZE * 4 + 2]; //struct����洢�߶���

void Build(int p,int l, int r){
	t[p].l = l, t[p].r = r; //�ڵ�p�������䡾left��right��
	if (l == r){					  //Ҷ�ڵ�
		t[p].data = arr[l]; 		  //arr������ԭʼ����
		return;
	}
	int mid = (l + r) / 2;		  //�۰�
	Build(lson, l, mid);			  //���ӽڵ㡾left��mid�������p*2
	Build(rson, mid+1, r);		  // ���ӽڵ㡾mid��right�������p*2+1
	t[p].data = max(t[lson].data, t[rson].data); //�������ϴ�����Ϣ
}
void Add(int p, int x, int k){
	if (t[p].l == t[p].r){
		t[p].data = k;
		return;
	}
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid)
		Add(lson, x, k);
	else if (mid < x)
		Add(rson, x, k);
	t[p].data = max(t[lson].data, t[rson].data);
}
int query(int p,int x, int y){

	if(x <= t[p].l && t[p].r <= y)
		return t[p].data;
	int mid = (t[p].l + t[p].r) >> 1;
	int val = 0;
	if (x <= mid)
		val = max(val, query(lson, x, y)) ;
	if(mid < y)
		val = max(val, query(rson, x, y)) ;
	return val;
}
int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		memset(t, 0, sizeof (t));
		for(int i=1;i<=n;i++)
            arr[i] = read();
		Build(1, 1, n);
		char ch;

        while(m--){
            scanf("%c",&ch);
            int x = read(), y = read();
            if (ch == 'Q')
                printf("%d\n",query(1, x, y));
            else
                Add(1, x, y);
        }
    }
    return 0;
}

