#include<iostream>
#include<memory.h>

#define HMAX 100
#define WMAX 20

using namespace std;

bool flag;
int h, w, whiteCount;
int board[HMAX][WMAX];
int boardseqy[4][3] = { {0,0,1},{0,0,1},{0,1,1},{0,1,1} };
int boardseqx[4][3] = { {0,1,0},{0,1,1},{0,0,1},{0,-1,0} };

void coverboard(int &cnt) {
	int yindex = -1, xindex= -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 0) { yindex = i; xindex = j; break; }
		}
		if (yindex != -1) break;
	}

	//base case
	if (yindex == -1) {
		cnt++; return;
	}

	bool flag = false;
	for (int i = 0; i < 4; i++) {
		flag = true;
		for (int j = 0; j < 3; j++) {
			int nexty = yindex + boardseqy[i][j];
			int nextx = xindex + boardseqx[i][j];
			if (nexty >= h || nextx >= w || nexty < 0 || nextx < 0 || board[nexty][nextx] == 1) {
				flag = false;
			}
		}

		if (flag == false) continue;

		for (int j = 0; j < 3; j++) {
			int nexty = yindex + boardseqy[i][j];
			int nextx = xindex + boardseqx[i][j];
			board[nexty][nextx] = 1;
		}

		coverboard(cnt);

		for (int j = 0; j < 3; j++) {
			int nexty = yindex + boardseqy[i][j];
			int nextx = xindex + boardseqx[i][j];
			board[nexty][nextx] = 0;
		}
	}
}

int main() {
	int t_case;
	cin >> t_case;

	char temp;
	while (t_case--) {
		//초기화 및 입력 받음
		whiteCount = 0;
		memset(board, -1, sizeof(board));
		cin >> h >> w;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> temp;
				//검정색 : 1, 흰색 : 0
				if (temp == '#')	board[i][j] = 1;
				else { board[i][j] = 0; whiteCount++; }
			}
		}
		
		//하얀칸 3의 배수 아니면 결과 : 0
		if (whiteCount % 3 != 0) {
			cout << "0\n";
			continue;
		}

		//함수 호출
		int cnt = 0;
		coverboard(cnt);
		cout << cnt<<endl;
	}
}