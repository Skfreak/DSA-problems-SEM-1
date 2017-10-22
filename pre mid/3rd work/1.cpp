// 1. in an array find if a[i]+a[j]=x , where x is a constant
// 2. one approach is to sort array in nlog(n) then do binary search for
// each n every difference
// this algo is for sorted array in O(n) time
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a[] = { 1, 2, 4, 6, 7, 14, 25, 56, 98, 124, 156, 207, 1250, 2905  };
  int size = sizeof(a)/sizeof(a[0]);
  int x, flag = 0;
  cout<<"Enter sum to be found : ";
  cin>>x;
  int left = 0, right = size-1;
  while(left<right){
    if(a[left] + a[right] == x){
      flag = 1;
      break;
    }

    else if(a[left] + a[right] < x)
      left++;
    else
      right--;
  }
  if(flag==1)
    cout<<endl<<"Found"<<endl;
  else
    cout<<endl<<"Not Found"<<endl;
  return 0 ;

}
