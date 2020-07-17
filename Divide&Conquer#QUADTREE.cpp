#include<iostream>
#include<string>
#include<vector>

#define NMAX 20
using namespace std;


string quadtree(string& input, string result) {
	//base case
	if (input[0] != 'x') {
		string temp = "";
		temp+=input[0];
		input=input.substr(1, input.length());	//�Ǿձ��� ����
		return temp;
	}

	input = input.substr(1, input.length());	//�Ǿձ��� ����

	string lt=quadtree(input,result); //������
	string rt=quadtree(input, result); //������ ��
	string lb=quadtree(input, result); //���� �Ʒ�
	string rb=quadtree(input, result); //������ �Ʒ�

	string toSum = "x"+lb + rb + lt + rt;
	result += toSum;
	return result;
}

int main() {
	int t_case;
	cin >> t_case;

	while (t_case--) {
		string input;
		cin >> input;

		string result = "";
		cout<<quadtree(input, result) << endl;

	}
}