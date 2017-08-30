#include<stdio.h>

int main()
{
    int i,a=0,b=1,c,mod;
    char str[1000001];
    printf("Enter the mod: ");
    scanf("%d",&mod);
    int arr[6*mod];
    arr[0] = 0;
    arr[1] = 1;
	for(i=2;i<6*mod;i++)
    {
	    c = (a+b)%mod;
	    arr[i] = c;
	    a = b;
	    b = c;
	}
	printf("Enter the number: ");
	scanf("%s",str);
	while(str[0] != '#')
    {
        a = 0;
        b = strlen(str);
        c = 1;
        for(i=b-1;i>-1;i--)
        {
            a = (a + c*(str[i]-48))%mod;
            c = (c * 10)%mod;
        }
        printf("%d\n",arr[a]);
        printf("Enter the number: ");
        scanf("%s",str);
    }
    return 0;
}
