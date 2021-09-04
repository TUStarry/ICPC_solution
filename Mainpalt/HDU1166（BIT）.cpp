/*
HDU - 1166
树状数组（BIT）版
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
int lowbit(int x){
	return x&(-x);
}
const int maxn = 90050;
int a[2*maxn], n;
void add(int x, int k){
	for(;x<=n;x+=lowbit(x))
		a[x] += k;
}
int ask(int x){
    int ans = 0;
    for(;x;x-=lowbit(x))
        ans += a[x];
    return ans;
}
int main(){
	int T = read(), total = 1;
	while(T--){
		printf("Case %d:\n",total++);
		n = read();
		memset(a, 0, sizeof (a));//忘了这句就会错
		for(int i=1;i<=n;i++){
			int c =read();
			add(i, c);
		}
		char ch[6];
		while(~scanf("%s", ch)){
			if (ch[0] == 'E')
				break;
			else{
				int x = read(), k = read();
				if (ch[0] == 'A')
					add(x, k);
				else if (ch[0] == 'S')
					add(x, -k);
				else if (ch[0] == 'Q')
					printf("%d\n",ask(k) - ask(x-1));
			}
		}
	}
	return 0;
}
