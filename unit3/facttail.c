#include <stdio.h>
int facttail(int n, int a)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (n == 1)
        return a;
    else 
        return facttail(n - 1, n * a);
}

int main()
{
    printf("%d\n", facttail(3, 1));
    return 0;
}
