#include<bits/stdc++.h>
using namespace std;
int arr[100005], brr[100005];
vector<int> even, odd;
int main()
{
	int N; cin>>N;
	for(int i=0; i<N; i++)
	{
		cin>>arr[i];
		if(i%2==0) even.push_back(arr[i]);
		else odd.push_back(arr[i]);
	}
	
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	sort(arr, arr+N);
	
	for(int i=0; i<N; i++)
	{
		if(i%2 == 0) brr[i] = even[i/2];
		else brr[i] = odd[i/2];
	}
	
	for(int i=0; i<N; i++)
	{
		if(arr[i] != brr[i])
		{
			cout<<0; return 0;
		}
	}
	cout<<1;
}
