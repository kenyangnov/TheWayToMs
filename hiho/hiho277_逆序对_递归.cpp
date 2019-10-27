#include<iostream>
using namespace std;
int a[100000], temp[100000]; long long ans = 0;
void merge_i(int l, int mid, int r)
{
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r)
	{
		if (a[i] > a[j])
		{
			temp[k++] = a[j++];
			ans += mid - i + 1;
		}
		else
			temp[k++] = a[i++];
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= r) temp[k++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = temp[i];
}
void merge(int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) >> 1;
		merge(l, mid);
		merge(mid + 1, r);
		merge_i(l, mid, r);
	}
}
int main()
{
	int n;
	cin >> n;
	int i;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	merge(1, n);
	cout << ans;
	return 0;
}