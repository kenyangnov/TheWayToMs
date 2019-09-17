#include <iostream>
#include<set>
#include<algorithm>
using namespace std;

int n, ans = 0;
int a[100001];
int cnt[100001] = {0};
set<int> s;
set<int> s_cur;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cur, next = 0;
	for (int i = 1; i <= n; i++) {
		cur = i;
		set<int>::iterator it;
		while (cnt[cur] == 0) {	//如果是新元素
			s_cur.insert(cur);
			for (it = s_cur.begin(); it != s_cur.end(); it++) {
				cnt[*it]++;
			}
			next = a[cur];
			if (s.find(next) != s.end()) { //如果在前面已经出现过
				for (it = s_cur.begin(); it != s_cur.end(); it++) {
					cnt[*it] += cnt[*s.find(cur)];
				}
				break;
			}
			else if (cnt[next] != 0) {	//如果出现循环，等同于s_cur.find(next) != s_cur.end()
				break;
			}
			cur = next;
		}
		if (s.find(i) != s.end()) {
			s.insert(s_cur.begin(), s_cur.end()); //将s_cur合并到s
		}
		s_cur.clear();
		ans = max(ans, cnt[i]);
	}
	cout << ans;
	return 0;
}