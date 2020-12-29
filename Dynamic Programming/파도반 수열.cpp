// 파도반 수열
#include <stdio.h>
#include <algorithm>
using namespace std;
long long int dp[101] = {0,1,1,1,2,2,};
int main(){
	int t;
	scanf("%d",&t);
	for(int i=6; i<=100; i++){
		dp[i] = dp[i-1]+dp[i-5];
	}
	for(int i=1;i<=t;i++){
		int n;
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	
} 
