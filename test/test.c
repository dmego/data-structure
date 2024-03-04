#include<stdio.h>
int main()
{
    int a, b, c, d;
    a = b = 10;
    c = a++;
    d = ++b;

    printf("a: %d, b: %d, c: %d, b: %d", a, b, c, d);
}