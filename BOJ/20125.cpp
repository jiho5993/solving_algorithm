#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N;
pair<int, int> heart;
int res[5]; // l_arm, r_arm, mid, l_leg, r_leg
char arr[1001][1001];

void foo() {
    int _i=heart.first, _j=heart.second;
    pair<int, int> l_leg, r_leg;
    for(int i=_j-1; i>=0; i--) {
        if(arr[_i][i] == '_') break;
        res[0]++;
    }
    for(int i=_j+1; i<N; i++) {
        if(arr[_i][i] == '_') break;
        res[1]++;
    }
    for(int i=_i+1; i<N; i++) {
        if(arr[i][_j] == '_') {
            l_leg = mp(i, _j-1);
            r_leg = mp(i, _j+1);
            break;
        }
        res[2]++;
    }
    for(int i=l_leg.first; i<N; i++) {
        if(arr[i][l_leg.second] == '_') break;
        res[3]++;
    }
    for(int i=r_leg.first; i<N; i++) {
        if(arr[i][r_leg.second] == '_') break;
        res[4]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    bool flag = false;
    cin >> N;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        for(int j=0; j<N; j++) {
            arr[i][j] = s[j];
            if(s[j] == '*' && !flag) {
                heart = mp(i+1, j);
                flag = true;
            }
        }
    }
    foo();
    cout << heart.first+1 << ' ' << heart.second+1 << '\n';
    for(int i=0; i<5; i++) cout << res[i] << ' ';

    return 0;
}