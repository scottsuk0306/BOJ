#include <iostream>

using namespace std;
const long long L = 2000000000;
long long N, Win; //총 게임수, 이긴 게임수

int ratio(long long b, long long a)
{
    return (a * 100) / b;
}

int neededGames(long long games, long long won)
{
    if (ratio(games, won) == ratio(games + L, won + L)){
    	return -1;
	}
	long long low = 0, high = L;


    while(low + 1 < high)
    {
       long long mid = (low + high) / 2;

       if (ratio(games, won) == ratio(games + mid, won + mid)){
       		low = mid;
	   }
       else{
       		high = mid;
	   }
    }
    return high;
}

int main(void)

{
    int test_case;
    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
           cin >> N >> Win;
           if (N < 1 || N>1000000000 || Win<0 || Win>N) // 문제 조건 
                exit(-1);
           cout << neededGames(N, Win) << endl;
    }
    return 0;
}

