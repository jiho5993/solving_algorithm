#include <bits/stdc++.h>
#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define len(a) ((int)(a.length()))
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    string s, ss; cin >> s >> ss;
    int s_cnt[26]={0,}, ss_cnt[26]={0,}, cnt=0;
    fr(i, 0, len(s)) s_cnt[s[i]-'a']++;
    fr(i, 0, len(ss)) ss_cnt[ss[i]-'a']++;
    fr(i, 0, 26) {
        if(s_cnt[i] > ss_cnt[i]) cnt += s_cnt[i]-ss_cnt[i];
        if(s_cnt[i] < ss_cnt[i]) cnt += ss_cnt[i]-s_cnt[i];
    }
    pt(cnt);

    return 0;
}