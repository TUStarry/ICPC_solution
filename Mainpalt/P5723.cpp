#include<bits/stdc++.h>
using namespace std;
int pd(int num)
{
	int flag=1;
	for(int i=2;i<=num/2;i++)
		if(num%i==0) flag=0;
	if(flag==1) return 1;
	else return 0;
}
int main()
{
	int n,total=0,N=0;
	scanf("%d",&n);
	if(n==1) cout<<0;
	for(int i=2;i<=n;i++){
		if(pd(i)==1){
			N+=i;
			if(N>n) {
				cout<<total;
				return 0;
			}
			cout<<i<<endl;
			total++;
		}
		
	}

	return 0;
}
