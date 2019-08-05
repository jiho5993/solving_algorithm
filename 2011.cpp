#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000;

int n, m, rs=0;
int dp[5005];
int arr[5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s; cin >> s;
    fr(i, 1, s.size()+1) arr[i] = s[i-1]-'0';
    if(s[0] == '0') return !printf("0");
    dp[0] = 1;
    fr(i, 1, s.size()+1) {
        int tmp1 = arr[i];
        if(0 < tmp1 && tmp1 < 10) {
            dp[i] += dp[i-1];
            dp[i] %= MOD;
        }
        if(i > 1) {
            int tmp2 = arr[i] + arr[i-1] * 10;
            if(10 <= tmp2 && tmp2 <= 26) {
                dp[i] += dp[i-2];
                dp[i] %= MOD;
            }
        }
    }
    pt(dp[s.size()]%MOD);
}