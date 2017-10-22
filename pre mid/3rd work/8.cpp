// max|a[j]-a[i]| such that i<j<i+l
//1. brute force (n^2 time)
// 0(n) approach given below(tried)
// doubt : cant it be done by finding max n min other than last element
#include<iostream>

using namespace std;

int main(){

  int a[] = { 2,3,-3,1,0,1,2,6 };

  int i=0, max,l=3, n=sizeof(a)/sizeof(a[0]);
  int j = 1;
  max = a[j]-a[i];
  j++;
  while(i+l<n){
    if(a[i]>a[j-1])
      i = j-1; // if previous index is smaller than any of the
              //indices found so far, update i
      if(a[j]-a[i]>max)
        max = a[j]-a[i];
      j++;
      if(j==i+l)
        l++;
  }

  cout<<endl<<"max|a[j]-a[i]|, such that j<i+l (l=4) is : "<<max<<endl;
  return 0;
}
