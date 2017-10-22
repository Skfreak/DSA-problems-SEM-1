#include<stdio.h>
int main(){
  int s=2,n=10000;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++)
        s=s*2+1;
    }
  }
  printf("%d",s);
  return 0;
}
