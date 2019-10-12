#include <bits/stdc++.h>
using namespace std;

int N;
int parent[100001];
int arr[100001];

int find(int n) {
    if(parent[n] == n) return n;
    int p = find(parent[n]);
    parent[n] = p;
    return p;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) parent[y] = x;
    arr[x] = arr[x] + arr[y];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        cin >> N;
        for(int i=0; i<100001; i++) {parent[i] = i; arr[i] = 1;}
        map<string, int> info;
        int idx = 0;
        for(int i=0; i<N; i++) {
            string a, b; cin >> a >> b;
            if(!info.count(a)) info[a] = idx++;
            if(!info.count(b)) info[b] = idx++;

            int a_p = find(info[a]);
            int b_p = find(info[b]);

            if(a_p == b_p)
                cout << arr[a_p] << '\n';
            else {
                merge(info[a], info[b]);
                cout << arr[a_p] << '\n';
            }
        }
    }

    return 0;
}