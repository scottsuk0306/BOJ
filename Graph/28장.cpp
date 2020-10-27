// 28.1 그래프의 깊이 우선 탐색

// 그래프의 인접 리스트 표현
vector<vector<int>> adj;
// 각 정점을 방문했는지 여부를 나타낸다.
vector<bool> visited;
// 깊이 우선 탐색을 구현한다.
void dfs(int here) {
	cout << "DFS visits " << here << endl;
	visited[here] = true;
	// 모든 인접 정점을 순회하면서
	for(int i = 0; i < adj[here].size(); ++i){
		int there = adj[here][i];
		// 아직 방문한 적 없다면 방문한다.
		if(!visited[there])
			dfs(there); 
	} 
	// 더이상 방문할 정점이 없으니, 재귀 호출을 종료하고 이전 정점으로 돌아간다. 
} 
// 모든 정점을 방문한다.
void dfsAll(){
	// visited를 모두 false로 초기화한다.
	visited = vector<bool>(adj.size(),false);
	// 모든 정점을 순회하면서, 아직 방문한 적 없으면 방문한다.
	for(int i = 0; i < adj.size(); ++i){
		if(!visited[i]) dfs(i);
	} 
} 

// 28.2 고대어 사전 문제의 그래프를 생성

// 알파벳의 각 글자에 대한 인접 행렬 표현
// 간선 (i,j)는 알파벳 i가 j보다 앞에 와야 함을 나타낸다.
vector<vector<int>> adj;
// 주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다. 
void makeGraph(const vector<string> &words) {
	adj = vector<vector<int>>(26, vector<int>(26,0));
	for(int j = 1; j < words.size(); ++j) {
		int i = j-1, len = min(words[i].size(), words[j].size());
		// word[i]가 word[j] 앞에 오는 이유를 찾는다.
		for(int k = 0; k < len; ++k){
			if(words[i][k] != words[j][k]){
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1; // a+'a' 이게 b+'a' 보다 앞에 있다. 
				break;
			} 
		} 
	}
} 

// 28.3 깊이 우선 탐색을 이용한 위상 정렬

vector<int> seen, order;
void dfs(int here) {
	seen[here] = 1;
	for(int there = 0; there < adj.size(); ++there){
		if(adj[here][there] && !seen[there]) dfs(there);
	}
	order.push_back(here);
} 

// adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면 빈 벡터를 반환한다.
vector<int> topologicalSort() {
	int m = adj.size();
	seen = vector<int>(m, 0);
	order.clear();
	for(int i = 0; i < m; ++i) if(!seen[i]) dfs(i);
	reverse(order.begin(), order.end());
	// 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
	for(int i = 0; i < m; ++i){
		for(int j = i+1; j < m; ++j){
			if(adj[order[j]][order[i]]) return vector<int>();
		}
	}
	// 없는 경우라면 깊이 우선 탐색에서 얻은 순서를 반환한다.
	return order; 
} 

// 28.4 깊이 우선 탐색을 이용한 오일러 서킷 찾기

// 그래프의 인접 행렬 표현. adj[i][j] = i와 j 사이의 간선의 수
vector<vector<int>> adj;
// 무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
// 결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다.
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

// 28.5 끝말잇기 문제의 입력을 그래프로 만들기

// 그래프의 인접 행렬 표현. adj[i][j] = i와 j 사이의 간선의 수
vector<vector<int>> adj;
// graph[i][j] = i로 시작해서 j로 끝나는 단어의 목록수 
vector<string> graph[26][26];
// indegree[i] = i로 시작하는 단어의 수
// outdegree[i] = i로 끝나는 단어의 
vector<int> indegree, outdegree;
void makeGraph(const vector<string>& words){
	// 전역변수 초기화
	for(int i = 0; i < 26; ++i){
		for(int j = 0; j < 26; ++j){
			graph[i][j].clear();
		}
	} 
	adj = vector<vector<int>>(26, vector<int>(26,0));
	indegree = outdegree = vector<int>(26,0);
	// 각 단어를 그래프에 추가한다.
	for(int i = 0; i < words.size(); ++i) {
		int a = words[i][0] - 'a';
		int b = words[i][words.size()-1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		outdegree[a]++;
		indegree[b]++;
	} 
} 

// 28.6 방향 그래프에서 오일러 서킷 혹은 트레일을 찾아내기

// 유향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷 혹은 트레일을 계산한다.
void getEulerCircuit(int here, vector<int>& circuit){
	for(int there = 0; there < adj.size(); ++there){
		while(adj[here][there] > 0){
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
		circuit.push_back(here);
	}
}

// 현재 그래프의 오일러 트레일이나 서킷을 반환하다.
vector<int> getEulerTrailOrCiruit(){
	vector<int> circuit;
	// 우선 트레일을 찾아본다: 시작점이 존재하는 경우
	for(int i = 0; i < 26; ++i){
		if(outdegree[i] == indegree[i]+1){
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	
	// 아니면 서킷이니, 간선에 인접한 아무 정점에서나 시작한다.
	for(int i = 0; i < 26; ++i){
		if(outdegree[i]){
			getEulerCircuit(i, circuit);
			return circuit;
		}
	} 
	
	// 모두 실패한 경우 빈 배열을 반환한다. 
	return circuit;
} 

// 28.7 끝말잇기 문제를 오일러 트레일 문제로 바꿔 해결하는 알고리즘

// 현재 그래프의 오일러 서킷/트레일 존재 여부를 확인한다.
bool checkEuler() {
	// 예비 시작점과 끝점 수
	int plus1 = 0; minus1 = 0;
	for(int i = 0; i < 26; ++i){
		int delta = outdegree[i] - indegree[i];
		// 모든 정점의 차수는 -1, 1, 또는 0 이어야 한다.
		if(delta < -1 || 1 < delta) return false;
		if(delta == 1) plus1++;
		if(delta == -1) minus1++;
	} 
	// 시작점과 끝점은 각 하나씩 있거나 하나도 없어야 한다.
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0); 
} 

string solve(const vector<string>& words){
	makeGraph(words);
	// 차수가 맞지 않으면 실패
	if(!checkEuler()) return "IMPOSSIBLE";
	// 오일러 서킷이나 경로를 찾아낸다.
	vector<int> circuit = getEulerTrailOrCircuit();
	// 모든 간선을 방문하지 못했으면 실패!
	if(circuit.size() != words.size() + 1) return "IMPOSSIBLE";
	
	// 아닌 경우 방문 순서를 뒤집은 뒤 간선들을 모아 문자열로 만들어 반환한다.
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





















 
