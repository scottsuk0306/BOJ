#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <climits>
using namespace std;
/*
 극값을 알아야 한다. -> 미분
 1차 2차방정식은 바로 풀  수 있다.
 방정식의 해는 모두 다르다 : 상수x, 중근x
*/
const double L = 25; // 해의 절대값은 L이하.

vector<double>diffrentiate(const vector<double>& poly) // [3,4,2,1]
{
	int n = poly.size() - 1;

	vector<double> ret;

	for (int i = 0; i < n; ++i)
		ret.push_back((n - i)*poly[i]); // [9,8,2,0]

	return ret;
}

/* 일차 방정식과 이차방정식은 해법이 존재하므로 이분법 사용 X */
vector<double>solveNaive(const vector<double>& poly)
{
	int n = poly.size() - 1;
	
	vector<double>ret;
	if (n == 1) ret.push_back(-poly[1] / poly[0]);
	if (n == 2)
	{
		double a = poly[0], b = poly[1], c = poly[2];
		ret.push_back((-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		ret.push_back((-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
	}
	// 근은 항상 정렬된 형태로.
	sort(ret.begin(), ret.end());
	return ret;
}

double evaluate(const vector<double>& poly, double x0)
{
	int n = poly.size() - 1;
	
	double ret = 0;

	for (int i = 0; i < n + 1; ++i)
		ret += poly[i] * pow(x0, n - i);

	return ret;
}

vector<double>solve(const vector<double>& poly)
{
	int n = poly.size() - 1;
	if (n <= 2) return solveNaive(poly);

	vector<double>ret;
	vector<double>derivative = diffrentiate(poly);
	vector<double>sols = solve(derivative); // 극값이 다 들어있음 

	sols.insert(sols.begin(), -L - 1);
	sols.insert(sols.end(), L + 1);

	for (int i = 0; i < sols.size() - 1; ++i)
	{
		double x1 = sols[i], x2 = sols[i + 1];
		double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);

		// 같은 부호면 해가 없다.
		if (y1 * y2 > 0) continue;
		// f(x1) <= 0 < f(x2) // 불변식 (x1 > x2 여도 상관x)
		if (y1 > y2) swap(y1, y2), swap(x1, x2);

		for (int iter = 0; iter < 100; ++iter)
			// 실수값에 대한 해를 구하기 위해선 100번정도 반복한다.
		{
			double mx = (x1 + x2) / 2;
			double my = evaluate(poly, mx);
			
			if (my <= 0) x1 = mx;
			else x2 = mx;
		}
		ret.push_back((x1 + x2) / 2);
	}
	sort(ret.begin(), ret.end());
	return ret;
}
int main()
{
	int testcase, N;
	cin >> testcase;
	while (testcase--)
	{
		cin >> N;
		vector<double>poly(N + 1);

		for (int i = 0; i < N + 1; ++i) cin >> poly[i];

		vector<double>ret = solve(poly);
		for (auto i : ret)
			printf("%.12lf ", i);
		puts("");
	}
	return 0;
}
