#include<iostream>
#include<string>

using namespace std;

string findWord;
char board[5][5];

int yindexseq[8] = { -1,-1,-1,0,1,1,1,0 };
int xindexseq[8] = { -1,0,1,1,1,0,-1,-1 };

bool boggle(int yindex,int xindex,int index) {
	//base case1 : out of index
	if (yindex > 5 || xindex > 5 || xindex < 0 || yindex < 0)	return false;
	
	//base case2 : 글자 다름
	if (board[yindex][xindex] != findWord[index])	return false;

	//base case3: success
	if (index == findWord.size() - 1) {
		if (board[yindex][xindex] == findWord[index]) {
			return true;}}

	//인접한 8칸 검사
	for (int i = 0; i < 8; i++) {
		int nexty = yindex + yindexseq[i];
		int nextx = xindex + xindexseq[i];

		if (boggle(nexty, nextx, index + 1))	return true;
	}
	return false;
}

int main() {
	int test_case;
	cin >> test_case;

	string input;
	while (test_case--) {
		for (int i = 0; i < 5; i++) {
			cin >> input;

			for (int j = 0; j < 5; j++) {
				board[i][j] = input[j];
			}
		}

		bool result;
		int N;	//찾고자하는 단어 수
		cin >> N;
		while (N--) {
			cin >> findWord;

			for (int i = 0; i < 5; i++) {
				result = false;
				for (int j = 0; j < 5; j++) {
					if (findWord[0] == board[i][j])	result=boggle(i, j, 0);
					if (result == true)	break;
				}
				if (result == true)	break;
			}
			if (result == true)	cout << "YES\n";
			else cout << "NO\n";
		}
	}
}