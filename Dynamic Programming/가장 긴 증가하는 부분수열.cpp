// 가장 긴 증가하는 부분수열
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001]; 
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		scanf("%d",&arr[i]);
	}
	dp[0] = 1;
	int ans = dp[0];
	for(int i=1;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[i]<arr[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		ans = max(dp[i],ans);
	}
	printf("%d",ans);
} 
