#include <iostream>
#include <vector>
using namespace std;
void test(vector<int> &a){
	cout<<a.size();
}
int main(){
	vector<int> v;
	for(int i=0;i<100;i++){
		v.push_back(i);
	}
	test(v);
}
