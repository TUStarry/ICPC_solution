#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	for(int i=2;i<=(n>>1);i++)
		if(n%i==0) {
			cout<<(n/i);
			return 0;
		}
} 
