// 회의실 배정 
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Meeting {
	int begin, end;
};

// 먼저 끝나는 회의를 먼저 배정한다.
// 끝나는 시간이 같을 땐, 시작시간이 빠른 것을 배정한다. 
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
		scanf("%d %d", &a[i].begin,&a[i].end);
	}
	sort(a.begin(),a.end(),cmp);
	int now=0;
	int ans=0;
	for(int i=0;i<a.size();i++){
		if(now<=a[i].begin){
			now=a[i].end;
			ans+=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
