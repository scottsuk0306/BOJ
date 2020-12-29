// 가장 긴 증가하는 부분수열
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1001];
int dp[1001];
int pre[1001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		scanf("%d",&arr[i]);
	}
	dp[0] = 1;
	int ans = dp[0];
	int temp;
	for(int i=1;i<n;i++){
		dp[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				if(dp[i]<dp[j]+1){
					pre[i] = j;
					dp[i] = dp[j]+1;	
				}
			}
		}
		if(dp[i]>ans) {
			temp = i;
		}
		ans = max(dp[i],ans);
	}
	printf("%d\n",ans);
	vector<int> v; 
	while(true){
		v.push_back(arr[temp]);
		if(temp == pre[temp]) break;
		temp = pre[temp];
	}
	while(!v.empty()){
		int k = v.back();
		v.pop_back();
		printf("%d ",k);
	}
}
