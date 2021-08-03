#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
char list1[1000001],list2[10001];
int next[10001];
int n, m, num;
void Get_next(){
	int i = 1,j = 0;
	next[0] = -1;
	while(i < m)	{
		if(j==-1 || list2[i]==list2[j])
			next[++i] = ++j;
		else
			j = next[j];
	}
}
void kmp(){
    Get_next();
	int i = 0,j = 0;
	while(i < n){
		if(j==-1 || list1[i]==list2[j])
			i++,j++;   
		else
			j =next[j];
		if(j == m){
			num++;
			j = next[j];
		}
	}
	printf("%d\n", num);
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		num = 0;
		scanf("%s",list2);
		scanf("%s",list1);
		n = strlen(list1);
		m = strlen(list2);
		kmp();	
	}
	return 0;
}

