#include<stdio.h>
int main(){
  int n=1000000,i;
  int f[n+1];

  f[0]=0;
	f[1]=1;
  for (i=2;i<=n; ++i)
	{
    f [i] =(f[i-1]+f[i-2])%100;
  }

  printf("%d",f[n]);
  return 0;

}
//in 1 sec getting for 40
