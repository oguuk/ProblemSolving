#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int sonny(int first,int last, int *arr);
int solution(int *lists);
int solution2(int *lists);

int n,x = 0;

int main(){

  float answer2=0;
  scanf("%d %d",&n,&x);

  int lists[n];
  for(int i=0;i<n;i++){
    scanf("%d",&lists[i]);
  }
  int list2[n];
  memcpy(list2,lists,sizeof(lists));

  sort(lists,lists+n,greater<int>());
  sort(list2,list2+n);
  answer2 = solution(lists) <= solution2(list2) ? solution(lists) : solution2(list2);
  printf("%.0f\n",answer2);

  return 0;
}

int solution(int *lists){
  float answer = 0;
  int h = n/3;
  int l = n%3;
  if(h>0){
    for(int i = 1;i<=h;i++){
      answer+= sonny(3*i-3,3*i,lists) >= lists[i*3-3]+lists[i*3-2] ? lists[i*3-3]+lists[i*3-2] : sonny(3*i-3,3*i,lists);
    }
    if(l > 0){
        answer += sonny(3*h,3*h+l,lists);
    }
  }else{
    for(int k =0; k <l;k++){
        answer += lists[k] - (lists[k]*(x*0.01));
    }
  }
  return answer;
}

int solution2(int *lists){
  float answer = 0;
  int h = n/3;
  int l = n%3;
  if(h>0){
    for(int i = 1;i<=h;i++){
      answer+= sonny(3*i-3,3*i,lists) >= lists[i*3-2]+lists[i*3-1] ? lists[i*3-2]+lists[i*3-1] : sonny(3*i-3,3*i,lists);
    }
    if(l > 0){
        answer += sonny(3*h,3*h+l,lists);
    }
  }else{
    for(int k =0; k <l;k++){
        answer += lists[k] - (lists[k]*(x*0.01));
    }
  }
  return answer;
}

int sonny(int first,int last,int *arr){//x% 할인
  int temp = 0;
  for(int j = first;j<last;j++){
    temp += arr[j] - (arr[j]*(x*0.01));
  }
  return temp;
}
