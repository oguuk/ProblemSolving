#include <iostream>
using namespace std;

int m,n;
long long a[4010],b[4010],c[4010];
double dp[4010][31];
bool check[4010][31];

double solution(int first,int second)
{
	if(check[first][second]) return dp[first][second];
	check[first][second]=true;
	if(second==1)
	{
		double mean=(double)b[first]/first;
		return dp[first][second]=mean*mean*first-2*mean*b[first]+c[first];
	}
	double now=1e20;
	for(int i=first;i>=second;i--)
	{
		double mean=(double)(b[first]-b[i-1])/(first-i+1);
		now=min(now,solution(i-1,second-1)+mean*mean*(first-i+1)-2*mean*(b[first]-b[i-1])+c[first]-c[i-1]);
	}
	return dp[first][second]=now;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
		c[i]=c[i-1]+a[i]*a[i];
	}
	if(m>=n)
	{
		cout<<0;
		return 0;
	}
	cout<<fixed;
	cout.precision(6);
	cout<<solution(n,m)<<endl;
}
