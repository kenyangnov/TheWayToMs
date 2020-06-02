#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> seats;

int main(){
    cin>>n>>m;
    int seats_cnt = 0;
    vector<int> seats_avail;
    for (int i=0; i<n ; i++){
        bool s;
        cin >> s;
        seats.push_back(s);
        if(s==0){
            seats_cnt++;
        }
        seats_avail.push_back(seats_cnt);
    }
    if(seats_cnt < m){
        return -1;
    }
    
    vector<bool> expand_seats;
    std::copy(seats.begin() + n/2, seats.end(), expand_seats.begin());
    expand_seats.insert(expand_seats.end(), seats.begin(), seats.end());
    expand_seats.insert(expand_seats.end(), seats.begin(), seats.begin() + n/2);
     
    // int start = n/2+1;
    // int end = n/2+1+n;
    // int seats_need = m;
    int start = 0;
    for(int i = n/2 -1, int j = 0; i<n;i++, j++){
        if(seats_avail[n-1]-seats_avail[i]<=m){
            start = j;
            break;
        }
    }

}