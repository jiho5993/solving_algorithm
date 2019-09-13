#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int n, l, a[101][101], b[101][101], rs=0;

void chk(int idx, int arr[101][101]) {
    bool chk_arr[101]={false, };
    fr(i, 0, n-1) {
        if(arr[idx][i] != arr[idx][i+1]) {
            int d = arr[idx][i] - arr[idx][i+1];
            if(abs(d) != 1) return;

            if(d == -1) {
                fr(j, 0, l) {
                    if(i-j < 0 || chk_arr[i-j] == 1) return;
                    if(arr[idx][i] == arr[idx][i-j]) chk_arr[i-j] = true;
                    else return;
                }
            } else {
                fr(j, 1, l+1) {
                    if(i+j >= n || chk_arr[i+j] == 1) return;
                    if(arr[idx][i]-1 == arr[idx][i+j]) chk_arr[i+j] = true;
                    else return;
                }
            }
        }
    }
    rs++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> l;
    fr(i, 0, n)
        fr(j, 0, n) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    fr(i, 0, n) {
        chk(i, a);
        chk(i, b);
    }
    cout << rs;

    return 0;
}