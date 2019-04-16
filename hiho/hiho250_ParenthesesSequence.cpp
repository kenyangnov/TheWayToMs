#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct parenthese {
	int lp;
	int rp;
};
string To_SR(const string &s) {
	string str = s;
	int len = s.length();
	//找SL、SR分界
	parenthese* cur = new parenthese[len];
	if (str[0] == '(') {
		cur[0].lp = 1;
		cur[0].rp = 0;
	}
	else {
		cur[0].lp = 0;
		cur[0].rp = 1;
	}
	for (int i = 1; i < len; i++) {
		if (str[i] == '(') {
			cur[i].lp = cur[i - 1].lp + 1;
			cur[i].rp = cur[i - 1].rp;
		}
		else {
			cur[i].rp = cur[i - 1].rp + 1;
			cur[i].lp = cur[i - 1].lp;
		}
	}
	int sum_lp = cur[len - 1].lp;
	int sum_rp = cur[len - 1].rp;
	int edge = 0;
	for (int i = 0; i < len; i++) {
		edge = i;
		if (cur[i].lp<cur[i].rp && (sum_lp - cur[i].lp)>(sum_rp - cur[i].rp)) {
			break;
		}
	}
	for (int i = 0; i < len; i++) {
		cout <<i<<"---"<< cur[i].lp << "---" << cur[i].rp << endl;
	}
	cout << edge << endl;
	delete[] cur;
	// 将SL先互换再反转
	int i = 0, j = edge + 1;
	for (i; i < j; i++) {
		if (str[i] == '(') {
			str[i] = ')';
		}
		else {
			str[i] = '(';
		}
	}
	while (i < j) {
		swap(str[i++], str[j--]);
	}
	// 返回处理后的字符串
	return str;
}

int main()
{
	string s;
	cin >> s;
	string str = To_SR(s);	//将字符串转换为SR形
	cout << str;
}