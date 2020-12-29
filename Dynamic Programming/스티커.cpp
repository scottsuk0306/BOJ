// ½ºÆ¼Ä¿
#include <stdio.h>
#include <algorithm>
#define MAXNUM 100001
using namespace std;
int sticker[2][MAXNUM];
int dp[MAXNUM];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<2;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&sticker[i][j]);
			}
		}
		dp[0] = 0;
		int prev = -1;
		if(sticker[0][1]>sticker[1][1]){
			dp[1] = sticker[0][1];
			prev = 0;
		}
		else{
			dp[1] = sticker[1][1];
			prev = 1;
		}
		int temp;
		for(int i=2;i<=n;i++){
			temp = max(sticker[0][i],sticker[1][i]);
			if(temp == sticker[1-prev][i]){
				dp[i] = dp[i-1]+temp;
				prev = 1-prev;
			}
			else {
				dp[i] = max(dp[i-1]+sticker[1-prev][i],dp[i-2]+temp);
				if(dp[i]!=(dp[i-2]+temp)) prev = 1-prev;
			}
		}
		printf("dp: ");
		for(int i=1;i<=n;i++){
			printf("%d ",dp[i]);
			
		}
		printf("\n");
		printf("%d\n",dp[n]);
	}
}
