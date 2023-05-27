0#include<bits/stdc++.h>
using namespace std;
// dp[i][j] = 1~i까지 수들로 inversion이 j개 
// dp[i][j] = dp[i-1][j-i+1] + .... dp[i-1][j]
// dp[i][j-1] = dp[i-1][j-i] + .... + dp[i-1][j-1]
// dp[i][j] - dp[i][j-1] = dp[i-1][j] - dp[i-1][j-i]
// dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-i]
int dp[1005][10005];
const int MOD = 1e9+7;
int main()
{
	int N, M; cin >> N >> M;
	dp[0][0] = 1;
	for(int i=1; i<=N; i++)
		for(int j=0; j<=M; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j>=1) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
			if(j>=i) dp[i][j] = (dp[i][j] + MOD - dp[i-1][j-i]) % MOD;
		}
	cout<<dp[N][M];
}
