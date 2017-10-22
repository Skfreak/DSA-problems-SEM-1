//max subarray with length atleast l
#include<iostream>
using namespace std;

int main(){
  int a[] = { -2,-2,-3,4 };
  int n = sizeof(a)/sizeof(a[0]);
  int p[n+1], max;
  p[0]=0;
  p[1]=a[0];
  //max = p[1]-p[0];
  for(int i=2;i<n+1;i++){
    p[i]=p[i-1]+a[i-1];
  }

  /*
  int i=0,j=1;
  if(max<p[j]-p[i])
    max = p[j]-p[i];
  j++;
  while(j<n+1){
    if(p[i]>p[j-1])
      i = j-1; // if previous index is smaller than any of the
              //indices found so far, update i
      if(p[j]-p[i]>max)
        max = p[j]-p[i];
      j++;
  }
  */
  n = sizeof(p)/sizeof(p[0]);
  int i =0,l=2,j;
  j=i+l;
  max = p[j]-p[i];
  //cout<<max<<endl;

  j++;
  while(j<n){
    if(p[i]>p[j-l])
      i = j-l; // if previous index is smaller than any of the
              //indices found so far, update i
      if(p[j]-p[i]>max)
        max = p[j]-p[i];
      j++;
  }
  cout<<max<<endl;
  //cout<<"max subarray : "<<max<<endl;
  return 0;
}
