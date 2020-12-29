// Επ»η
#include <stdio.h>
#include <algorithm>
using namespace std;
int length[17];
int price[17];
int dp[17];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&length[i],&price[i]);
	}
	dp[0] = 0;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<i;j++){
			if(i>(length[j]+j-1)){
				dp[i] = max(dp[i],dp[j]+price[j]);
			}
		}
	}
	printf("%d",dp[n+1]);
} 
