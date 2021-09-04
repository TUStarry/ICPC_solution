#include<bits/stdc++.h> 
using namespace std;
int S[5],date[5][21],Min,Left,Right;
void search(int y,int x){
	if(x>S[y]) {
		Min=min(Min,max(Left,Right));
		return;
	}
	Left+=date[y][x];
	search(y,x+1);
	Left-=date[y][x];
	Right+=date[y][x];
	search(y,x+1);
	Right-=date[y][x];
}
int main()
{
	int total=0;
	for(int i=1;i<=4;i++) 
		cin>>S[i];
	for(int i=1;i<=4;i++){
		for(int j=1;j<=S[i];j++)
			cin>>date[i][j];
		Left=Right=0;
		Min=99999999;
		search(i,1);
		total+=Min;
	}
	cout<<total;
	return 0;
}
