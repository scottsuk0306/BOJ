// 회의실 배정 
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Meeting {
	int begin, end;
};

bool cmp(const Meeting &u, const Meeting &v){
	if(u.end == v.end){
		return u.begin < v.begin;
	}
	else {
		return u.end < v.end;
	}
}

int main(){
	int n;
	scanf("%d",&n);
	vector<Meeting> a(n);
	for(int i=0;i<n;i++){
		scanf("%d %d", &a[i].begin(),&a[i].end);
	}
	sort(a.begin(),a.end(),cmp); // 이거 작동원리 뭐임?
	int now=0;
	int ans=0;
	for(int i=0;) 
}
