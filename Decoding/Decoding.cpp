#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int StringToInt(string str, int start, int end) {
	int num = 0;
	for (int i = start; i < end; i++) {
		num = num * 10 + str[i] - '0';
	}
	return num;
}

string GenerateOutput(string str)
{
	string output = "";
	int start = -1, end = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z' || i == str.length() - 1) {
			if (start >= end) {
				end = (str[i] >= 'A' && str[i] <= 'Z') ? i : i + 1;
				int num = StringToInt(str, start + 1, end);
				for (int j = 0; j < num; j++) {
					output += str[start];
				}
			}
			start = i;
		}
	}
	return output;
}

int main()
{
	int num = 0;
	vector<string> strs;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		strs.push_back(str);
	}

	for (int i = 0; i < num; i++) {
		string ops = GenerateOutput(strs[i]);
		cout << "Case " << i + 1 << ": " << ops.c_str() << endl;
	}
}
