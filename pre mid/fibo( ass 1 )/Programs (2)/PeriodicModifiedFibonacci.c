#include<stdio.h>
#include<string.h>

int main()
{
    int a=0,b=1,c=1,d,i,mod,j;
    char num[1000001];
    printf("Enter the mod: ");
    scanf("%d",&mod);
    i = (217 * mod/10);
    int arr[i];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for(j=3;j<i;j++)
    {
        d = (a+c)%mod;
        arr[j] = d;
        a = b;
        b = c;
        c = d;
    }
    printf("Enter the number: ");
    scanf("%s",num);
    mod = i;
    a = 0;
    while(num[0] != '#')
    {
        a = 0;
        b = strlen(num);
        d = 1;
        for(i = b-1;i>-1;i--)
        {
            a = (a + d*(num[i]-48))%mod;
            d = (d*10)%mod;
        }
        printf("%d\n",arr[a]);
        printf("Enter the number: ");
        scanf("%s",num);
    }
    return 0;
}
