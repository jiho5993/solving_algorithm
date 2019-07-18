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

const int INF = 2147483648;
const int MOD = 1000000007;

int arr[7];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int a, b, c, m;
    bool flag = false;
    cin >> a >> b >> c;
    arr[a]++, arr[b]++, arr[c]++;
    fr(i, 1, 7) {
        if(arr[i] == 3) {
            pt(10000+i*1000);
            flag = true;
        }
        else if(arr[i] == 2) {
            pt(1000 + i * 100);
            flag = true;
        }
        else if(arr[i] == 1) m = i;
    }
    if(!flag) pt(m*100);
    

    return 0;
}