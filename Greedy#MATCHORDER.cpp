#include<iostream>
#include<algorithm>

#define NMAX 100
using namespace std;

int N;
int russia[NMAX], korea[NMAX];
void matching(int &result) {
	sort(korea, korea + N);
	sort(russia, russia + N);
	
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < N; j++) {
			if (russia[i] <= korea[j]) {
				result++;
				korea[j] = -1;
				break;
			}
		}
	}
}

int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		//ÃÊ±âÈ­
		cin >> N;
		memset(russia, -1, sizeof(russia));
		memset(korea, -1, sizeof(korea));

		for (int i = 0; i < N; i++) {
			cin >> russia[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> korea[i];
		}

		int result = 0;
		matching(result);
		cout << result << endl;
	}
}