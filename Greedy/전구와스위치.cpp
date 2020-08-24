// 2138: 전구와 스위치 
#include <cstdio>
#include <vector>
using namespace std;
int n;

void check_all(vector<int> a){
	for(int i=0;i<a.size();i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
void flip(vector<int> &a,int x){
	for(int i=x-1;i<=x+1;i++){
		if(i>=0&&i<n){
			a[i]=1-a[i];
		}
	}
	return;
}

int go(vector<int> a, vector<int> &b){
	int ans=0;
	for(int i=0;i<n-1;i++){
		if(a[i]!=b[i]){
			flip(a,i+1);
			ans+=1;
			//check_all(a);
		}
	}
	if(a[n-1]==b[n-1]) return ans;
	else return -1;
}

int main(){
	scanf("%d",&n);
	vector<int> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++){
		scanf("%1d",&a[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%1d",&b[i]);
	}
	int r1=go(a,b);
	//printf("this is r1: %d\n",r1);
	flip(a,0);
	//printf("check:"); check_all(a);
	int r2=go(a,b);
	if(r2!=-1) r2+=1;
	//printf("this is r2: %d\n",r2);
	if(r1*r2<0){
		if(r1==-1) printf("%d",r2);
		else printf("%d",r1);
	}
	else if(r1==-1&&r2==-1){
		printf("-1");
	}
	else{
		printf("%d",min(r1,r2));
	}
}
