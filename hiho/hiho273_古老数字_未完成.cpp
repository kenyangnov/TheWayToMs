//dp题目，打表
//状态转移方程列不出来，未完成
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string s;
int m, n;
int f[201][201] = { 0 };
int a[201][201] = { 0 };
int p[100] = { 0 };

int main() {
	cin >> s;
	cin >> m >> n;
	int len = s.length();
	int value = 0;
	int cnt = 0;
	//假设所有的?都是0，计算出这个数字模m的余数
	for (int i = 0; i < len; i++) {
		if (s[i] != '?') {
			value = value * 10 + (s[i]-'0');
		}
		else {
			value = value * 10;
			cnt++;
			p[cnt] = i;	//记录第cnt个'?'的位置
		}
	}
	int r = value % m;
	f[0][r] = true;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 0; j < m; j++) {
			for (int d = 0; d <= 9; d++) {
				if ( ) {
					break;
				}
			}
		}
	}

	if (f[cnt][n] == true) {
		int ans = 0;
		for (int i = cnt; i >= 0; i--) {
			ans = ans * 10 + a[i][n];
		}
		cout << ans << endl;
	}
	else {
		cout << "No solution" << endl;
	}
	return 0;
}