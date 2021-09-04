#include<iostream>
using namespace std;
int map_[14][14]={0},N,total_=0;
bool lie_[14]={0},xie_a_[50]={0},xie_b_[50]={0};
int search(int i);
int print();
int main()
{ 
	cin>>N;
	search(1);
	cout<<total_;
	return 0;
}
int search(int i)
{
	for(int j=1;j<=N;j++)
    {
    	if((!lie_[j])&&(!xie_a_[i+j])&&(!xie_b_[i-j+12]))
    	{
    		map_[i][j]=1;
    		lie_[j]=1;
    		xie_a_[i+j]=1;
    		xie_b_[i-j+12]=1;
    		if(i==N) print();
    		else search(i+1);
            map_[i][j]=0;
    		lie_[j]=0;
    		xie_a_[i+j]=0;
    		xie_b_[i-j+12]=0;
    	}
    }
}
int print()
{	
	total_++;
	if(total_<=3)
	{
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{
				if(map_[i][j]==1)
				{
					cout<<j<<" ";
				}
			}
		}
	cout<<endl;
	}
	
}
