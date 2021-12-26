#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> x;
vector<int> y;
vector<float> mi;
vector<float> temp;


float distance(int index){

        for(int i = 0; i < index - 1; i++){
          for(int j = 0;j < index;j++){
            if(i !=j)
            temp.push_back(sqrt(pow(x[i] - x[j],2)+pow(y[i] - y[j],2))/2);
            else
            continue;
       }
       mi.push_back(*min_element(temp.begin(), temp.end()));
       vector<float>().swap(temp);
      }

   return *max_element(mi.begin(),mi.end());
}

int main(){
  int count = 0;
  int a = 0;
  int b = 0;


  scanf("%d",&count);

  for(int i = 0; i < count;i++){
    scanf("%d %d",&a,&b);
    x.push_back(a);
    y.push_back(b);
  }

  cout.precision(7);
  cout<<fixed;
  cout<< distance(count) <<endl;
  return 0;

}

