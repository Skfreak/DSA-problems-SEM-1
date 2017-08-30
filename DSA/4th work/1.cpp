//find the first smaller number to the right of the current element
// and return its index
// store all such indices
//s[n] i being used as a stack
#include<iostream>
using namespace std;
int main(){
  int a[] = { 3,6,8,7,5,2,9,10 };
  int i = 0,c =0;
  int n = sizeof(a)/sizeof(a[0]);
  int s[n], b[n];
  s[i]=0;
  for(int j=1;j<n;j++){
    if(a[j]>a[s[i]])
      s[++i]=j;
    else{
      //int k=i;
      while (i>=0&&a[j]<a[s[i]]) {
        //s[i]=j;
        b[s[i--]]=j;
        //s[i--]=j;
      }
      s[++i]=j;
    }
    //i++;
  }
  while(i>=0)
    b[s[i--]]=0;

    for(i=0;i<n;i++){
      cout<<b[i]<<endl;
    }
  return 0;
}
