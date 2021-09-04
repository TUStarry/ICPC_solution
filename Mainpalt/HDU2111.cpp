#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1005;
struct Node
{
    int price;
    int vol;
} tr[maxn];
bool cmp(Node a, Node b)
{
    return a.price > b.price;
}
int main()
{
    int v, n;
    while (scanf("%d", &v) && v)
    {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &tr[i].price, &tr[i].vol);
        sort(tr + 1, tr + 1 + n, cmp);
        for(int i = 1; i <= n; i++)
        {
            if (tr[i].vol < v)
            {
                ans += tr[i].vol * tr[i].price;
                v -= tr[i].vol;
            }
            else 
            {
                ans += tr[i].price * v;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}