#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


vector<bool>vec;
int arr[4] = {1,2,2,3};
int a,b,c,d,n= 0;

int check(int num){
for(int i = 0; i <num;i++){
  a = arr[0];
  b = arr[1];
  c = arr[2];
  d = arr[3];

  arr[0] = a+b;
  arr[1] = b+c;
  arr[2] = c+d;
  arr[3] = d+arr[0];
}
if(!(n%4))return arr[3];
  return arr[(n%4)-1];
}

int main(){
  scanf("%d",&n);
  int num = ceil((float)n/4)-1;

  cout<<check(num)%20201212<<endl;
  if(n<=30){
  }

  return 0;
}
