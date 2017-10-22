#include<iostream>
#include<cstdlib>

using namespace std;

int rPivot(int i, int j){
  srand(time(NULL));
  int k=rand()%(j-i+1)+i;
  return k;
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
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
    p = rPivot(i,j);
    k = partition(a,i,j,p);
    //cout<<p<<" "<<k<<endl;
  }
  if(r==(j-k+1))
    return k;
  else if(r<(j-k+1))
    findRank(a,k+1,j,r);
  else
    findRank(a,i,k-1,r-(j-k+1));
}

int main(){
  int k,m;
  int a[] = {2,3,8,7,10,23,4,6,4,5};
  /*
  k = rPivot(0,9);
  m = partition(a,0,9,k);
  cout<<endl<<k<<" "<<m<<endl;


  for(int i=0;i<10;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  */
  k = findRank(a,0,9,1);// fourth parameter is the rank
  //k is the index of element whose rank is fourth param
  cout<<a[k]<<endl;
  return 0;
}
