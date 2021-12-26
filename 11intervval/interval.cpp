#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//시작점 따로 종료점 따로 배열로 받아서 sort하고  분류
int n,a,b,c;
vector <pair<int,int> >itv;
int ans[200001];
void solution(int start);

int main(){
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin>>n;
  for(int i = 0;i<n;i++){
    cin>>a>>b>>c;
    if(c){//0이면
      itv.push_back(pair<int,int>(a,b));
      continue;
    }
    itv.push_back(pair<int,int>(a+1,b-1));
  }
  sort(itv.begin(),itv.end());
  b = 0;
  solution(0);
  sort(ans,ans+n,greater<int>());

  for(int j = 0;j<n-1;j++){
    cout<<ans[j]<<" ";
  }
  cout<<ans[n-1]<<endl;
  return 0;
}

//<와 <=로 교차 0,1구분하고 교차도 구분

void solution(int start){//start는 기준이 되는 애;

  for(int i = start+1; i < n;i++){//i는 end를 의미 즉 가변
    if(itv[start].second < itv[i].first){
      break;
    }
      ++ans[start];
      ++ans[i];
  }
      ++start;
      if(start < n){
        return solution(start);
      }
      return;
}
