// 20.1
// '집더미' H의 부분 물자열로 '바늘' N이 출현하는 시작 위치들을 모두 반환한다. 
vector<int> naiveSearch(const string &H, const string &N){
	vector<int> ret;
	// 모든 시작 위치를 다 시도해 본다.
	for(int begin = 0; begin + N.size() <= H.size(); ++begin){
		bool matched = true;
		for(int i = 0; i < N.size(); ++i){
			if(H[begin + i] != N[i]){
				matched = false;
				break;
			}
		}
		if(matched) ret.push_back(begin);
	}
	return ret;
	
}

// 20.2
// '집더미' H의 부분 문자열로 '바늘' N이 출현하는 시작 위치들을 모두 반환한다. 
vector<int> kmpSearch(const string& H, const string& N){
	int n = H.size(), m = N.size();
	vector<int> ret;
	// p[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
	vector<int> pi = getPartialMatch(N);
	// begin = matched = 0 에서부터 시작하자.
	int begin = 0, matched = 0;
	while(begin <= n-m){
		// 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if(matched < m && H[begin+matched] == N[matched]){
			++matched;
			// 결과적으로 m글자가 모두 일치했다면 답에 추가한다.
			if(matched == m) ret.push_back(begin);
		} 
		else{
			// 예외: matched가 0인 경우에는 다음 칸에서부터 계속 
			if(matched == 0)
				++begin;
			else{
				begin += matched - pi[matched-1];
				// begin을 옮겼다고 처음부터 다시 할 필요가 없다.
				// 옮긴 후에도 pi[matched-1]만큼은 항상 일치하기 때문이다. 
			} 
		}
	}
	return ret; 
}

// 20.3
// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해
// pi[]를 계산한다.
// pi[] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatchNaive(const string& N){
	int m = N.size();
	vector<int> pi(m,0);
	// 단순한 문자열 검색 알고리즘을 구현한다.
	for(int begin = 1; begin < m; begin++){
		for(int i = 0; i + begin < m; i++){
			if(N[begin+i] != N[i]) break;
			// i+1 글자가 서로 대응되었다.
			pi[begin + i] = max(pi[begin + i], i+1); 
		}
	}
	return pi; 
}

// 20.4
// N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해
// pi[]를 계산한다.
// pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N){
	int m = N.size();
	vector<int> pi(m,0);
	// KMP로 자기 자신을 찾는다.
	// N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 안됨!
	int begin = 1, matched = 0;
	// 비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
	while(begin + matched < m){
		if(N[begin + matched] == N[matched]){
			++matched;
			pi[begin + matched-1] = matched;
		}
		else{
			if(matched == 0)
				++begin;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
} 

// 20.5
// s의 접두사도 되고 접미사도 되는 문자열들의 길이를 반환한다.
vector<int> getPrefixSuffix(const string& s){
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while(k>0) {
		// s[..k-1]는 답이다.
		ret.push_back(k);
		k = pi[k-1]; 
	}
	return ret;
}

// 20.6 
// a의 접미사이면서 b의 접두사인 문자열의 최대 길이를 구한다.
int maxOverlap(const string& a, const string& b){
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);
	// begin = matched = 0에서부터 시작하자.
	int begin = 0, matched = 0;
	while(begin < n){
		if(matched < m && a[begin + matched] == b[matched]){
			++matched;
			if(begin + matched == n)
				return matched
		}
		else {
			if(matched == 0)
				++begin;
			else {
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	} 
	return 0;
} 

// 재하의 금고
int shifts(const string& original, const string& target){
	return kmpSearch(original + original, target)[0];
}
	
// 20.8
// 두 접미사의 시작 위치 i,j가 주어질 때 두 접미사 중 어느 쪽이 앞에 와야 할지 비교한다.
struct SuffixComparator {
	const string& s;
	SuffixComparator(const string &s) : s(s) {}
	bool operator() (int i, int j){
		// s.substr() 대신에 strcmp()를 쓰면 임시 객체를 만드는 비용이 절약된다.
		return strcmp(s.c_str() + i, s.c_str() + j) < 0; 
	}
};

vector<int> getSuffixArrayNaive(const string& s){
	// 접미사 시작 위치를 담은 배열을 만든다.
	vector<int> perm;
	for(int i = 0; i < s.size(); ++i) perm.push_back(i);
	// 접미사를 비교하는 비교자를 이용해 정렬하면 완성!
	sort(perm.begin(), perm.end(), SuffixComparator(s));
	return perm; 
}

//
