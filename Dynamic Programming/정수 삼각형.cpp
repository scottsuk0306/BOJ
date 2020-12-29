// Á¤¼ö »ï°¢Çü
#include <stdio.h>
#include <algorithm>
using namespace std;
int map[501][501];
int dp[501][501];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			map[i][j] = -1;
			// dp[i][j] = ;
		}
	}
	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<i+1; j++){
			scanf("%d",&map[i][j]);
		}
	}
	
	dp[0][0] = map[0][0];
	for(int i = 1; i<n; i++){
		for(int j =0; j<i+1; j++){
			dp[i][j] = max(dp[i-1][j]+map[i][j],dp[i-1][j-1]+map[i][j]);
		} 
	}
//	for(int i = 0; i<n; i++){
//		for(int j = 0; j<i+1; j++){
//			printf("%d ",map[i][j]);
//		}
//		printf("\n");
//	}
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(ans < dp[n-1][i]){
			ans = dp[n-1][i];
		}
	}
	printf("%d",ans);
	
	
	
} 
