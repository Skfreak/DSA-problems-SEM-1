#include<iostream>
#include<algorithm>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int dPivot(int a[], int i, int j){
  int l, m, s =j-i+1; // size
  if(s<5){
    sort(a,a+s);
    int t = a[i];
    a[i] = a[(i+j)/2];
    a[(i+j)/2] = t;
    return i;
  }
  int k=s%5;
  s = s-k; //taking greatest multiple of 5
  //cout<<s<<endl;

  for(l=i;l<s+i;l+=5){ //sorting the buckets of 5 elements
    sort(a+l,a+(l+5));
  }
  sort(a+s+i,a+i+s+k);//sorting the remaining elements
  //cout<<endl<<endl<<i+2<<endl<<endl;
  for(l=i,m=i+2;m<s+i;l++,m+=5){
    //cout<<endl<<"--"<<a[m]<<"--"<<a[l]<<endl;
    swap(&a[m],&a[l]);
  }

  if(k!=0){
    int t = a[l];
    a[l] = a[s+i+((k)/2)];
    a[s+i+((k)/2)] = t;
  }

  //cout<<endl<<"--"<<l<<"--"<<endl;
  sort(a+i,a+l+1);
  return (i+((s/5)/2));

}
void printA(int a[], int l, int r){
  for(int i=l;i<=r;i++){
    cout<<endl<<endl<<a[i];
  }
}

int main(){
  int a[] = {7,6,3,4,5,1,91,14,15,16,17,13,34,45,56,27,29,89,13,124,90,63,2,1};
  int size = sizeof(a)/sizeof(a[0]);
  int k = dPivot(a,0,23);
  cout<<k<<endl;
  //printA(a,10,17);
  cout<<endl<<size<<endl;
  return 0;
}
