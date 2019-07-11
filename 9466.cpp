#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

#define MX 100001
int t, sc, cnt=0;
int s[MX], visit[MX], cycle[MX]; // 방문여부와 함께 사이클 여부도 판단

void init() {
    fill(s, s + MX, 0);
    fill(cycle, cycle + MX, 0);
    fill(visit, visit + MX, 0);
}

void dfs(int start) {
    visit[start] = 1;
    int next = s[start];
    if(!visit[next]) dfs(next); // 먼저 사이클을 찾는다.
    else { // 사이클을 다 찾고 난 뒤 cnt를 해준다.
        if(!cycle[next]) {
            for(int i=next; i!=start; i=s[i]) cnt++;
            cnt++; // 자기 자신도 센다.
        }
    }
    cycle[start] = 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> t;
    while(t--) {
        init();
        cin >> sc;
        fr(i, 1, sc+1) cin >> s[i];
        cnt = 0;
        fr(i, 1, sc+1) {
            if(!visit[i])
                dfs(i);
        }
        pt(sc-cnt);
    }

    return 0;
}