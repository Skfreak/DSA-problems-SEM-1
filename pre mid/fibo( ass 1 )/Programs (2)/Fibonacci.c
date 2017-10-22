#include<stdio.h>
#include<stdlib.h>

int *a,*b,mod;

void MM(int *m,int *c)
{
    int *temp;
    temp = (int *)malloc(sizeof(int)*4);

    *(temp + 0) = ((*(m+0))*(*(c+0))) + ((*(m+1))*(*(c+2)));
    *(temp + 1) = ((*(m+0))*(*(c+1))) + ((*(m+1))*(*(c+3)));
    *(temp + 2) = ((*(m+2))*(*(c+0))) + ((*(m+3))*(*(c+2)));
    *(temp + 3) = ((*(m+2))*(*(c+1))) + ((*(m+3))*(*(c+3)));

    *(a+0) = *(temp+0)%mod;
    *(a+1) = *(temp+1)%mod;
    *(a+2) = *(temp+2)%mod;
    *(a+3) = *(temp+3)%mod;
}

void power(int n)
{
    if(n > 1)
    {
        power(n/2);
        MM(a,a);
        if(n%2 != 0)
            MM(b,a);
    }
}

int main()
{
    int n;
    scanf("%d",&mod);
    a = (int *)malloc(sizeof(int)*4);
    b = (int *)malloc(sizeof(int)*4);
    *(a+0) = *(b+0) = 1;
    *(a+1) = *(b+1) = 1;
    *(a+2) = *(b+2) = 1;
    *(a+3) = *(b+3) = 0;
    scanf("%d",&n);
    if(n < 1)
    {
        printf("Wrong Input\n");
        return 0;
    }
    if(n == 1)
    {
        printf("0\n");
        return 0;
    }
    power(n-1);
    printf("%d\n",*(a+2));
    return 0;
}
