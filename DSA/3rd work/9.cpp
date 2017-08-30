//max subarray in an array
// brute force : 0(n^3)
/* i=0->n
    j=i+1->n
      s=0
      k=i->j
        s=s+a[k]
        if(m<s) m=s
*/
/* brute force 2 : 0(n^2)
  i=0 to n
    s=a[i]
    j=i+1 to n
      s+=a[j]
        if(s>m) m=s
*/
// calc p1,p2,p3 such that pi = summation of elements upto that
// then find max|pj=pi|
#include<iostream>
using namespace std;

int main(){
  int a[] = { 1,-2,3 };
  int n = sizeof(a)/sizeof(a[0]);
  int p[n], max;
  p[0]=a[0];
  max = p[0];
  for(int i=1;i<n;i++){
    p[i]=p[i-1]+a[i];
    if(max<p[i])
      max=p[i];

  }
  int i=0,j=1;
  if(max<p[j]-p[i])
    max = p[j]-p[i];
  j++;
  while(j<n){
    if(p[i]>p[j-1])
      i = j-1; // if previous index is smaller than any of the
              //indices found so far, update i
      if(p[j]-p[i]>max)
        max = p[j]-p[i];
      j++;
  }

  cout<<"max subarray : "<<max<<endl;
  return 0;
}
