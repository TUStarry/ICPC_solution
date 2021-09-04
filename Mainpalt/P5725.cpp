#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k=1;
	cin>>n;
	for(int i=1;i<=(n*n);i++){
		if(i<10) cout<<"0";
		cout<<i;
		if(i%n==0) cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(n-i);j++)
			cout<<"  ";
		for(int j=1;j<=i;j++){
			
			if(k<10) cout<<"0";
			cout<<k;
			k++;			
		}
	cout<<endl;		
	}
	return 0;
}
