#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

int V, E, res=1e9;
int arr[401][401];

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> V >> E;
    for(int i=1; i<=V; i++)
        for(int j=1; j<=V; j++)
            arr[i][j] = 1e9;
    while(E--) {
        int a, b, c; cin >> a >> b >> c;
        arr[a][b] = c;
    }
    for(int k=1; k<=V; k++)
        for(int i=1; i<=V; i++)
            for(int j=1; j<=V; j++)
                arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
    for(int i=1; i<=V; i++) {
        for(int j=1; j<=V; j++) {
            if(arr[i][j] != 1e9 && arr[j][i] != 1e9)
                res = min(res, arr[i][j]+arr[j][i]);
        }
    }
    res != 1e9 ? cout << res : cout << -1;

    return 0;
}