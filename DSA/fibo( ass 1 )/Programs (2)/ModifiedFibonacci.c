#include<stdio.h>
#include<stdlib.h>

int a[3][3],b[3][3],mod;

void MM(int m[3][3],int c[3][3])
{
    int temp[3][3];
    int i,j,k;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            temp[i][j] = 0;

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++)
                temp[i][j] += m[i][k] * c[k][j];

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            a[i][j] = temp[i][j]%mod;
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
    printf("Enter the mod: ");
    scanf("%d",&mod);
    a[0][0] = b[0][0] = 1;
    a[0][1] = b[0][1] = 0;
    a[0][2] = b[0][2] = 1;
    a[1][0] = b[1][0] = 1;
    a[1][1] = b[1][1] = 0;
    a[1][2] = b[1][2] = 0;
    a[2][0] = b[2][0] = 0;
    a[2][1] = b[2][1] = 1;
    a[2][2] = b[2][2] = 0;
    printf("Enter the number: ");
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
    if(n == 2)
    {
        printf("1\n");
        return 0;
    }
    power(n-1);
    printf("%d\n",(a[2][1]+a[2][0])%10);
    return 0;
}
