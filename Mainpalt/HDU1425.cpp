#include<iostream>
#include<cstdio>
using namespace std;
void Quicksort(int *a, int left, int right) 
{// left、right左闭右开，low、high闭区间
    if (left >= right -1) return;
    int low = left, high = right-1, center = a[low]; 
    while(low< high)
    {
        while(low < high && a[high] >= center) high --; 
        	a[low]= a[high];
        while(low < high && a[low] <= center) low ++;
        	a[high]=a[low];        
    }
    a[low]= center;
    Quicksort(a,left, low);
    Quicksort(a,low +1,right);
}
int arr[1000005];
int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d", &arr[i]);
        Quicksort(arr,0,n);
        for(int i=n-1;i> n-m;i--)
            cout<<arr[i] << " ";
        cout<<arr[n-m];
        cout<<endl;
    }
    return 0;
}
