#include <cstdio>
int main()
{
    int n,x,k;
    scanf("%d", &n);
    for (k=1;;++k)
        for(x=100;x>0;--x)
            if ((7 * x + 21 * k) * 52 == n){
                printf("%d\n%d\n", x, k);
                return 0;
            }
}
