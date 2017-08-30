// max subarray of length atleast l

#include<iostream>

using namespace std;
int main(){
  int a[] = { 2,-2,-13,3,-15,3,50 };
  int n = sizeof(a)/sizeof(a[0]);
  int s =a[0]+a[1]+a[2], l=3, j=3, m =0;
  while(j<n){
    if(s<0&&j+l<n){
      s=0;
      s=a[j]+a[j+1]+a[j+2];
      j=j+l;
      if(m<s)
        m=s;

    }
    s=s+a[j];

    if(m<s)
      m=s;
    j++;
    //cout<<endl<<m<<endl;
  }

  cout<<"max subarray : "<<m<<endl;
  return 0;
}
