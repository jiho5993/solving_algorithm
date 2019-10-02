#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int lcs[101][101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, c; cin >> a >> b >> c;
    for(int i=1; i<=a.size(); i++) {
        for(int j=1; j<=b.size(); j++) {
            for(int k=1; k<=c.size(); k++) {
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1]) lcs[i][j][k] = lcs[i-1][j-1][k-1]+1;
                else {
                    int n1 = max(max(lcs[i-1][j][k], lcs[i][j-1][k]), lcs[i][j][k-1]);
                    int n2 = max(max(lcs[i-1][j-1][k], lcs[i-1][j][k-1]), lcs[i][j-1][k-1]);
                    lcs[i][j][k] = max(n1, n2);
                }
            }
        }
    }
    cout << lcs[a.size()][b.size()][c.size()];

    return 0;
}