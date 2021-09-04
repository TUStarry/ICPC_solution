#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<cmath>
double y;
double fx(double x){
	return  6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
double bs(){
	double l = 0, r =100;
	while(r-l>0.00000000000001){
		double mid = (l + r) / 2;
		if (42*pow(mid,6)+48*pow(mid,5)+21*pow(mid,2)+10*mid-y >= 0)
			r = mid;
		else 
			l = mid;
	}
	return r;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    	scanf("%lf",&y);
    	double ans = bs();
    	printf("%.4lf\n",fx(ans));
	}
    return 0;
}
