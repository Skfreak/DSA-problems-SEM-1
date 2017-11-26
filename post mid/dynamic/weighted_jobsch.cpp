#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Job{
  int start;
  int end;
  int weight;
};

// defining a new function for the stl sort() function to sort struct Job
// on the basis of its data members
bool fcompare( Job j1, Job j2 ){  return j1.end < j2.end; }

//function for weighted job scheduling
void weightedSchedule(Job job[], int n){
  int i, j, res[n], pos[n];
  //res[n] shows final values after scheduling jobs
  //pos[n] stores the positions or indices to backtrack

  //initialing pos and res arrays
  for(i=0;i<n;i++){
    res[i] = job[i].weight;
    pos[i] = -1;
  }

  int MAX = -1, index = -1;

  //running aactual algorithm
  for(i=1;i<n;i++){
    for(j=0;j<i;j++){
      if(job[i].start >= job[j].end ){
        res[i] = max(res[i], res[j] + job[i].weight);
        pos[i] = j;
        if(MAX < res[i]){
          MAX = res[i];
          index = i;
        }
      }
    }
  }
  cout<<endl<<"Maximum profit is : "<<MAX;
  cout<<endl<<"Jobs scheduled are (in reverse order) : ";
  while(index != -1){
    cout<<"("<<job[index].start<<","<<job[index].end<<")[";
    cout<<job[index].weight<<"]  ";
    index = pos[index];
  }

}

int main(){
  Job j[6] = {  {1, 3, 5},
                {5, 8, 11},
                {4, 6, 5},
                {6, 7, 4},
                {2, 5, 6},
                {7, 9, 2}
              };
  sort(j, j+6, fcompare);

  int n = sizeof(j)/sizeof(j[0]);
  /*
  for(int i =0;i<6;i++){
    cout<<j[i].end<<" ";
  }
  */
  weightedSchedule(j, n);

  cout<<endl;
  return 0;
}
