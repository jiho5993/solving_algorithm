#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int n;
char arr[9][9];

bool is_palin(string s) {
    int ss = s.size();
    for(int i=0; i<ss/2; i++)
        if(s[i] != s[ss-1-i])
            return false;
    return true;
}

int foo1() {
    int ret = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(j+n > 8) continue;
            string s="";
            for(int k=j; k<j+n; k++) s += arr[i][k];
            if(is_palin(s)) ret++;
        }
    }
    return ret;
}

int foo2() {
    int ret = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(i+n > 8) continue;
            string s="";
            for(int k=i; k<i+n; k++) s += arr[k][j];
            if(is_palin(s)) ret++;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int tc=1; tc<=10; tc++) {
        cin >> n;
        for(int i=0; i<8; i++) {
            string s; cin >> s;
            for(int j=0; j<8; j++) arr[i][j] = s[j];
        }
        cout << "#" << tc << ' ' << foo1()+foo2() << '\n';
    }

    return 0;
}