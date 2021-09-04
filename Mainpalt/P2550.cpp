#include<bits/stdc++.h>
using namespace std;
int date[10],date_1[10],total[10]={0}; 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=7;i++)
		scanf("%d",&date[i]);
	while(n--)
	{
		for(int i=1;i<=7;i++)
			scanf("%d",&date_1[i]);
		int T=0;
		for(int i=1;i<=7;i++)
			for(int j=1;j<=7;j++){
				if(date[i]==date_1[j]) T++;
			}
		total[7-T]++;	
	}
	for(int i=0;i<7;i++) 
		cout<<total[i]<<" ";
	return 0;
 } 
