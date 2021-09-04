#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod = 123456789;
int n=6;
struct Matrix{
	static const int N = 15;
	ll a[N][N];
	Matrix(ll e = 0){
		for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j] = e * (i == j);
	}
	Matrix mul(Matrix A,Matrix B){
		Matrix ans(0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					ans.a[i][j]=(ans.a[i][j]+A.a[i][k]*B.a[k][j]) % mod;
		return ans;
	}
	Matrix fastpower(Matrix A,ll b){
		Matrix ans(1);
		while(b){
			if (b&1)ans=mul(ans,A);
			A=mul(A,A);b>>=1;
		}
		return ans;
	}
}m1;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long q;
        scanf("%lld",&q);
        {
            m1.a[1][1]=1,m1.a[1][2]=2,m1.a[1][3]=1,m1.a[1][4]=3,m1.a[1][5]=3,m1.a[1][6]=1;
            m1.a[2][1]=1,m1.a[2][2]=0,m1.a[2][3]=0,m1.a[2][4]=0,m1.a[2][5]=0,m1.a[2][6]=0;
            m1.a[3][1]=0,m1.a[3][2]=0,m1.a[3][3]=1,m1.a[3][4]=3,m1.a[3][5]=3,m1.a[3][6]=1;
            m1.a[4][1]=0,m1.a[4][2]=0,m1.a[4][3]=0,m1.a[4][4]=1,m1.a[4][5]=2,m1.a[4][6]=1;
            m1.a[5][1]=0,m1.a[5][2]=0,m1.a[5][3]=0,m1.a[5][4]=0,m1.a[5][5]=1,m1.a[5][6]=1;
            m1.a[6][1]=0,m1.a[6][2]=0,m1.a[6][3]=0,m1.a[6][4]=0,m1.a[6][5]=0,m1.a[6][6]=1;
            if(q==0) printf("0\n");
            else
            {
                m1=m1.fastpower(m1,q-2);
                printf("%lld\n",(m1.a[1][1]*2%mod+m1.a[1][2]*1%mod+m1.a[1][3]*8%mod+m1.a[1][4]*4%mod+m1.a[1][5]*2%mod+m1.a[1][6]%mod)%mod);
            }
        }
        }
    return 0;
}