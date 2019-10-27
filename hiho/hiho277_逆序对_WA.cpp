#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[100000 + 10];

//迭代版
int merge_sort(int arr[], int len) {
	int* a = arr;
	int* b = new int[len];
	int cnt = 0;
	for (int seg = 1; seg < len; seg += seg) {
		for (int start = 0; start < len; start += seg + seg) {	//左闭右开
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				if (a[start1] < a[start2]) {
					b[k++] = a[start1++];
				}
				else {
					b[k++] = a[start2++];
					cnt += mid - start1	;
				}
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		int* temp = a;
		a = b;
		b = temp;
	}
	if (a != arr) {
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << merge_sort(a, n) << endl;
	return 0;
}