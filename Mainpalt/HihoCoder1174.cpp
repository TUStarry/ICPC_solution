#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
const int maxn=100000+5;
int n,m;
std::vector<int> graph[maxn];
int inlink[maxn];
bool tuopu(){
    std::queue<int> que;
    int sum=0;
    for(int i=1;i<=n;i++)
		if (inlink[i] == 0)
        	que.push(i);
    while(!que.empty()){
        int u = que.front(); 
		que.pop();
        sum++;
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(--inlink[v] == 0) 
				que.push(v);
        }
    }
    return sum == n;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
    	memset(inlink,0,sizeof(inlink));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) 
			graph[i].clear();
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            inlink[v]++;
        }
        if (tuopu())
	        printf("Correct\n");
	    else
	    	printf("Wrong\n");
    }
    return 0;
}
