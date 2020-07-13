#include<iostream>
#include<memory.h>
#define NMAX 10
using namespace std;

int check[NMAX];
int input[NMAX][NMAX];
int n, m;//n:학생수,m:친구쌍의수
int makeGroup() {
	int startNum = -1;
	for (int i = 0; i < n - 1; i++) {
		if (check[i] == -1) {
			startNum = i;
			break;
		}
	}

	if (startNum == -1)	return 1;

	int ret = 0;
	for (int i = startNum + 1; i < n; i++) {
		if (check[i] == -1 && input[i][startNum] == 1) {
			check[startNum] = 1;
			check[i] = 1;

			ret += makeGroup();

			check[startNum] = -1;
			check[i] = -1;

		}
	}

	return ret;
}

int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		cin >> n >> m;

		memset(input, 0, sizeof(input));
		fill(check, check + n + 1, -1);

		int input1, input2;
		for (int i = 0; i < m; i++) {
			cin >> input1 >> input2;
			input[input1][input2] = 1;
			input[input2][input1] = 1;
		}

		int result = makeGroup();

		cout << result << endl;

	}
}