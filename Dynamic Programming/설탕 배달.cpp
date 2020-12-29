// DP
#include <stdio.h>
#include <algorithm>
#define MAXNUM 100000
using namespace std;
int dp[5001];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<=n; i++){
		dp[i] = MAXNUM;
	}
	dp[0] = 0;
	for(int i = 3; i<=n; i++){
		if(i<5) {
			dp[i] = min(dp[i-3]+1,dp[i]);
		}
		else dp[i] = min(dp[i-3]+1,dp[i-5]+1);
	}
	if(dp[n] >= MAXNUM){
		printf("-1");
	}
	else printf("%d",dp[n]);
}
