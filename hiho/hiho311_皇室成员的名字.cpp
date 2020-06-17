#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, int> year_map;

void init() {
    year_map['I'] = 1;
    year_map['V'] = 5;
    year_map['X'] = 10;
    year_map['L'] = 50;
    year_map['C'] = 100;
    year_map['D'] = 500;
    year_map['M'] = 1000;
}

int transfer(string &s) {
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len - 1; i++) {
        if (year_map[s[i]] >= year_map[s[i + 1]]) {
            sum += year_map[s[i]];
        } else {
            sum -= year_map[s[i]];
        }
    }
    sum += year_map[s[len - 1]];
    return sum;
}

bool customCompare(pair<string, string> &a, pair<string, string> &b) {
    int pos = a.first.compare(b.first);
    if (pos != 0)
        return pos < 0;
    else
        return transfer(a.second) < transfer(b.second);
}

void sortName(vector<pair<string, string>> &name) {
    sort(name.begin(), name.end(), customCompare);
    for (int i = 0; i < name.size(); i++) {
        cout << name[i].first << " " << name[i].second << endl;
    }
}

int main() {
    init();
    int n;
    cin >> n;
    vector<pair<string, string>> name(n);
    for (int i = 0; i < n; i++) {
        cin >> name[i].first >> name[i].second;
    }
    sortName(name);
    return 0;
}