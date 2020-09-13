#include <cstdio>
using namespace std;
 
int A, B, C;
 
long long int power(int n, int k){
    if(k == 0) return 1;
 
    long long int temp = power(n, k/2);
    long long int result = temp * temp % C;
    if(k%2==1) result = result * n % C;
    return result;
}
 
int main(){
    scanf("%d %d %d", &A, &B, &C);
    printf("%lld\n", power(A, B));
}
 
