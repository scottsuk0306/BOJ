// 2138: 전구와 스위치 
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000001];
int b[1000001];
int n;

void flip(int x){
	for(int i=x-1;i<=x+1;i++){
		if(i>0&&i<n){
			a[i]=1-a[i];
		}
	}
	return;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%1d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%1d",&b[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			flip(i);
			ans++;
			printf("%d\n",a[i]);
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			printf("-1");
			return 0;
		}
	}
	printf("%d",ans);
}
