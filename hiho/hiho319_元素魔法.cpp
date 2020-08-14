#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    double a, ans = 0;
    cin >> k >> a;
    vector<double> w(k);
    double wTotal = 0;
    for (int i = 0; i < k; i++) {
        cin >> w[i];
        wTotal += w[i];
    }
    vector<double> aw(k);
    for (int i = 0; i < k; i++) {
        aw[i] = w[i] / wTotal * a;
        ans += log(pow(aw[i], w[i]));
    }
    cout << fixed << setprecision(5) << ans << endl;
    for (int i = 0; i < k; i++)
        cout << fixed << setprecision(5) << aw[i] << ' ';
    return 0;
}
