// 23.1
// ��������� �ִ� �� heap�� �� ���� newValue�� �����Ѵ�.
void push_heap(vector<int>& heap, int newValue){
	// ���� �� ���� newValue�� �����Ѵ�.
	heap.push_back(newValue);
	// ���� newValue�� ��ġ
	int idx = heap.size()-1;
	// ��Ʈ�� �����ϰų� newValue �̻��� ���Ҹ� ���� ������ ���� ������
	while(idx > 0 && heap[(idx-1)/2] < heap[idx]){
		swap(heap[idx], heap[(idx-1)/2]);
		idx = (idx-1)/2;
	} 
} 

// 23.2
// ���� ���Ҹ� ���� �ִ� ������ �ִ� ���� �����ϱ�
// ������ ��� �ִ� heap���� heap[0]�� �����Ѵ�.
void pop_heap(vector<int>& heap){
	// ���� �� ������ ���� ������ ��Ʈ�� ������.
	heap[0] = heap.back();
	heap.pop_back(); // 8 ���� �� �� 
	int here = 0;
	while(true){
		int left = here * 2 + 1, right = here * 2 + 2;
		// ������ ������ ���
		if(left >= heap.size()) break;
		// heap[here]�� ������ ��ġ�� ã�´�.
		int next = here;
		if(heap[next] < heap[left]){
			next = left;
		}
		if(right < heap.size() && heap[next] < heap[right]){
			next = right;
		}
		if(next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	} 
} 

// 23.4 ���� �̿��� ��ȭ�ϴ� �߰� �� ������ �ذ��ϴ� �Լ��� ����
int runningMedian(int n, RNG rng){
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int ret = 0;
	// �ݺ��� �Һ���:
	// 1. maxHeap�� ũ��� minHeap�� ũ��� ���ų� 1 �� ũ��.
	// 2. maxHeap.top() <= minHeap.top()
	for(int cnt = 1; cnt <= n; ++cnt){
		// �켱 1�� �Һ��ĺ��� ������Ų��.
		if(maxHeap.size() == minHeap.size()){
			maxHeap.push(rng.next());
		}
		else
			minHeap.push(rng.next());
		if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()){
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
	return ret; 
} 
