#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5;
int n, mTime[N + 1], parent[N + 1];
vector<int> tree[N + 10];

long long ans = 0, f[N + 1];

void dfs(int root) {
    int size = tree[root].size();
    for (int i = 0; i < size; i++) {
        int y = tree[root][i];
        dfs(y);
        f[root] = max(f[root], f[y]);
    }
    for (int i = 0; i < size; i++) {
        int y = tree[root][i];
        ans += f[root] - f[y];
    }
    f[root] += mTime[root];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> mTime[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        parent[b] = a;
        tree[a].push_back(b);
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == 0) {
            root = i;
            break;
        }
    }
    dfs(root);
    cout << ans << endl;
    return 0;
}


