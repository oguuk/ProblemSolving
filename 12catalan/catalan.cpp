#include <iostream>
using namespace std;

int ans[19];
int n;

void solution(int a){
  if(a <= n){
    if(a > 1){
      for(int i = 0;i < a;i++){
        ans[a] += ans[i]*ans[a-1-i];
      }
    }
    ++a;
    return solution(a);
  }
  return;
}

int main(){
  cin>>n;
  ans[0] = 1;
  ans[1] = 1;
  solution(0);
  cout<<ans[n]<<endl;
  return 0;
}
