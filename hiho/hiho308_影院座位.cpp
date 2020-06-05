#include <algorithm>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    // Init
    int n, m;
    cin >> n >> m;
    vector<int> seats(3 * n), nextSeat(3 * n);
    int seats_cnt = 0;
    for (int i = n; i < 2 * n; i++) {
        cin >> seats[i];
        seats[i - n] = seats[i];
        seats[i + n] = seats[i];
        // if (seats[i] == 0) {
        //     seats_cnt++;
        // }
        seats_cnt += (seats[i] == 0);
    }
    int last = 3 * n;
    for (int i = 3 * n - 1; i >= 0; i--) {
        nextSeat[i] = last;
        if (seats[i] == 0) {
            last = i;
        }
    }
    // Processing
    if (seats_cnt < m) {
        cout << -1 << endl;
    } else {
        long long ans = LLONG_MAX;
        for(int i=n; i<2*n; i++){
            int l=i, r=i, s = m-(1-seats[i]);
            long long sum = 0;
            while (s > 0) {
                if (s > 0) {
                    l--;
                    if (seats[l] == 0) s--, sum = sum + (i - l);
                }
                if (s > 0) {
                    r++;
                    if (seats[r] == 0) s--, sum = sum + (r - i);
                }
            }
            ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}