#include<bits/stdc++.h>
using namespace std;
int vst[400005];
vector<int> arr;
bool chk(int x, int diff) // diff를 넘는 차이를 내면서 x쌍을 만들 수 있는가?
{
	for(int i=0; i<x; i++)
	{
		if(arr[arr.size()-x+i] - arr[i] <= diff) return false;
	}
	return true;
}
int main()
{
	int N,M,K,x,y; cin>>N>>M>>K;
	for(int i=1; i<=M; i++)
	{
		cin>>x>>y;
		vst[x] = vst[y] = true;
	}
	cin>>x>>y; vst[x] = vst[y] = true;
	int sc = abs(x%K - y%K);
	for(int i=1; i<=4*N; i++)
	{
		if(vst[i] == false)
		{
			arr.push_back(i%K);
		}
	}
	sort(arr.begin(), arr.end());
	
	int ans = 0;
	int L=0, R=arr.size()/2;
	while(L<R)
	{
		int mid = (L+R+1)/2;
		if(chk(mid, sc)) L=mid;
		else R=mid-1;
	}
	cout<<min(M-1, L);
}
