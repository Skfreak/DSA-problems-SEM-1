#include<stdio.h>
int rec(int n){
  if(n<2)
    return n;
  else
    return ((rec(n-1)+rec(n-2))%100);
}



int main(){
  int i;
  i = rec(60);
  printf("%d",i);
  return 0;

}
//in 1 sec getting for 40
