// find if  a[i]+a[j]=a[k]
// open problem--O(n^2)--less than that? don't know
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a[] = { 3 ,4, 8, 15  };
  int size = sizeof(a)/sizeof(a[0]);
  sort(a,a+size);
  int x ,left , right;
  for(int i =0;i<size;i++){
    x = a[i];
    left = 0, right = size-1;
    while(left<right){
      if(a[left] + a[right] == x){
        cout<<endl<<"Found"<<endl;
        exit(0);
      }

      else if(a[left] + a[right] < x)
        left++;
      else
        right--;
    }
  }

  cout<<"Not Found"<<endl;


  return 0 ;

}
