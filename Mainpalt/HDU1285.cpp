#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
const int maxn =501;
bool graph[maxn][maxn];
int edge[maxn];
int main(){int n, m;
	while(std::cin >> n >> m){
	
	memset(graph,0,sizeof(graph));
	memset(edge,0,sizeof(edge));
	
	
	for(int i=1;i<=m;i++){
		int a, b;
		scanf("%d%d",&a, &b);
			graph[a][b] = 1;
			edge[b] ++;
	}
    for(int i=1;i<=n;i++){
		int cur;
		for(int j=1;j<=n;j++){
			if (edge[j] == 0){
				cur = j;
				edge[j] = -1;
				break;
			}
		}
		if (i == 1)
        	std::cout << cur;
        else
        	std::cout<<" "<<cur;
		for(int j=1;j<=n;j++)
             if(graph[cur][j] == 1)
				 edge[j]--;
	}
	std::cout<<std::endl;
	}
	return 0;
}
