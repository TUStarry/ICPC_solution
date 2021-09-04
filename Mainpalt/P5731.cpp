#include<bits/stdc++.h>
using namespace std;
int date[10][10]={0};
int main()
{
	int n,total=1,x=0,y=1;
	scanf("%d",&n);
	while(total<=n*n)
	{	
		while(x<n&&!date[y][x+1]) date[y][++x]=total++;
		while(y<n&&!date[y+1][x]) date[++y][x]=total++;
		while(1<x&&!date[y][x-1]) date[y][--x]=total++;
		while(1<y&&!date[y-1][x]) date[--y][x]=total++;
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<setw(3)<<date[i][j];
			cout<<endl;
	}
	return 0;
} 
