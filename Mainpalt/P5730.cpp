#include<bits/stdc++.h>
using namespace std;
string date_map[10][5]={
{"XXX","X.X","X.X","X.X","XXX"},//0
{"..X","..X","..X","..X","..X"},//1
{"XXX","..X","XXX","X..","XXX"},//2
{"XXX","..X","XXX","..X","XXX"},//3
{"X.X","X.X","XXX","..X","..X"},//4
{"XXX","X..","XXX","..X","XXX"},//5
{"XXX","X..","XXX","X.X","XXX"},//6
{"XXX","..X","..X","..X","..X"},//7
{"XXX","X.X","XXX","X.X","XXX"},//8
{"XXX","X.X","XXX","..X","XXX"},//9
};
int main()
{
	int n;
	string in;
	cin>>n;
	cin>>in;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<date_map[in[j]-'0'][i];
			if(j!=n-1)
				cout<<'.';
		}
		cout<<endl;
	}
	return 0;
}

