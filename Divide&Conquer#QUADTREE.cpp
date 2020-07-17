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
		input=input.substr(1, input.length());	//맨앞글자 버림
		return temp;
	}

	input = input.substr(1, input.length());	//맨앞글자 버림

	string lt=quadtree(input,result); //왼쪽위
	string rt=quadtree(input, result); //오른쪽 위
	string lb=quadtree(input, result); //왼쪽 아래
	string rb=quadtree(input, result); //오른쪽 아래

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