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
const int MOD = 1000000007;

int arr[101];
set<int> tap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k, cnt=0; cin >> n >> k;
    fr(i, 0, k) cin >> arr[i];
    fr(i, 0, k) {
        if(n > 0) {
            if(tap.find(arr[i]) == tap.end()) n--; // 새로 꼽는거라면
            tap.insert(arr[i]);
        } else {
            if(tap.find(arr[i]) != tap.end()) continue; // 중복되면 그냥 넘어감
            else {
                pii info = {-1, -1};
                for(auto it=tap.begin(); it != tap.end(); it++) {
                    int plug_cnt=0;
                    fr(j, i+1, k){
                        if(*it == arr[j]) break;
                        plug_cnt++;
                    }
                    if(info.first < plug_cnt) info = {plug_cnt, *it};
                }
                auto v = tap.find(info.second);
                tap.erase(v);
                tap.insert(arr[i]);
                cnt++;
            }
        }
    }
    pt(cnt);

    return 0;
}