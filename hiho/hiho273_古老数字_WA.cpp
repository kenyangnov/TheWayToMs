//数字中可能有多个"?"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string s;
int m, n;

int main() {
	cin >> s;
	cin >> m >> n;
	int len = s.length();
	int value = 0;
	int loc = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] != '?') {
			value = value * 10 + (s[i]-'0');
		}
		else {
			value = value * 10;
			loc = i;
		}
	}
	int ans = -1;
	int pw = len - 1 - loc;
	if (loc == 0) {
		if (len == 1) {
			for (int i = 0; i < 10; i++) {
				if (i % m == n) {
					ans = i;
					break;
				}
			}
		}
		else {
			for (int i = 1; i < 10; i++) {
				if ((value + i * int(pow(10, pw))) % m == n) {
					ans = value + i * int(pow(10, pw));
					break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if ((value + i * int(pow(10, pw))) % m == n) {
				ans = value + i * int(pow(10, pw));
				break;
			}
		}
	}
	if (ans == -1) {
		cout << "No solution" << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}