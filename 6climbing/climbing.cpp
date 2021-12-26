#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> player, multi, sum, answer,idex,minis,minis2,minis3;

void input(int a){
  for(int i = 0;i < a;i++){
    int b,p,q,r = 0;
    scanf("%d %d %d %d",&b,&p,&q,&r);
    player.push_back(b);
    multi.push_back(p*q*r);
    sum.push_back(p+q+r);
  }
}

int main(){
  int a,first,second,third,temp,ver = 0;
  scanf("%d",&a);
  input(a);
  answer.push_back(min_element(multi.begin(),multi.end())-multi.begin());
  first = *min_element(multi.begin(),multi.end());

  for(int k = 0;k < a;k++){
    if(multi[k] == first){
      minis.push_back(k);
    }
  }

  if(minis.size() < 4){
    ver = 1;
    multi[min_element(multi.begin(),multi.end())-multi.begin()] = *max_element(multi.begin(),multi.end());
    answer.push_back(min_element(multi.begin(),multi.end())-multi.begin());
    second = *min_element(multi.begin(),multi.end());
    multi[min_element(multi.begin(),multi.end())-multi.begin()] = *max_element(multi.begin(),multi.end());

    answer.push_back(min_element(multi.begin(),multi.end())-multi.begin());
    third = *min_element(multi.begin(),multi.end());
    multi[min_element(multi.begin(),multi.end())-multi.begin()] = *max_element(multi.begin(),multi.end());
    if(first == second){

      if(second == third){ //dd
        idex.push_back(sum[answer[0]]);
        idex.push_back(sum[answer[1]]);
        idex.push_back(sum[answer[2]]);
        sort(idex.begin(),idex.end());

        if(idex[0]==idex[1]){//합이 앞에가 같은 경우
          if(idex[1] == idex[2]){//합이 다같은 경우
            idex.clear();
            idex.push_back(player[answer[0]]);
            idex.push_back(player[answer[1]]);
            idex.push_back(player[answer[2]]);
            sort(idex.begin(),idex.end());
            return printf("%d %d %d\n",idex[0],idex[1],idex[2]);
          }else{
            if(sum[answer[0]] == sum[answer[1]]){
              if(player[answer[0]] > player[answer[1]]){
                temp = answer[0];
                answer[0] = answer[1];
                answer[1] = temp;
              }
            }else if(sum[answer[1]] == sum[answer[2]]){
              if(player[answer[1]] > player[answer[2]]){
                temp = answer[0];
                answer[0] = answer[2];
                answer[2] = temp;
              }
            }else if(sum[answer[0]] == sum[answer[2]]){
              if(player[answer[0]] > player[answer[2]]){
                temp = answer[0];
                answer[0] = answer[2];
                answer[2] = answer[0];
                temp = answer[1];
                answer[1] = answer[2];
                answer[2] = temp;
              }
            }
          }
        }else{//합이 앞은 같지 않은데
          if(idex[1] == idex[2]){//합이 뒤만 같은 경우
            if(sum[answer[0]] == sum[answer[1]]){
              if(player[answer[0]] > player[answer[1]]){
                temp = answer[0];
                answer[0] = answer[1];
                answer[1] = temp;
              }
            }else if(sum[answer[1]] == sum[answer[2]]){
              if(player[answer[1]] > player[answer[2]]){
                temp = answer[0];
                answer[0] = answer[2];
                answer[2] = temp;
              }
            }else if(sum[answer[0]] == sum[answer[2]]){
              if(player[answer[0]] > player[answer[2]]){
                temp = answer[0];
                answer[0] = answer[2];
                answer[2] = answer[1];
                answer[1] = temp;
              }
            }
          }else{//합이 다 다른 경우
            if(sum[answer[0]] > sum[answer[1]]){
              if(sum[answer[1]] < sum[answer[2]]){
                if(sum[answer[0]] < sum[answer[2]]){// 2 0 1
                  temp = answer[0];
                  answer[0] = answer[2];
                  answer[2] = answer[1];
                  answer[1] = temp;
                }else{ // 0 2 1
                  temp = answer[1];
                  answer[1] = answer[2];
                  answer[2] = temp;
                }
              } // 0 1 2
            }else if(sum[answer[0]] <  sum[answer[1]]){
              if(sum[answer[1]] <  sum[answer[2]]){// 2 1 0
                temp = answer[0];
                answer[0] = answer[2];
                answer[2] = temp;
              }else{
                if(sum[answer[0]] >  sum[answer[2]]){// 1 0 2
                  temp = answer[0];
                  answer[0] = answer[1];
                  answer[1] = temp;
                }else{// 1 2 0
                  temp = answer[0];
                  answer[0] = answer[1];
                  answer[1] = answer[2];
                  answer[2] = temp;
                }
              }
            }
          }
        }

      }else{//first == second인데 third는 다름
        if(sum[answer[0]] > sum[answer[1]]){
          temp = answer[0];
          answer[0] = answer[1];
          answer[1] = temp;
        }else if(sum[answer[0]] < sum[answer[1]]){
        }else{//합에서도 같은 경우
          if(player[answer[0]]>player[answer[1]]){
            temp = answer[0];
            answer[0] = answer[1];
            answer[1] = temp;
          }
        }
      }
    }else{// first != second 하지만 second == third일 수 있음
      if(second == third){
        if(sum[answer[1]] > sum[answer[2]]){
          temp = answer[1];
          answer[1] = answer[2];
          answer[2] = temp;
        }else if(sum[answer[1]] < sum[answer[2]]){
        }else{//합에서도 같은 경우
          if(player[answer[1]]>player[answer[2]]){
            temp = answer[1];
            answer[1] = answer[2];
            answer[2] = temp;
          }
        }
      }

    }

  }else{
    answer.clear();
    ver = 2;
    int count = 0;
    for(int j = 0; j < minis.size();j++){
      minis2.push_back(sum[minis[j]]);
    }
    answer.push_back(min_element(minis2.begin(),minis2.end())-minis2.begin());
    first = *min_element(minis2.begin(),minis2.end());


    for(int k = 0; k < minis2.size();k++){
      if(minis2[k] == first){
        minis3.push_back(k);
      }
    }

    if(minis3.size()<4){
      idex.push_back(sum[minis3[0]]);
      idex.push_back(sum[minis3[1]]);
      idex.push_back(sum[minis3[2]]);
      sort(idex.begin(),idex.end());

      if(idex[0]==idex[1]){//합이 앞에가 같은 경우
        if(idex[1] == idex[2]){//합이 다같은 경우
          idex.clear();
          idex.push_back(player[minis3[0]]);
          idex.push_back(player[minis3[1]]);
          idex.push_back(player[minis3[2]]);
          sort(idex.begin(),idex.end());
          return printf("%d %d %d\n",idex[0],idex[1],idex[2]);
        }else{
          if(sum[minis3[0]] == sum[minis3[1]]){
            if(player[minis3[0]] > player[minis3[1]]){
              temp = minis3[0];
              minis3[0] = minis3[1];
              minis3[1] = temp;
            }
          }else if(sum[minis3[1]] == sum[minis3[2]]){
            if(player[minis3[1]] > player[minis3[2]]){
              temp = minis3[0];
              minis3[0] = minis3[2];
              minis3[2] = temp;
            }
          }else if(sum[minis3[0]] == sum[minis3[2]]){
            if(player[minis3[0]] > player[minis3[2]]){
              temp = minis3[0];
              minis3[0] = minis3[2];
              minis3[2] = minis3[0];
              temp = minis[1];
              minis3[1] = minis3[2];
              minis3[2] = temp;
            }
          }
        }
      }else{//합이 앞은 같지 않은데
        if(idex[1] == idex[2]){//합이 뒤만 같은 경우
          if(sum[minis3[0]] == sum[minis3[1]]){
            if(player[minis3[0]] > player[minis3[1]]){
              temp = minis3[0];
              minis3[0] = minis3[1];
              minis3[1] = temp;
            }
          }else if(sum[minis3[1]] == sum[minis3[2]]){
            if(player[minis3[1]] > player[minis3[2]]){
              temp = minis3[0];
              minis3[0] = minis3[2];
              minis3[2] = temp;
            }
          }else if(sum[minis3[0]] == sum[minis3[2]]){
            if(player[minis3[0]] > player[minis3[2]]){
              temp = minis[0];
              minis3[0] = minis3[2];
              minis3[2] = minis3[1];
              minis3[1] = temp;
            }
          }
        }else{//합이 다 다른 경우
          if(sum[minis3[0]] > sum[minis3[1]]){
            if(sum[minis3[1]] < sum[minis3[2]]){
              if(sum[minis3[0]] < sum[minis3[2]]){// 2 0 1
                temp = minis3[0];
                minis3[0] = minis3[2];
                minis3[2] = minis3[1];
                minis3[1] = temp;
              }else{ // 0 2 1
                temp = minis3[1];
                minis3[1] = minis3[2];
                minis3[2] = temp;
              }
            } // 0 1 2
          }else if(sum[minis3[0]] <  sum[minis3[1]]){
            if(sum[minis3[1]] <  sum[minis3[2]]){// 2 1 0
              temp = minis3[0];
              minis3[0] = minis3[2];
              minis3[2] = temp;
            }else{
              if(sum[minis3[0]] >  sum[minis3[2]]){// 1 0 2
                temp = minis3[0];
                minis3[0] = minis3[1];
                minis3[1] = temp;
              }else{// 1 2 0
                temp = minis3[0];
                minis3[0] = minis3[1];
                minis3[1] = minis3[2];
                minis3[2] = temp;
              }
            }
          }
        }
      }
      return printf("%d %d %d\n",minis3[0],minis3[1],minis3[2]);

    }else{
      answer.clear();
      for(int i = 0; i < minis3.size();i++){
        answer.push_back(minis[minis3[i]]);
      }
      minis.clear();
      for(int j = 0; j < answer.size();j++){
        minis.push_back(player[answer[j]]);
      }

    }




  }
  if(ver == 1){
    printf("%d %d %d\n",player[answer[0]],player[answer[1]],player[answer[2]]);
  }else if(ver == 2){
    sort(minis.begin(),minis.end());
    printf("%d %d %d\n",minis[0],minis[1],minis[2]);
  }

  return 0;


}
