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
  int n, m, k, mid, middle;
  cout<<"Enter number (n) of elements : ";
  cin>>n;
  m = n;
  cout<<"How many (k) largest numbers you want ? ";
  cin>>k;
  int tk = 2 * k;
  int a[tk];
  for(int i=0; i < tk ;i++){
    cin>>a[i];
    m--;
  }

  mid = findRank(a,0,tk-1, k+1 );

  while(m-k >= 0){
    for(int i = 0; i<k;i++){
      cin>>a[i];
      m--;
    }
    findRank(a,0,tk-1, k+1 );

  }
  if(m>0){
    for(int i =0;m>0;i++){
      cin>>a[i];
      m--;
    }
    findRank(a,0,tk-1, k+1 );


  }
  cout<<endl;
  for(int i=k;i<tk;i++)
    cout<<a[i]<<" ";

    cout<<endl;
  //cout<<endl<<a[mid]<<endl;



  return 0;
}
