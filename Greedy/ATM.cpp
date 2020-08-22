#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += (n-i)*v[i];
	}
	printf("%d",sum);
} 
