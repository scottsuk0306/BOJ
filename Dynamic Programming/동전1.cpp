// µ¿Àü1
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int coin[101];
int memo[10001][101];
int n,k;
int go(int k){
	int sum=0;
	if(memo[k]!=-1) return memo[k];
	if(k==0) return 1;
	if(k<0) return 0;
	for(int i=;i<n;i++){
		if(k-coin[i]>=0){
			int temp;
			temp=go(k-coin[i]);
			sum+=temp;
		}
	}
	memo[k][y]=sum;
	return sum;
}
int main(){
	memset(memo,-1,sizeof(memo));
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&coin[i]);
	}
	sort(coin,coin+n);
	printf("%d",go(k));
}
