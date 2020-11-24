#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;

int arr1[51], arr2[51];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> arr1[i];
    for(int i=0; i<N; i++) cin >> arr2[i];
    sort(arr1, arr1+N);
    sort(arr2, arr2+N, greater<int>());
    int s = 0;
    for(int i=0; i<N; i++) s += (arr1[i]*arr2[i]);
    cout << s;

    return 0;
}