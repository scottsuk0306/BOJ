// 계단오르기
#include <stdio.h>
#include <algorithm>
using namespace std;
int stairs[301];
int dp[301];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&stairs[i]);
	}
	dp[0] = 0;
	dp[1] = stairs[1];
	dp[2] = stairs[2]+stairs[1];
	for(int i=3; i<=n; i++){
		dp[i] = max(dp[i-2]+stairs[i],dp[i-3]+stairs[i-1]+stairs[i]);
	}
	printf("%d",dp[n]);
	
} 
