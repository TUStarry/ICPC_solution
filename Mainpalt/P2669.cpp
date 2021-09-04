#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,i;
	long long int total=0;
	cin>>k;
	for(i=1;k-i>=0;k-=i++)
		total+=i*i;
	cout<<(total+i*k);
	return 0;
} 
