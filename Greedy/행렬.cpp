#include <cstdio>
#include <algorithm>
using namespace std;
int a[51][51];
int b[51][51];

void flip(int x,int y){
	for(int i=x;i<x+3;i++){
		for(int j=y;j<y+3;j++){
			a[i][j]=1-a[i][j];
		}
	}
	return;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int j=0;j<n;j++){
		for(int k=0;k<m;k++){
			scanf("%1d",&a[j][k]);
		}
	}
	for(int j=0;j<n;j++){
		for(int k=0;k<m;k++){
			scanf("%1d",&b[j][k]);
		}
	}
	int ans = 0;
	for(int i=0;i<n-2;i++){
		for(int j=0;j<m-2;j++){
			if(a[i][j]!=b[i][j]){
				flip(i,j);
				ans++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]!=b[i][j]){
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d",ans);
	
}
