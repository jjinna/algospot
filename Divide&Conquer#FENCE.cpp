#include<iostream>
#include<algorithm>
#define NMAX 20000
using namespace std;

int input[NMAX];
void fence(int startIndex,int endIndex,int &result) {
	//base case
	if (endIndex < startIndex) { return; }
	if (endIndex == startIndex) {
		result = max(result, input[startIndex]);
		return;
	}

	//���� ���� ��Ÿ�� ã��(�ּڰ� ���ϱ�)
	int min = startIndex;
	for (int i = startIndex+1; i <= endIndex; i++) {
		if (input[i]<=input[min])	min = i;}

	//�ּڰ� �������� �ִ� ���ϱ�
	int temp;
	temp = (endIndex - startIndex + 1) * input[min];
	result = max(result, temp);

	fence(startIndex, min - 1,result);
	fence(min + 1, endIndex, result);
}

int main() {
	int t_case;
	cin >> t_case;
	while (t_case--) {
		//�ʱ�ȭ
		int N;
		memset(input, -1, sizeof(input));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input[i];}

		int result = 0;
		fence(0, N-1, result);
		cout << result<<endl;
	}
}