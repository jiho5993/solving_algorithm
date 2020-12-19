#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define V(T) vector<T>
#define VP(T) vector<pair<T,T>>
#define P(T) pair<T,T>
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int C; cin >> C;
    while(C--) {
        string s;
        ll N, T, L; cin >> s >> N >> T >> L;
        L *= 1e8;
        bool flag = true;
        if(s[3] == '!') {
            ll cnt = T;
            for(int i=1; i<=N; i++) {
                cnt *= i;
                if(cnt > L) {
                    flag = false;
                    break;
                }
            }
        } else if(s[2] == '2') {
            ll cnt = T;
            for(int i=0; i<N; i++) {
                cnt <<= 1;
                if(cnt > L) {
                    flag = false;
                    break;
                }
            }
        } else {
            ll cnt = N;
            if(s[4] == '2') cnt *= N;
            else if(s[4] == '3') cnt *= N*N;
            if(cnt > L) flag = false;
            else if(cnt*T > L) flag = false;
        }
        flag ? cout << "May Pass.\n" : cout << "TLE!\n";
    }

    return 0;
}