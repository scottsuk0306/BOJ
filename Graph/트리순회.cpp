#include <cstdio>
#include <algorithm>
// 왜 안됨?
// 답 코드에서는 'A'를 빼줘서 수로 저장하는 것 같은데, 왜 이러는 걸까? 
using namespace std;

struct Node {
	char left;
	char right;
};

Node a[50];

void preorder(char x){
	if(x=='.') return;
	printf("%c",x);
	preorder(a[x].left);
	preorder(a[x].right);
}

void inorder(char x){
	if(x=='.') return;
	inorder(a[x].left);
	printf("%c",x);
	inorder(a[x].right);
}

void postorder(char x){
	if(x=='.') return;
	postorder(a[x].left);
	postorder(a[x].right);
	printf("%c",x);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char x,y,z;
		scanf("%c %c %c",&x,&y,&z);
		a[x].left = y;
		a[x].right = z;
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
}
