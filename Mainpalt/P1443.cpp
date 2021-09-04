#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

int qipan[404][404]={0},n,m,a,b;
bool qipan_1[404][404]={0};
int search(){
	
}

print(){
	for(int i=1;i<=n;i++)	{
		for(int j=1;j<m;j++){
			cout<<left<<setw(5)<<qipan[i][j];
		}
	cout<<endl;
	}
		
}
int main()
{
	cin>>n>>m>>a>>b;
	qipan_1[a][b]=1;
	
	print();
	return 0;
}
