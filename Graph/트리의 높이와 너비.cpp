// 트리의 높이와 너비 
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX_SIZE 10001
using namespace std;

struct Node {
	int left;
	int right;
};

Node a[MAX_SIZE];
vector<int> v[MAX_SIZE];
int cnt = 1;
bool isChild[MAX_SIZE];

void inorder(int x, int h) {
    if (x == -1) return;
    h++;
    inorder(a[x].left,h);
    v[h-1].push_back(cnt++);
    inorder(a[x].right,h);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if (y==-1){
			a[x].left = -1;
		} 
		else {
			 a[x].left = y;
			 isChild[y] = true;
		}
		if(z==-1) {
			a[x].right = -1;
		}
		else {
			a[x].right = z;
			isChild[z] = true;
		}
	}
	int root;
	for(int i=1;i<=n;i++){
		if(isChild[i]==false){
			root = i;
			break;
		}
	}
	inorder(root,1);
	int maxi = 0;
	int curheight = 0;
	for(int i=1;v[i].size()!=0;i++){
		if((-v[i][0]+v[i][v[i].size()-1]+1)>maxi){
			maxi = -v[i][0]+v[i][v[i].size()-1]+1;
			curheight = i;
		}
		// printf("%d %d %d\n",v[i][0],v[i][v[i].size()-1],i);
	}
	printf("%d %d",curheight,maxi);
} 
