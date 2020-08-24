// 1,2,3 ¥ı«œ±‚ 4
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int memo[10000][4];
int go(int n, int y){
	if(n==1&&y==1) return 1;
	if(n==2&&y!=3) return 1;
	if(n==3) return 1;
	else if(n<=3) return 0;
	if(memo[n][y]>0){
		return memo[n][y];
	}
	if(y==1){
		memo[n][y]=go(n-1,1);
	}
	else if(y==2){
		memo[n][y]=go(n-2,1)+go(n-2,2);
	}
	else{
		memo[n][y]=go(n-3,1)+go(n-3,2)+go(n-3,3);
	}
	return memo[n][y]; 
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",go(n,1)+go(n,2)+go(n,3));
	}
}
