#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool check(int idx, bool flag);
int n, k;
int countO[1000001], countI[1000001], outCheck, inCheck = 1;

int main() {
  //  cin.tie(0);
  //  cout.tie(0);
  //  ios::sync_with_stdio(false);
  //  cin >> n >> k;
  ifstream fin("/Users/ain/Desktop/Downloads/in02.txt");//
  fin>>n>>k;
    outCheck = k;
    int a = -1, b = 0, answer = n + 1;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        //cin >> vec[i];
        fin >> vec[i];
        ++countO[vec[i]];
    }
    ++countI[vec[0]];
    --countO[vec[0]];

    outCheck = countO[vec[0]] == 0 ? outCheck - 1 : outCheck;
    while (1) {
        if (inCheck < k){
            if (++b == n) {
                break;
            }
            if (check(vec[b], 1)) {
                answer = min(answer, b - a);
            }
        }else if (check(vec[++a], 0)){
            answer = min(answer, b - a);
            cout<<"a는 "<<a<<endl;
        }
    }
    cout << ((answer == n + 1) ? 0 : answer)<<endl;
    return 0;
}

bool check(int idx, bool flag){
    if (flag) {
        if (--countO[idx] == 0) --outCheck;
        if (++countI[idx] == 1) ++inCheck;
    } else {
        if (++countO[idx] == 1) ++outCheck;
        if (--countI[idx] == 0) --inCheck;
    }
    return outCheck == k && inCheck == k;
}
