#include <iostream>
#include<set>
#include<algorithm>
using namespace std;

int n, ans = 0;
int a[100001];
int root[100001] = {0};
set<int> s;	//存储已计算的元素
set<int> s_cur;	//储存当前循环中出现的元素

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cur, next = 0;
	for (int i = 1; i <= n; i++) {
		cur = i;
		set<int>::iterator it;
		while (s_cur.find(cur)== s_cur.end() && s.find(cur) == s.end()) {	//如果是新元素
			s_cur.insert(cur);
			root[i]++;
			next = a[cur];
			if (s.find(next) != s.end()) { //如果在前面已经出现过
				root[i] += root[*s.find(next)];
				break;
			}
			else if (root[next] != 0) {	//如果出现循环
				break;
			}
			cur = next;
		}
		for (it = s_cur.begin(); it != s_cur.end(); it++) {
			//if (*it != i) {
			root[*it] = root[i];
			//}
		}
		s.insert(s_cur.begin(), s_cur.end());
		s_cur.clear();
		ans = max(ans, root[i]);
	}
	cout << ans;
}