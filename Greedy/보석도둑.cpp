// 보석 도둑: 시간초과 해결해야함. 
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool check[300000];

struct Diamond{
	int mass, value;
};

bool cmp(const Diamond &u, const Diamond &v){
	if(u.value == v.value){
		return u.mass < v.mass;
	}
	else {
		return u.value > v.value;
	}
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<Diamond> v(n);
	vector<int> bag(k);
	for(int i=0;i<n;i++){
		scanf("%d %d",&v[i].mass,&v[i].value);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<k;i++){
		scanf("%d",&bag[i]);
	}
	sort(bag.begin(),bag.end());
	int total=0;
	for(int i=0;i<k;i++){
		int iter=0;
		while(iter<n){
			if(bag[i]>=v[i].mass&&check[i]==false){
				check[i]=true;
				total+=v[i].value;
				break;
			}
		}
	}
	printf("%d",total);
} 
