// ¿¬¼ÓÇÕ
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[100001];
int dp[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i<n; i++){
		scanf("%d",&arr[i]);	
	}
	dp[0] = arr[0];
	int ans = dp[0];
	for(int i = 1; i<n; i++){
		dp[i] = max(dp[i-1]+arr[i],arr[i]);
		ans = max(dp[i],ans);
	}
	printf("%d",ans);
} 
