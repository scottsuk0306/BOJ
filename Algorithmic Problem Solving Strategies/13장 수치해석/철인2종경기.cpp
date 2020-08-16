#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
const int MAX = 20;


int N; //number of contestors
int track; //Ʈ������
double runSpeed[MAX], cycleSpeed[MAX]; //�ٴ� �ӵ�, ������ Ÿ�� �ӵ�

double time(int i, double run)
{
    double cycle = track - run;
    return run / runSpeed[i] + cycle / cycleSpeed[i];
}

double difference(double run) // �Լ� (������ �Ÿ��� ���� �����Ǵ� �Լ�) 
{
    double cheater = time(N - 1, run);
    double others = time(0, run);
    for (int i = 1; i < (N - 1);i++)
           others = min(others, time(i, run));
    return others - cheater;
}

double maxDifference(void)
{
    double low = 0, high = track;
    for (int iter = 0; iter < 100; iter++)
    {
       double a = (2 * low + high) / 3; // 1/3 ����
       double b = (low + 2 * high) / 3; // 2/3 ����

       if (difference(a) > difference(b)){
       		high = b;
	   }
       else{
       		low = a;
	   }
    }
    return (low + high) / 2;
}

int main(void)
{
    while(cin >> track)
    {
       cin >> N;

       for (int i = 0; i < N; i++)
            cin >> runSpeed[i] >> cycleSpeed[i];

       double run = maxDifference(); //�޸� ����
       double cycle = track - run; //������ ����
       double timeDiff = difference(run);

       if (timeDiff >= 0.0){
           cout << fixed << setprecision(0);
           cout << "The cheater can win by " << (timeDiff * 3600);
           cout << fixed << setprecision(2);
           cout << " seconds with r = " << run << "km and k = " << cycle << "km." << endl;
       }
       else{
       		cout << "The cheater cannot win." << endl;
	   }
    }
    return 0;
}

