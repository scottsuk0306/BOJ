#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
stack<int> s;
int main(){
	int n,value;
	scanf("%d %d",&n,&value);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d",&temp);
		s.push(temp);
	}
	int count = 0;
	while(value!=0){
		if(value/s.top()){
			int quotient=value/s.top();
			value-=(s.top()*quotient);
			s.pop();
			count+=quotient;
		}
		else s.pop();
	}
	printf("%d",count);
}
