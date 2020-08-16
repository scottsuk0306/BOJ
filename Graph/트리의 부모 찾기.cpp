// 트리의 부모 찾기
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_SIZE 100001
using namespace std;

struct Node {
	int left;
	int right;
};

Node a[MAX_SIZE];
vector<int> v[MAX_SIZE];
int parentOf[MAX_SIZE];

int main(){
	int n;
	scanf("%d",&n);
	parentOf[1] = -1;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if(parentOf[x]!=0||parentOf[y]!=0){
			if(parentOf[x]){
				parentOf[y] = x;
			}
			else{
				parentOf[x] = y;
			}
		}
		
	}
	for(int i=2;i<=n;i++){
		printf("%d\n",parentOf[i]);
	}
}  
