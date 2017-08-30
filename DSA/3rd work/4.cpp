// find max|a[i]-a[j]|
// u know the drill for brute force
// for 0(n) time we find max n min element n take the difference

#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int main(){
  int max = INT_MIN, min = INT_MAX;
  int a[] = { 2,3,-4,5,7,10,0,-25,7,25,28,-6};
  int size = sizeof(a)/sizeof(a[0]);
  for(int i=0;i<size;i++){
    if(a[i]>max)
      max = a[i];
    if(a[i]<min)
      min = a[i];
  }

  cout <<endl<<"ma|a[i]-a[j]| = "<<abs(max-min)<<endl;
  return 0;
}
