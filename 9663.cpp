#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 2147483648;
const int MOD = 1000000007;

int n, cnt;
int arr[8];
bool vis_1[15], vis_2[30], vis_3[30];
// 대각선이 증가할 때는 행+열 의 값이 일정
// 감소할 때는 행-열 의 값이 일정

void dfs(int ss) {
    if(ss == n) {
        cnt++;
        return;
    }
    fr(i, 0, n) {
        if(!vis_1[i] && !vis_2[ss+i] && !vis_3[ss-i+n-1]) {
            vis_1[i] = 1;
            vis_2[ss+i] = 1;
            vis_3[ss-i+n-1] = 1;
            dfs(ss+1);
            vis_1[i] = 0;
            vis_2[ss+i] = 0;
            vis_3[ss-i+n-1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    dfs(0);
    pt(cnt);

    return 0;
}