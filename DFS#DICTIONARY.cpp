#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>

#define NMAX 1000

using namespace std;

int graph[26][26];
vector<string> inputword;
int visited[26];
void makeGraph(int findex,int sindex) {
	int a = inputword[findex][sindex]-'a';
	int b = inputword[findex+1][sindex] - 'a';

	if (sindex >= min(inputword[findex].length(), inputword[findex + 1].length())) {
		return;
	}

	if (a == b) {
		makeGraph(findex, sindex + 1);
		return;
	}

	graph[a][b] = 1;
}

vector<int> order;
void dfs(int x) {
	visited[x] = 1;

	for (int i = 0; i < 26; i++) {
		if (graph[x][i]&&!visited[i]) { dfs(i); }
	}
	order.push_back(x);
}

vector<int> topologicalSort() {
	for (int i = 0; i < 26; i++) {
		if (!visited[i]) dfs(i);
	}

	reverse(order.begin(), order.end());

	for (int i = 0; i < 26; i++) {
		for (int j = i+1; j < 26; j++) {
			if (graph[order[j]][order[i]])	return vector<int>();
		}
	}
	return order;
}


int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		//입력값받고 초기화
		memset(visited, 0, sizeof(visited));
		memset(graph, 0, sizeof(graph));
		inputword.clear();
		order.clear();

		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			string input;
			cin >> input;
			inputword.push_back(input);
		}

		//함수 실행
		for (int i = 0; i < N - 1; i++) {
			makeGraph(i, 0);
		}

		auto orders = topologicalSort();
		if (orders.empty()) {
			cout << "INVALID HYPOTHESIS\n";
		}
		else {
			for (auto& o : orders) {
				cout << static_cast<char>(o + 'a');
			}
			cout << '\n';
		}
	}
}