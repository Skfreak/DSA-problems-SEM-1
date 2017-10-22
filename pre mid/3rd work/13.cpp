//max subarray with length atmost l
#include<iostream>
using namespace std;

int main(){
  int a[] = { 1,2,3,-4,5,6 };
  int n = sizeof(a)/sizeof(a[0]);
  int p[n+1], max;
  p[0]=0;
  p[1]=a[0];
  //max = p[1]-p[0];
  for(int i=2;i<n+1;i++){
    p[i]=p[i-1]+a[i-1];
  }
  cout<<"   ";
  for(int i=0;i<n;i++){
    cout<<a[i]<<"  ";
  }
  cout<<endl;
  for(int i=0;i<n+1;i++){
    cout<<p[i]<<"  ";
  }
  cout<<endl;

  int l=1,r=1,j=2,k=3,i=0;
  n = sizeof(p)/sizeof(p[0]);


  int s[100];
  s[l]=0;
  while(j<k+1){
    while(p[s[r]]<p[j]&&r>=0)
      r--;
    s[++r]=j;
    j++;
  }
  //cout<<a[s[l]]<<endl;
  max=p[s[l]]-p[i];
  //<<l<<" "<<r<<endl;

  while(j<n){
    while(r>=l&&p[j]>p[s[r]])
      r--;
    s[++r]=j;

    if(j>=k){
      i++;
      if(s[r]-s[l]+1>k){
        //i++;
        l++;
      }

      if(max<(p[s[l]]-p[i]))
      max=p[s[l]]-p[i];
    }
    j++;
  }
  cout<<max<<endl;

  return 0;
}
