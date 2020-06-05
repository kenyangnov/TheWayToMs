#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> seats;
vector<bool> expand_seats;
vector<int> avail_seats;
vector<int> next_seat;

int main() {
    cin >> n >> m;
    int seats_cnt = 0;
    for (int i = 0; i < n; i++) {
        bool s;
        cin >> s;
        seats.push_back(s);
        if (s == 0) {
            seats_cnt++;
        }
    }
    if (seats_cnt < m) {
        return -1;
    }

    // expand_seats.insert(expand_seats.end(), seats.begin(), seats.end());
    // expand_seats.insert(expand_seats.end(), seats.begin(), seats.end());
    // expand_seats.insert(expand_seats.end(), seats.begin(), seats.end());

    int pre = 0;
    for (int i = 0; i < expand_seats.size(); i++) {
        if (expand_seats[i] == 0) {
            for (int j = pre; j < i; j++) {
                next_seat.push_back(i);
            }
            pre = i;
        }
    }

    int ans = n * m;
    int start = n;
    int end = start + n;

    int l = start, r = start, s = m - (1 - expand_seats[start]), sum = 0,
        lc = 1 - expand_seats[start], rc = 0;
    while (s > 0) {
        if (s > 0) {
            l = l - 1;
            if (expand_seats[l] == 0) {
                s = s - 1;
                sum = sum + (start - l);
                lc++;
            }
        }
        if (s > 0) {
            r = r + 1;
            if (expand_seats[r] == 0) {
                s = s - 1;
                sum = sum + (r - start);
                rc++;
            }
        }
    }

    while (expand_seats[l] != 0) l++;
    while (expand_seats[r] != 0) r--;

    ans = min(ans, sum);

    for (int i = n + 1; i < 2 * n; i++) {
        sum = sum + lc - rc;
        if (expand_seats[i] == 0) {
            lc = lc + 1;
            rc = rc - 1;
        }
        if ((next_seat[r] - i) < i - l) {
            sum = sum - (i - l) + (next_seat[r] - i);
            if (l <= i)
                lc--;
            else
                rc--;
            if (next_seat[r] <= i)
                rc++;
            else
                lc++;
            l = next_seat[l];
            r = next_seat[r];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}