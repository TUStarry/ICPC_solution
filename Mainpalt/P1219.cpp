#include<iostream>
using namespace std;
int n,total=0,flag=0;
bool date_map[14][14]={0};
bool lie[14]={0},xie_a[30]={0},xie_b[30]={0};
void print();
void search(int);
int main()
{
	cin>>n;
	search(1);
	cout<<total;
	return 0;
}

void search(int i)
{
	for(int j=1;j<=n;j++){
		if((!lie[j])&&!xie_a[i-j+13]&&!xie_b[i+j]){
			lie[j]=1;
			xie_a[i-j+13]=1;
			xie_b[i+j]=1;
			date_map[i][j]=1;
			if(i==n) {
				total++;
	            flag++;	
				if(flag<=3)print();	
			}
			else search(i+1);
			lie[j]=0;
			xie_a[i-j+13]=0;
			xie_b[i+j]=0;	
			date_map[i][j]=0;		
		}
	}
}

void print ()
{
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(date_map[i][j])	cout<<j<<" ";
		}
	}
	cout<<endl;	
	
}
