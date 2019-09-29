//dp题目，打表
//如果开头连续'?',首位如何判断？
//此题放弃，做不出来，花太多时间了。。
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string s;
int m, n;
bool f[201][200001] = { 0 };
int a[201][200001] = { 0 };
int p[100] = { 0 };

int main() {
	cin >> s;
	cin >> m >> n;
	int len = s.length();
	int value = 0;
	int cnt = 0; //记录'?'数量
	int cnt_0 = 0; //记录'0'数量
	//假设所有的?都是0，计算出这个数字模m的余数，设置初始状态
	for (int i = 0; i < len; i++) {
		if (s[i] != '?') {
			value = value * 10 + (s[i]-'0');
			if (s[i] - '0' == 0) {
				cnt_0++;
			}
		}
		else {
			value = value * 10;
			cnt++;
			p[cnt] = len -1 - i;	//记录第cnt个'?'的位置
		}
	}
	//判断是否为0
	if (cnt_0 + cnt == len && n == 0) {
		cout << 0 << endl;
		return 0;
	}

	int r = value % m;
	f[0][r] = true;

	for (int i = 1; i <= cnt; i++) {
		for (int j = 0; j < m; j++) {
			for (int d = 0; d <= 9; d++) {
				//（前一步所能提供的余数） 是否等于（待获得余数）和（10的幂所能提供的余数）之间的差值
				int k = (j - d * int(pow(10, p[i])) % m + m) % m;
				if (d == 0 && p[i] == len - 1) {	//第一个数不能为0
					continue;	//注意此处使用continue
				}
				if (f[i-1][k]==true) {
					f[i][j] = true;
					a[i][j] = d;
					break;
				}
			}
		}
	}

	if (f[cnt][n] == true) {
		int ans = 0;
		for (int i = 1; i <= cnt; i++) {
			ans = ans + a[i][n]*pow(10,p[i]);
		}
		ans += value;
		cout << ans << endl;
	}
	else {
		cout << "No solution" << endl;
	}
	return 0;
}