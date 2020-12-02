#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int N, res=0;
int arr[30001];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N; i++) {
        int t = arr[i], cnt=0;;
        for(int j=i+1; j<N; j++) {
            if(arr[j] > t) break;
            else cnt++;
        }
        res = max(res, cnt);
    }
    cout << res;

    return 0;
}