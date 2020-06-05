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
        seats_cnt += (seats[i] == 0);
        // if (seats[i] == 0) {
        //     seats_cnt++;
        // }
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
        int l = n, r = n, s = m - (1 - seats[n]);
        int lc = (1 - seats[n]), rc = 0;
        long long sum = 0, ans = LLONG_MAX;
        // Find the nearest result for the n-th (0-th actually) seat
        while (s > 0) {
            if (s > 0) {
                l--;
                if (seats[l] == 0) s--, lc++, sum = sum + (n - l);
            }
            if (s > 0) {
                r++;
                if (seats[r] == 0) s--, rc++, sum = sum + (r - n);
            }
        }
        // Set the l, r to be boundary
        while (seats[l] != 0) l++;
        while (seats[r] != 0) r--;
        ans = min(ans, sum);
        // Translate from left to right
        for (int i = n + 1; i <= 2 * n; i++) {
            sum = sum + lc - rc;
            if (seats[i] == 0) {
                lc++;
                rc--;
            }
            if (nextSeat[r] - i < i - l) {
                sum -= (i - l);
                sum += (nextSeat[r] - i);
                lc--; rc++;
                // if (l <= i) lc--; else rc--;
                // if (nextSeat[r] <= i) lc++; else rc++;
                l = nextSeat[l]; r = nextSeat[r];
            }
            ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}