#include <bits/stdc++.h>
using namespace std;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int n;
int tree[30][2];

void pre(int node) {
    if(node == (int)('.'-'A')) return;

    cout << (char)(node+'A');
    pre(tree[node][0]);
    pre(tree[node][1]);
}

void in(int node) {
    if(node == (int)('.'-'A')) return;

    in(tree[node][0]);
    cout << (char)(node+'A');
    in(tree[node][1]);
}

void post(int node) {
    if(node == (int)('.'-'A')) return;

    post(tree[node][0]);
    post(tree[node][1]);
    cout << (char)(node+'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;
    fr(i, 0, n) {
        char a, b, c; cin >> a >> b >> c;
        tree[a-'A'][0] = b-'A';
        tree[a-'A'][1] = c-'A';
    }

    pre(0), cout << '\n';
    in(0), cout << '\n';
    post(0);

    return 0;
}