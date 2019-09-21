#include <bits/stdc++.h>
#define mp(a, b) make_pair((a), (b))
using namespace std;

int n, me, mn;
int r, li, si, cnt;
vector<pair<int, int> > vp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> me >> mn;
        vp.push_back(mp(me, mn));
    }
    cin >> r;
    for(int i=0; i<r; i++) {
        cin >> li;
        cnt = li;
        vector<int> cl;
        for(int j=0; j<li; j++) {
            cin >> si;
            for(int k=0; k<n; k++) {
                if(vp[k].first == si) {
                    cl.push_back(vp[k].second);
                    cnt--;
                    break;
                }
            }
        }
        if(!cnt) {for(int i : cl) printf("%d ", i);}
        else printf("YOU DIED");
        printf("\n");
    }

    return 0;
}