#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	int a[13];
	int b[13];
	while(true){
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			if(i<6) b[i]=0;
			else b[i]=1;
		}
		//sort(b,b+n);
		do{
			for(int i=0;i<n;i++){
				if(!b[i]){
					cout<<a[i]<<" ";
				}
			}
			cout<<'\n';
			
		}while(next_permutation(b,b+n));
		cout<<'\n';
		
		
	}
}
