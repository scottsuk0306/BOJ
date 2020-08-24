// ÆÓ¸°µå·Ò?
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int s[2001];
int memo[2001][2001];
int go(int a, int b){
	if(a==b){
		return 1;
	}
	if(memo[a][b]!=0){
		return memo[a][b];
	}
	if(s[a]==s[b]){
		if(b-1>=a+1){
			memo[a][b]=go(a+1,b-1);
		}
		else memo[a][b]=1;
	}
	else memo[a][b]=-1;
	return memo[a][b];
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int S,E;
		scanf("%d %d",&S,&E);
		int result=go(S-1,E-1);
		if(result<0) result=0;
		printf("%d\n",result);
	}
} 
