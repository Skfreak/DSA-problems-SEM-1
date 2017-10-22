#include<stdio.h>

unsigned long long int linear (unsigned long long int n){
  unsigned long long int a,b,c;
    a=0;
		b=1;
		c=n;
    for (unsigned long long int i=2;i<=n; ++i){
			c=(a+b)%100;
			a=b;
			b=c;
			}
	return c;
}
int main(){
  unsigned long long int i;
  i = linear(1000000234);
  printf("%llu",i);
  return 0;

}
