#include <stdio.h>

int factorial(int n){
    int sum = 1;
    if(n == 0 || n == 1)
        return 1;
    return factorial(n-1) * n;
}
int main()
{
    printf("%d\n",factorial(5));
}