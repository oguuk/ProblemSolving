#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>vec,vec2;

int num,temp,answer,coun = 0;

void makeVec(int num){
  for(int i = 0;i < num;i++){
    scanf("%d",&temp);
    vec.push_back(temp);
  }
}

int minimum(int num){
  for(int i = 0;i < num;i++){
    if(!vec[i]){
      if(coun){
        int min2 = *min_element(vec2.begin(), vec2.end());
        int max2 = *max_element(vec2.begin(), vec2.end());
        if(min2 == max2){
          for(int k = i - coun;k < i;k++){
            vec[k] = 0;
          }
        }else{
          for(int k = i - coun;k < i;k++){
            vec[k] = vec[k] - min2;
          }
        }
        answer +=1;
        coun = 0,min2 = 0, max2 = 0;
        vec2.clear();
      }
    }else{
      coun+=1;
      vec2.push_back(vec[i]);
    }

    if(i == num -1){
      if(coun){
        int min2 = *min_element(vec2.begin(), vec2.end());
        int max2 = *max_element(vec2.begin(), vec2.end());
        if(min2 == max2){
          for(int k = i + 1 - coun;k <= i;k++){
            vec[k] = 0;
          }
        }else{
          for(int k = i + 1 - coun;k <= i;k++){
            vec[k] = vec[k] - min2;
          }
        }
        answer +=1;
        coun = 0,min2 = 0, max2 = 0;
        vec2.clear();
      }
        if(*max_element(vec.begin(), vec.end())){
          coun = 0;
          return minimum(num);
        }else{
          return answer;
        }
    }//마지막확인
  }//for
  return answer;
}

int main(){
  scanf("%d",&num);
  makeVec(num);
  cout<<minimum(num);
  return 0;
}
