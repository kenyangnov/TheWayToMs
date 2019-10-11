#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	float  tp = 0, tn = 0 , fp = 0, fn = 0;
	char gt, pred;
	for (int i = 0; i < n; i++) {
		cin >> gt >> pred;
		if (gt == '+') {
			if (pred == '+') {
				tp++;
			}
			else {
				fp++;
			}
		}
		else {
			if (pred == '-') {
				tn++;
			}
			else {
				fn++;
			}
		}
	}
	float precision, recall, f1;
	if (tp + fp == 0) {
		precision = 0;
	}
	else {
		precision = tp / (tp + fp);
	}
	if (tp + fn == 0) {
		recall = 0;
	}
	else {
		recall = tp / (tp + fn);
	}
	if (precision == 0 && recall == 0) {
		f1 = 0;
	}
	else {
		f1 = 2 * precision * recall / (precision + recall);
	}
	cout << fixed << setprecision(2) << f1 * 100 << '%' << endl;
	return 0;
}