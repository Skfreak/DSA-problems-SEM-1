#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
/*
int sort(int a[], int left, int right){
  int t;
  for(int i=left;i<right;i++){
    for(int j=left;j<right;j++){
      if(a[i]<a[j]){
        t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
    }
  }
}*/
/*
int dPivot(int a[], int i, int j){
  int l, s =j-i+1; // size
  if(s<5){
    sort(a,a+s);
    return (i+j)/2;
  }
  int k=s%5;
  s = s-k; //taking greatest multiple of 5
  //cout<<s<<endl;

  for(l=i;l<s;l+=5){ //sorting the buckets of 5 elements
    sort(a+l,a+(l+5));
  }
  sort(a+s,a+s+k);//sorting the remaining elements
  for(l=i,j=2;j<s;l++,j+=5){
    int t = a[l];
    a[l] = a[j];
    a[j] = t;
  }
  if(k!=0){
  int t = a[l];
  a[l] = a[s+((k)/2)];
  a[s+((k)/2)] = t;
  }
  sort(a+i,a+(i+5));
  return (i+2);

}
*/

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
int partition (int a[], int low, int high, int p)
{
    swap(&a[p],&a[high]);
    int pivot = a[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (a[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

int findRank(int a[], int i, int j, int r){

  int p, k;
  if(j<i){
    cout<<"\nCould not find!!\n";
    exit(0);
  }
  else{
    p = dPivot(a, i, j);
    k = partition(a, i, j, p );
    cout<<p<<" "<<k<<endl;
  }
  if(r==(j-k+1))
    return k;
  else if(r<(j-k+1))
    findRank(a,k+1,j,r);
  else
    findRank(a,i,k-1,r-(j-k+1));
}


int main(){
  int a[]={27,3,11,12,2,53,4,6,7,8,9,11,15,16,18,19,13,10,35,46,23,34,56,78,42,98};
  //int a[] = {2,1,4,3};
  int size= sizeof(a)/sizeof(a[0]);
  //cout<<size;
  /*
  dPivot(a,0,size-1);
  for(int i=0;i<size;i++){
    cout<<a[i]<<" ";
  }

  cout<<endl;
  */


  int k = findRank(a,0,size-1,15);
  cout<<"element with rank 15 : "<<a[k];


  sort(a,a+size);
  cout<<endl;
  for(int i=0;i<size;i++){
    cout<<a[i]<<" ";
  }


  cout<<endl;

  return 0;
}
