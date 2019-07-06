#include <iostream>
#include <string.h>
using namespace std;

//注意：手中14张牌最多只能属于两个花色！

int cnt[3][10];	//3种花色，9种数字(1~9)
int k1, k2;

bool ok1_sub(int dep) {
	if (dep > 4) {	//到达第四层判断有无对子
		for (int i = 1; i <= 9; i++) {
			if (cnt[k1][i] >= 2) {
				return true;
			}
		}
		for (int i = 1; i <= 9; i++) {
			if (cnt[k2][i] >= 2) {
				return true;
			}
		}
		return false;
	}
	for (int i = 1; i <= 9; i++) {
		if (cnt[k1][i] >= 3) {
			cnt[k1][i] -= 3;
			if (ok1_sub(dep + 1)) {
				return true;
			}
			cnt[k1][i] += 3;
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (cnt[k2][i] >= 3) {
			cnt[k2][i] -= 3;
			if (ok1_sub(dep + 1)) {
				return true;
			}
			cnt[k2][i] += 3;
		}
	}
	for (int i = 1; i <= 7; i++) {
		if (cnt[k1][i] && cnt[k1][i + 1] && cnt[k1][i + 2]) {
			cnt[k1][i]--, cnt[k1][i + 1]--, cnt[k1][i + 2]--;
			if (ok1_sub(dep + 1)) {
				return true;
			}
			cnt[k1][i]++, cnt[k1][i + 1]++, cnt[k1][i + 2]++;
		}
	}
	for (int i = 1; i <= 7; i++) {
		if (cnt[k2][i] && cnt[k2][i + 1] && cnt[k2][i + 2]) {
			cnt[k2][i]--, cnt[k2][i + 1]--, cnt[k2][i + 2]--;
			if (ok1_sub(dep + 1)) {
				return true;
			}
			cnt[k2][i]++, cnt[k2][i + 1]++, cnt[k2][i + 2]++;
		}
	}
	return false;
}

bool ok1() {
	for (k1 = 0; k1 <= 2; k1++) {
		for (k2 = k1; k2 <= 2; k2++) {
			if (ok1_sub(1)) {
				return true;
			}
		}
	}
	return false;
}

bool ok2() {
	int num[3];
	memset(num, 0, sizeof(num));
	for (int i = 0; i <= 2; i++) {
		for (int j = 1; j <= 9; j++) {	//j从1开始(1~9)
			num[i] += cnt[i][j] / 2;
		}
	}
	if ((num[0] + num[1] >= 7) || (num[0] + num[2] >= 7) || (num[1] + num[2] >= 7)) {
		return true;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	char element[4];
	memset(cnt, 0, sizeof(cnt));
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		cout << cnt[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	for (int i = 0; i < 14; i++) {
		cin >> element;
		cnt[element[0] - 'a'][element[1] - '0']++;
	}
	if(ok1()||ok2()){	//起手就胡？！
		cout<<"0";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> element;
		cnt[element[0] - 'a'][element[1] - '0']++;
		if (ok1() || ok2()) {
			cout << i + 1;
			//system("pause");
			return 0;
		}
	}
	cout << "-1";
	//system("pause");
	return 0;
}