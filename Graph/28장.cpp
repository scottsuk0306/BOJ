// 28.1 �׷����� ���� �켱 Ž��

// �׷����� ���� ����Ʈ ǥ��
vector<vector<int>> adj;
// �� ������ �湮�ߴ��� ���θ� ��Ÿ����.
vector<bool> visited;
// ���� �켱 Ž���� �����Ѵ�.
void dfs(int here) {
	cout << "DFS visits " << here << endl;
	visited[here] = true;
	// ��� ���� ������ ��ȸ�ϸ鼭
	for(int i = 0; i < adj[here].size(); ++i){
		int there = adj[here][i];
		// ���� �湮�� �� ���ٸ� �湮�Ѵ�.
		if(!visited[there])
			dfs(there); 
	} 
	// ���̻� �湮�� ������ ������, ��� ȣ���� �����ϰ� ���� �������� ���ư���. 
} 
// ��� ������ �湮�Ѵ�.
void dfsAll(){
	// visited�� ��� false�� �ʱ�ȭ�Ѵ�.
	visited = vector<bool>(adj.size(),false);
	// ��� ������ ��ȸ�ϸ鼭, ���� �湮�� �� ������ �湮�Ѵ�.
	for(int i = 0; i < adj.size(); ++i){
		if(!visited[i]) dfs(i);
	} 
} 

// 28.2 ���� ���� ������ �׷����� ����

// ���ĺ��� �� ���ڿ� ���� ���� ��� ǥ��
// ���� (i,j)�� ���ĺ� i�� j���� �տ� �;� ���� ��Ÿ����.
vector<vector<int>> adj;
// �־��� �ܾ��κ��� ���ĺ� ���� ���İ��� �׷����� �����Ѵ�. 
void makeGraph(const vector<string> &words) {
	adj = vector<vector<int>>(26, vector<int>(26,0));
	for(int j = 1; j < words.size(); ++j) {
		int i = j-1, len = min(words[i].size(), words[j].size());
		// word[i]�� word[j] �տ� ���� ������ ã�´�.
		for(int k = 0; k < len; ++k){
			if(words[i][k] != words[j][k]){
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1; // a+'a' �̰� b+'a' ���� �տ� �ִ�. 
				break;
			} 
		} 
	}
} 

// 28.3 ���� �켱 Ž���� �̿��� ���� ����

vector<int> seen, order;
void dfs(int here) {
	seen[here] = 1;
	for(int there = 0; there < adj.size(); ++there){
		if(adj[here][there] && !seen[there]) dfs(there);
	}
	order.push_back(here);
} 

// adj�� �־��� �׷����� ���������� ����� ��ȯ�Ѵ�.
// �׷����� DAG�� �ƴ϶�� �� ���͸� ��ȯ�Ѵ�.
vector<int> topologicalSort() {
	int m = adj.size();
	seen = vector<int>(m, 0);
	order.clear();
	for(int i = 0; i < m; ++i) if(!seen[i]) dfs(i);
	reverse(order.begin(), order.end());
	// ���� �׷����� DAG�� �ƴ϶�� ���� ����� ������ ������ �ִ�.
	for(int i = 0; i < m; ++i){
		for(int j = i+1; j < m; ++j){
			if(adj[order[j]][order[i]]) return vector<int>();
		}
	}
	// ���� ����� ���� �켱 Ž������ ���� ������ ��ȯ�Ѵ�.
	return order; 
} 

// 28.4 ���� �켱 Ž���� �̿��� ���Ϸ� ��Ŷ ã��

// �׷����� ���� ��� ǥ��. adj[i][j] = i�� j ������ ������ ��
vector<vector<int>> adj;
// ���� �׷����� ���� ��� adj�� �־��� �� ���Ϸ� ��Ŷ�� ����Ѵ�.
// ����� ������� circuit�� �������� ���Ϸ� ��Ŷ�� �ȴ�.
void getEulerCircuit(int here, vector<int>& circuit) {
	for(int there = 0; there < adj[here].size(); ++there){
		while(adj[here][there] > 0){
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
} 

// 28.5 �����ձ� ������ �Է��� �׷����� �����

// �׷����� ���� ��� ǥ��. adj[i][j] = i�� j ������ ������ ��
vector<vector<int>> adj;
// graph[i][j] = i�� �����ؼ� j�� ������ �ܾ��� ��ϼ� 
vector<string> graph[26][26];
// indegree[i] = i�� �����ϴ� �ܾ��� ��
// outdegree[i] = i�� ������ �ܾ��� 
vector<int> indegree, outdegree;
void makeGraph(const vector<string>& words){
	// �������� �ʱ�ȭ
	for(int i = 0; i < 26; ++i){
		for(int j = 0; j < 26; ++j){
			graph[i][j].clear();
		}
	} 
	adj = vector<vector<int>>(26, vector<int>(26,0));
	indegree = outdegree = vector<int>(26,0);
	// �� �ܾ �׷����� �߰��Ѵ�.
	for(int i = 0; i < words.size(); ++i) {
		int a = words[i][0] - 'a';
		int b = words[i][words.size()-1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	} 
} 

// 28.6 ���� �׷������� ���Ϸ� ��Ŷ Ȥ�� Ʈ������ ã�Ƴ���

// ���� �׷����� ���� ��� adj�� �־��� �� ���Ϸ� ��Ŷ Ȥ�� Ʈ������ ����Ѵ�.
void getEulerCircuit(int here, vector<int>& circuit){
	for(int there = 0; there < adj.size(); ++there){
		while(adj[here][there] > 0){
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
		circuit.push_back(here);
	}
}

// ���� �׷����� ���Ϸ� Ʈ�����̳� ��Ŷ�� ��ȯ�ϴ�.
vector<int> getEulerTrailOrCiruit(){
	vector<int> circuit;
	// �켱 Ʈ������ ã�ƺ���: �������� �����ϴ� ���
	for(int i = 0; i < 26; ++i){
		if(outdegree[i] == indegree[i]+1){
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	
	// �ƴϸ� ��Ŷ�̴�, ������ ������ �ƹ� ���������� �����Ѵ�.
	for(int i = 0; i < 26; ++i){
		if(outdegree[i]){
			getEulerCircuit(i, circuit);
			return circuit;
		}
	} 
	
	// ��� ������ ��� �� �迭�� ��ȯ�Ѵ�. 
	return circuit;
} 

// 28.7 �����ձ� ������ ���Ϸ� Ʈ���� ������ �ٲ� �ذ��ϴ� �˰���

// ���� �׷����� ���Ϸ� ��Ŷ/Ʈ���� ���� ���θ� Ȯ���Ѵ�.
bool checkEuler() {
	// ���� �������� ���� ��
	int plus1 = 0; minus1 = 0;
	for(int i = 0; i < 26; ++i){
		int delta = outdegree[i] - indegree[i];
		// ��� ������ ������ -1, 1, �Ǵ� 0 �̾�� �Ѵ�.
		if(delta < -1 || 1 < delta) return false;
		if(delta == 1) plus1++;
		if(delta == -1) minus1++;
	} 
	// �������� ������ �� �ϳ��� �ְų� �ϳ��� ����� �Ѵ�.
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0); 
} 

string solve(const vector<string>& words){
	makeGraph(words);
	// ������ ���� ������ ����
	if(!checkEuler()) return "IMPOSSIBLE";
	// ���Ϸ� ��Ŷ�̳� ��θ� ã�Ƴ���.
	vector<int> circuit = getEulerTrailOrCircuit();
	// ��� ������ �湮���� �������� ����!
	if(circuit.size() != words.size() + 1) return "IMPOSSIBLE";
	
	// �ƴ� ��� �湮 ������ ������ �� �������� ��� ���ڿ��� ����� ��ȯ�Ѵ�.
	reverse(circuit.begin(), circuit.end());
	string ret;
	for(int i = 1; i < circuit.size(); i++){
		int a = circuit[i-1], b = circuit[i];
		if(ret.size()) ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	} 
	return ret;
}





















 
