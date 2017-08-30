// max|a[j]-a[i]| such that j>i
//1. brute force (n^2 time)
// 0(n) approach given below

#include<iostream>

using namespace std;

int main(){

  int a[] = { 6,5,8,12,3,1,0,24,14,24,11,-5,20 };

  int i=0, j=1, max, n=sizeof(a)/sizeof(a[0]);
  max = a[j]-a[i];
  j++;
  while(j<n){
    if(a[i]>a[j-1])
      i = j-1; // if previous index is smaller than any of the
              //indices found so far, update i
      if(a[j]-a[i]>max)
        max = a[j]-a[i];
      j++;
  }

  cout<<endl<<"max|a[j]-a[i]|, such that j>i is : "<<max<<endl;
  return 0;
}
