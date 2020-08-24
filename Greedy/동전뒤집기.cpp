// 동전뒤집기(비트마스크) 
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define MAX_SIZE 21
using namespace std;
char flip(char x){
	if(x=='H') return 'T';
	else return 'H';
}

int main(){
	int n;
	cin>>n;
	vector<string> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=n*n;
	for(int state=0;state<(1<<n);state++){
		int sum=0;
		for(int j=0;j<n;j++){
			int cnt=0;
			for(int i=0;i<n;i++){
				char cur=a[i][j];
				if(state&(1<<i)){
					cur=flip(cur);
				}
				if(cur=='T'){
					cnt+=1;
				}
			}
			sum+=min(cnt,n-cnt);
		}
		if(ans>sum) ans=sum;
	}
	cout<<ans<<'\n';
} 
