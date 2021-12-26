#include<iostream>
#include<algorithm>

using namespace std;

int clicked[100001];
int unclicked[100001];

int n;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>clicked[i];
	}

  copy(clicked,clicked+n,unclicked);

  clicked[0] = 1 - clicked[0];
  clicked[1] = 1 - clicked[1];



	int sum1 = 1;
	int sum2 = 0;

	for (int i = 1; i < n - 1; i++) {
		if (clicked[i - 1] != 0) {
			for (int j = i - 1; j <= i + 1; j++) {
				clicked[j] = 1 - clicked[j];
			}
			sum1++;
		}
		else continue;
	}

	if (clicked[n - 2] != 0) {
		clicked[n - 2] = 1 - clicked[n - 2];
		clicked[n - 1] = 1 - clicked[n - 1];
		sum1++;
	}

	for (int i = 1; i < n - 1; i++) { 
		if (unclicked[i - 1] != 0) {
			for (int j = i - 1; j <= i + 1; j++) {
				unclicked[j] = 1 - unclicked[j];
			}
			sum2++;
		}
		else continue;
	}

	if (unclicked[n - 2] != 0) {
		unclicked[n - 2] = 1 - unclicked[n - 2];
		unclicked[n - 1] = 1 - unclicked[n - 1];
		sum2++;
	}

	bool ans1,ans2 = true;

	for (int i = 0; i < n; i++) {
		if (clicked[i] != 0) {
			ans1 = false;
		}
		if (unclicked[i] != 0) {
			ans2 = false;
		}
	}

	if (ans1 && ans2) {
		cout<<min(sum1, sum2)<<endl;
	}
	else if (ans1) {
		cout<<sum1<<endl;
	}
	else if (ans2) {
		cout<<sum2<<endl;
	}
	else cout<<"impossible\n";

}
