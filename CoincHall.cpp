#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll coinchange(ll array2[],ll m,ll n)
{
	ll array1[m+1][n+1];
	for(ll i=0;i<m+1;i++)
	{
		array1[i][0]=1;
	}
	for(ll j=0;j<n+1;j++)
	{
		array1[0][j]=0;
	}
	for(ll i=1;i<m+1;i++)
	{
		for(ll j=1;j<n+1;j++)
		{
			if(array2[i-1]>j)
			{
				array1[i][j]=array1[i-1][j];
			}
			else
			{
				array1[i][j]=(array1[i-1][j]+array1[i][j-array2[i-1]]);
			}
		}
	}
return array1[m][n];
}
int main()
{
	ll n;
	cin>>n;
	ll m;
	cin>>m;

	ll array1[m];
	for(ll i=0;i<m;i++)
		cin>>array1[i];
	cout<<coinchange(array1,m,n);
}
