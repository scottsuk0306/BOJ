// 1149
#include <stdio.h>
#include <algorithm>
#define MAXNUM 1000000
using namespace std;
int map[1001][3];
int dp[1001][3];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=1; i<=n; i++){
		dp[i][0] = MAXNUM;
		dp[i][1] = MAXNUM;
		dp[i][2] = MAXNUM;
	}
	dp[1][0] = map[1][0];
	dp[1][1] = map[1][1];
	dp[1][2] = map[1][2];
//	int prev = min({dp[1][0],dp[1][1],dp[1][2]});
//	for(int j = 0; j<3; j++){
//		if(prev == dp[1][j]){
//			prev = j
//			break;
//		}
//	}
	for(int i=2; i<=n; i++){
		dp[i][0] = min(dp[i-1][1] + map[i][0],dp[i-1][2] + map[i][0]);
		dp[i][1] = min(dp[i-1][0] + map[i][1],dp[i-1][2] + map[i][1]);
		dp[i][2] = min(dp[i-1][0] + map[i][2],dp[i-1][1] + map[i][2]);
	}
	int ans = MAXNUM;
	for(int j=0;j<3;j++){
		if(ans >= dp[n][j]){
			ans = dp[n][j];
		}
	}
	printf("%d",ans);
}
