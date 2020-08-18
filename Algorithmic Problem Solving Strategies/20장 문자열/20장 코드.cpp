// 20.1
// '������' H�� �κ� ���ڿ��� '�ٴ�' N�� �����ϴ� ���� ��ġ���� ��� ��ȯ�Ѵ�. 
vector<int> naiveSearch(const string &H, const string &N){
	vector<int> ret;
	// ��� ���� ��ġ�� �� �õ��� ����.
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
// '������' H�� �κ� ���ڿ��� '�ٴ�' N�� �����ϴ� ���� ��ġ���� ��� ��ȯ�Ѵ�. 
vector<int> kmpSearch(const string& H, const string& N){
	int n = H.size(), m = N.size();
	vector<int> ret;
	// p[i] = N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
	vector<int> pi = getPartialMatch(N);
	// begin = matched = 0 �������� ��������.
	int begin = 0, matched = 0;
	while(begin <= n-m){
		// ���� ¤������ �ش� ���ڰ� �ٴ��� �ش� ���ڿ� ���ٸ�
		if(matched < m && H[begin+matched] == N[matched]){
			++matched;
			// ��������� m���ڰ� ��� ��ġ�ߴٸ� �信 �߰��Ѵ�.
			if(matched == m) ret.push_back(begin);
		} 
		else{
			// ����: matched�� 0�� ��쿡�� ���� ĭ�������� ��� 
			if(matched == 0)
				++begin;
			else{
				begin += matched - pi[matched-1];
				// begin�� �Ű�ٰ� ó������ �ٽ� �� �ʿ䰡 ����.
				// �ű� �Ŀ��� pi[matched-1]��ŭ�� �׻� ��ġ�ϱ� �����̴�. 
			} 
		}
	}
	return ret; 
}

// 20.3
// N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿���
// pi[]�� ����Ѵ�.
// pi[] = N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int> getPartialMatchNaive(const string& N){
	int m = N.size();
	vector<int> pi(m,0);
	// �ܼ��� ���ڿ� �˻� �˰����� �����Ѵ�.
	for(int begin = 1; begin < m; begin++){
		for(int i = 0; i + begin < m; i++){
			if(N[begin+i] != N[i]) break;
			// i+1 ���ڰ� ���� �����Ǿ���.
			pi[begin + i] = max(pi[begin + i], i+1); 
		}
	}
	return pi; 
}

// 20.4
// N���� �ڱ� �ڽ��� ã���鼭 ��Ÿ���� �κ� ��ġ�� �̿���
// pi[]�� ����Ѵ�.
// pi[i] = N[..i]�� ���̻絵 �ǰ� ���λ絵 �Ǵ� ���ڿ��� �ִ� ����
vector<int> getPartialMatch(const string& N){
	int m = N.size();
	vector<int> pi(m,0);
	// KMP�� �ڱ� �ڽ��� ã�´�.
	// N�� N���� ã�´�. begin = 0�̸� �ڱ� �ڽ��� ã�ƹ����ϱ� �ȵ�!
	int begin = 1, matched = 0;
	// ���� ���ڰ� N�� ���� ������ ������ ã���鼭 �κ� ��ġ�� ��� ����Ѵ�.
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
// s�� ���λ絵 �ǰ� ���̻絵 �Ǵ� ���ڿ����� ���̸� ��ȯ�Ѵ�.
vector<int> getPrefixSuffix(const string& s){
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while(k>0) {
		// s[..k-1]�� ���̴�.
		ret.push_back(k);
		k = pi[k-1]; 
	}
	return ret;
}

// 20.6 
// a�� ���̻��̸鼭 b�� ���λ��� ���ڿ��� �ִ� ���̸� ���Ѵ�.
int maxOverlap(const string& a, const string& b){
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);
	// begin = matched = 0�������� ��������.
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

// ������ �ݰ�
int shifts(const string& original, const string& target){
	return kmpSearch(original + original, target)[0];
}
	
// 20.8
// �� ���̻��� ���� ��ġ i,j�� �־��� �� �� ���̻� �� ��� ���� �տ� �;� ���� ���Ѵ�.
struct SuffixComparator {
	const string& s;
	SuffixComparator(const string &s) : s(s) {}
	bool operator() (int i, int j){
		// s.substr() ��ſ� strcmp()�� ���� �ӽ� ��ü�� ����� ����� ����ȴ�.
		return strcmp(s.c_str() + i, s.c_str() + j) < 0; 
	}
};

vector<int> getSuffixArrayNaive(const string& s){
	// ���̻� ���� ��ġ�� ���� �迭�� �����.
	vector<int> perm;
	for(int i = 0; i < s.size(); ++i) perm.push_back(i);
	// ���̻縦 ���ϴ� ���ڸ� �̿��� �����ϸ� �ϼ�!
	sort(perm.begin(), perm.end(), SuffixComparator(s));
	return perm; 
}

//
