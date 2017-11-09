// i have 'n' elements
// i want to design a data structure that answers the following
// in O(log(n)) time
// 1. add
// 2. delete
// 3. find median
#include<iostream>
#include<climits>
using namespace std;

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// A class for Min Heap
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MinHeap(int capacity);

    // function to get size of heap
    int heapSize() { return heap_size; };

    // to heapify a subtree with root at given index
    void MinHeapify(int );

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    int extractMin();

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A class for Max Heap
class MaxHeap
{
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
    MaxHeap(int capacity);

    // function to get size of heap
    int heapSize() { return heap_size; };

    // to heapify a subtree with root at given index
    void MaxHeapify(int );

    int parent(int i) { return (i-1)/2; }

    // to get index of left child of node at index i
    int left(int i) { return (2*i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2*i + 2); }

    // to extract the root which is the minimum element
    int extractMax();

    // Decreases key value of key at index i to new_val
    void increaseKey(int i, int new_val);

    // Returns the minimum key (key at root) from min heap
    int getMax() { return harr[0]; }

    // Deletes a key stored at index i
    void deleteKey(int i);

    // Inserts a new key 'k'
    void insertKey(int k);
};

// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

// Inserts a new key 'k'
void MaxHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    // Fix the max heap property if it is violated
    while (i != 0 && harr[parent(i)] < harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that
// new_val is smaller than harr[i].
void MaxHeap::increaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] < harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MaxHeap::extractMax()
{
    if (heap_size <= 0)
        return INT_MIN;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MaxHeapify(0);

    return root;
}


// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMax()
void MaxHeap::deleteKey(int i)
{
    increaseKey(i, INT_MAX);
    extractMax();
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && harr[l] > harr[i])
        largest = l;
    if (r < heap_size && harr[r] > harr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&harr[i], &harr[largest]);
        MaxHeapify(largest);
    }
}

//functions to get middle element in middle for the first time
int rPivot(int i, int j){
  srand(time(NULL));
  int k=rand()%(j-i+1)+i;
  return k;
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
  int n, n1, n2, e;

  cout<<"Enter initial size : ";
  cin>>n;
  if(n%2!=0){
    n1 = (n/2) +1;
    n2 = n/2;
  }
  else{
    n1 =n/2;
    n2=n/2;
  }
  int a[n];

  cout<<endl<<"Enter elements : ";
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  findRank(a,0,n-1, n2+1);
    cout<<endl<<"\nelements : ";
    for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
    }

  MaxHeap hmax(100);
  MinHeap hmin(100);
  for(int i = 0;i<n1;i++)
    hmax.insertKey(a[i]);

  for(int i = n1;i<n;i++)
    hmin.insertKey(a[i]);

  cout<<endl<<"Sizes of max and min heaps respectively are : "<< hmax.heapSize()<<" "<<hmin.heapSize()<<endl;
  cout<<"Max in max heap is : "<<hmax.getMax()<<endl<<"Min in minheap is : "<<hmin.getMin()<<endl;
  cout<<"Current median is : "<<hmax.getMax()<<endl;
  char ch = 'y';
  while(ch=='y'||ch=='Y'){
    cout<<"Enter new element : ";
    cin>>e;
    if(e<hmax.getMax()){
      hmax.insertKey(e);
    }
    else
      hmin.insertKey(e);

    n1 = hmax.heapSize();
    n2 = hmin.heapSize();
    if(n1 > n2+1){
      e = hmax.extractMax();
      hmin.insertKey(e);
    }
    if(n2 > n1){
      e = hmin.extractMin();
      hmax.insertKey(e);
    }

    cout<<"Now sizes and max-min in maxheap and min heap are : "<<hmax.heapSize()<<","<<hmin.heapSize()<<" : "<<hmax.getMax()<<","<<hmin.getMin();
    cout<<endl<<"wanna enter more ? ";
    cin>>ch;
  }
  return 0;
}
