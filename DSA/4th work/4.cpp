//max(a[j]-a[i]) such that i<=j<=i+l-1
#include<iostream>
using namespace std;


int main(){
  int l=0,r=0,j=1,k=3,i=0,max;
  int a[] = { 3,6,8,7,-5,2,9,10 };
  int n = sizeof(a)/sizeof(a[0]);
  int s[100];
  s[l]=0;
  while(j<k){
    while(a[s[r]]<a[j]&&r>=0)
      r--;
    s[++r]=j;
    j++;
  }
  //cout<<a[s[l]]<<endl;
  max=a[s[l]]-a[i];
  //<<l<<" "<<r<<endl;

  while(j<n){
    while(r>=l&&a[j]>a[s[r]])
      r--;
    s[++r]=j;

    if(j>=k-1){
      i++;
      if(s[r]-s[l]+1>k){
        //i++;
        l++;
      }

      if(max<(a[s[l]]-a[i]))
      max=a[s[l]]-a[i];
    }
    j++;
  }
  cout<<max<<endl;
  return 0;
}
