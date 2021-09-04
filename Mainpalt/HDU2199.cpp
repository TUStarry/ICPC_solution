#include<cstdio>
#include<cstring> 
double fx(double x){
	return  8*x*x*x*x + 7*x*x*x + 2*x*x + 3*x + 6;
}
void getx(double y){
	double left = 0;
	double right = 100;
	if(fx(0) > y || y > fx(100)){
		printf("No solution!\n");
		
	}
	else{
	
	while(right - left > 0.00000001){
		double mid = (left + right) / 2;
		if(fx(mid) < y){
			left = mid;
		}
		else
			right = mid;
	}
	printf("%.4lf\n",left);}
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    	double y;
    	scanf("%lf",&y);
    	getx(y);
	}
    return 0;
}
