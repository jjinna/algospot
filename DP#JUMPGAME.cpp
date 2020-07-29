#include<iostream>
#include<memory.h>
#define NMAX 100

using namespace std;

int n, input[NMAX][NMAX],cache[NMAX][NMAX];
int dy[2] = { 0,1 },dx[2] = { 1,0 };	//오른쪽, 아래로 이동

//초기화
void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}

	memset(cache, -1, sizeof(cache));
}

int solve(int yindex,int xindex) {
	//base case
	if (yindex >= n || xindex >= n)	return 0;
	if (yindex == n - 1 && xindex == n - 1)	return 1;

	int &ret = cache[yindex][xindex];
	if (ret != -1)	return ret;

	int jumpsize = input[yindex][xindex];
	ret= solve(yindex, xindex + jumpsize) || solve(yindex + jumpsize, xindex);

	return ret;
}

int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		init();
		if (solve(0, 0))	cout << "YES\n";
		else cout << "NO\n";
	}
}