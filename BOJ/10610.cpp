#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int arr[10];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    string s; cin >> s;
    int sum=0;
    for(char i:s) {
        sum += i-'0';
        arr[i-'0']++;
    }
    if(sum%3 != 0 || arr[0] == 0) {
        cout << -1;
        return 0;
    }
    for(int i=9; i>=0; i--)
        for(int j=0; j<arr[i]; j++)
            cout << i;

    return 0;
}