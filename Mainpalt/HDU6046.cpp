#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define MAXN 30001
using namespace std;
#define  LL long long
inline unsigned sfr(unsigned h, unsigned x) { 
  return h >> x; 
} 
int f(LL i, LL j) { 
  LL w = i * 1000000ll + j; 
  int h = 0; 
  for(int k = 0; k < 5; ++k) { 
    h += (int) ((w >> (8 * k)) & 255); 
    h += (h << 10); 
    h ^= sfr(h, 6); 
  } 
  h += h << 3; 
  h ^= sfr(h, 11); 
  h += h << 15; 
  return sfr(h, 27) & 1; 
} 
int main(){
	int t;
	cin >> t;
	while(t--){
		
	}
	
	return 0;
}
