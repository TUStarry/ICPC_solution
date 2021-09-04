#include<bits/stdc++.h>
using namespace std;
long long int n,a1,a2,b1,b2,c1,c2,pen1=0,pen2=0,pen3=0,x[3]={0};
int compare(int a1,int a2,int b1,int b2,int c1,int c2)
{
    while(pen1<n)  { pen1+=a1; x[0]+=a2; }
    while(pen2<n)  { pen2+=b1; x[1]+=b2; }
    while(pen3<n)  { pen3+=c1; x[2]+=c2; }
    return x[0],x[1],x[2];
}
int main()
{
    cin>>n>>a1>>a2>>b1>>b2>>c1>>c2;
    compare(a1,a2,b1,b2,c1,c2);
    sort(x,x+3);
    cout<<x[0];
    return 0;
}
