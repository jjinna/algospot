#include <string>
#include <vector>
#include<memory.h>
#include <algorithm>
#include<iostream>

#define INF 99999
using namespace std;

vector<vector<int>> switches = {
	{ 0, 1, 2 }, // 0
	{ 3, 7, 9, 11 }, // 1
	{ 4, 10, 14, 15 }, // 2
	{ 0, 4, 5, 6, 7 }, // 3
	{ 6, 7, 8, 10, 12 }, // 4 
	{ 0, 2, 14, 15 }, // 5
	{ 3, 14, 15 }, // 6
	{ 4, 5, 7, 14, 15 }, // 7
	{ 1, 2, 3, 4, 5 }, // 8
	{ 3, 4, 5, 9, 13 } // 9
};

int input[16]; int cnt[10];
void solve(int index, int& ans, int result) {
	//base case1
	if (index == 10) { 
		bool flag = true;
		for (int i = 0; i < 16; i++) {
			if (input[i] != 0)	flag = false;
		}

		if (flag == true) { if (result < ans)	ans = result; }
		return;
	}


	for (int i = 0; i < 4; i++) {
		cnt[index] = i;
		for (int j= 0; j < switches[index].size(); j++) {
			input[switches[index][j]]=(input[switches[index][j]] + i) % 4;
		}

		solve(index+1, ans, result+i);

		for (int j = 0; j < switches[index].size(); j++) {
			input[switches[index][j]] = (input[switches[index][j]]+4 - i) % 4;
		}
	}
}

int main() {
	int C;
	cin >> C;

	while (C--) {
		memset(cnt, -1, sizeof(cnt));

		int temp;
		for (int i = 0; i < 16; i++) {
			cin >> temp;
			if (temp == 12)	input[i] = 0;
			else if (temp == 9)	input[i] = 3;
			else if (temp == 6)	input[i] = 2;
			else if (temp == 3)	input[i] = 1;
		}

		int ans = INF;
		solve(0, ans, 0);

		if (ans == INF)	cout << -1 << endl;
		else cout << ans << endl;	
	}
	return 0;
}
