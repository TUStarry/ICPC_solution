#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
inline int read(){
	int fu = 1, num = 0;
	char ch = getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') fu=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') {num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
int arr[1000010];
int main(){
	int T = read(),total = 1;
	while(T--){
		int maxn = -(1<<30);
		int n = read(), m = read();
		for(int i=1;i<=n;i++)
			arr[i] = read();
		printf("Case #%d:\n",total++);
		while(m--){
			int s = read();
			for(int i=1;i<=n;i++)
				maxn = max(maxn, arr[i]^s);			
			printf("%d\n",maxn^s);	
		}
	}
	return 0;
}
