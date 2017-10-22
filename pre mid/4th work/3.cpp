//report the max value in each of the windows of length l in an array
//an application of mix of stack and queue
//in the stack -- treat front part as queue and end part as stack
#include<iostream>

using namespace std;


int main(){
  int l=0,r=0,j=1,k=3;
  int a[] = { 3,6,8,7,5,2,9,10 };
  int n = sizeof(a)/sizeof(a[0]);
  int s[100];
  s[l]=0;

  while(j<k){
    while(a[s[r]]<a[j]&&r>=0)
      r--;
    s[++r]=j;
    j++;
  }
  cout<<a[s[l]]<<endl;
  //<<l<<" "<<r<<endl;

  while(j<n){
    while(r>=l&&a[j]>a[s[r]])
      r--;
    s[++r]=j;
    if(j>=k-1){
      if(s[r]-s[l]+1>k)
        l++;
      cout<<a[s[l]]<<endl;
    }
    j++;
  }

  return 0;
}
