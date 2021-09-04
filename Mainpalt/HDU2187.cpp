#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node
{
    int price;
    int weight;
} tr[1600];
bool cmp(Node a, Node b)
{
    return a.price < b.price;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, minn = 0x3f3f3f3f, cur;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            scanf("%d%d", &tr[i].price, &tr[i].weight);
        sort(tr + 1, tr + m + 1, cmp);
        double ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (tr[i].price * tr[i].weight <= n)
            {
                ans +=  tr[i].weight;
                n -= tr[i].price * tr[i].weight;
            }
            else
            {
                double temp = (double)n / tr[i].price;
                ans += temp;
                break;
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}