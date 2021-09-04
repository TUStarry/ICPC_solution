#include<bits/stdc++.h>
using namespace std;
int date[22][22]={0};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		date[i][1]=date[i][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=2;j<=i;j++){
			date[i][j]=date[i-1][j]+date[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)
			cout<<date[i][j]<<" ";
		cout<<endl;
	}
		
	return 0;
} 
