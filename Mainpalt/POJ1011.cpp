#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 70;
int arr[maxn], n;
int vis[maxn], lastnum=0;
bool cmp(int a, int b){
	return a>b;
}
bool dfs(int m,int l, int L)
{
	if(m == 0 && l == 0) return true;//find out ans
	if(l == 0)  l = L;
	int cur = 1;
	if(l != L) cur = lastnum+1;
	for(int i=cur;i<=n;i++)
    {
		if(!vis[i-1] && i>1 && arr[i] == arr[i-1]) continue;	
		if(!vis[i] && arr[i]<=l)
        {
			vis[i] = 1;
			lastnum = i;
			if(dfs(m-1,l-arr[i], L)) return true;
			else
            {
				vis[i] = 0;
				if(L == l||arr[i] == l) return false;	
			}
		}
	}
	return false;
}
int main()
{
	while(~scanf("%d",&n) && n)
    { 
		memset(arr,0,sizeof(arr));
		int tot = 0, largestlen = -1;
		for(int i=1;i<=n;i++)
        {
			scanf("%d", &arr[i]);
			if(arr[i] > largestlen) largestlen = arr[i];//largest length sticks
			tot += arr[i];// tot length
		}
		int i;
		sort(arr+1,arr+1+n,cmp);//big -> small
		for(i=largestlen;i<=tot/2;i++)
			if(tot % i == 0)
            {
                memset(vis,0,sizeof(vis));
                lastnum=0;
                if(dfs(n, i, i))
                {
                    printf("%d\n",i);
                    break;
                }
            }
		
		if(i>tot/2) printf("%d\n",tot);
	}
    return 0;
}