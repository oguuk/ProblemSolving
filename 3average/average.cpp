#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>vec;

int num = 0;
int temp = 0;
float compare = 1; //몇개의 인덱스와 비교할건지
int answer = 0; //답안

void makeVec(int num){
  for(int i = 0;i < num;i++){
    scanf("%d",&temp);
    vec.push_back(temp);
  }
}

int check(int n){ //몇개까지 같은지 확인

 for(int i = 0;i+compare <num;i++){
   float add = 0;
   float division = 0;
   vector<int>vec2;
   vec2 = vec;

   for(int j = 0; j <=compare;j++){
      add += vec[i+j];

      if(j==compare){
       division = add/(compare+1);
       sort(vec2.begin()+i,vec2.begin()+i+compare);
       if(binary_search(vec2.begin()+i,vec2.begin()+i+compare,division)){
         answer+=1;

       }
     }

   }

   if(i+compare == num -1){
     compare++;
     check(compare);
   }
 }

  return num+answer;
}


int main(){

  scanf("%d",&num);
  makeVec(num);
  cout<< check(1);

  return 0;
}
