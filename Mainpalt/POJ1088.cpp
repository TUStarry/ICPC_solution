#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n, m;
int mp[105][105];
int vis[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check(int x, int y){
	if(x >= 1 && y >= 1 && x <= n && y <= m) return true;
	else return false;
}
int dfs(int x, int y)
{
	if (vis[x][y] != 0)	return vis[x][y];
	vis[x][y] = 1;       
	for(int i = 0; i <= 4; i++)
    {    
		int xx = x + dx[i];
		int yy = y + dy[i];
		if( check(xx, yy) && mp[xx][yy] < mp[x][y]) 
			vis[x][y] = max(dfs(xx, yy) + 1, vis[x][y]);	
	}
	return vis[x][y]; 
}
int main()
{ 
	cin >> n >> m;
	int ans = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			cin >> mp[i][j];
			vis[i][j] = 0;      
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans = max(ans, dfs(i, j));
	cout << ans << endl;
	return 0;
}
