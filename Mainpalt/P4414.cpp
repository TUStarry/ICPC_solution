#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3];
	char A,B,C;
    cin>>a[0]>>a[1]>>a[2];
    cin>>A>>B>>C;
    sort(a,a+3);
    cout<<a[A-'A']<<" "<<a[B-'A']<<" "<<a[C-'A'];//��ĸ�Ǵ�д����ȥ��A����õ�0��A��,1��B��,2��C����
    return 0;
}
