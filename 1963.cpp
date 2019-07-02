#include <bits/stdc++.h>
using namespace std;

int t, a, b;
bool visit[10001], arr[10001];

void eratos() {
    for(int i=0; i<10001; i++) arr[i] = 1;
    for(int i=2; i<10001; i++) {
        if(!arr[i]) continue;
        for(int j=i+i; j<10001; j+=i) arr[j] = 0;
    }
}

void bfs(int start, int end) {
    int cnt=0;
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            int c = q.front();
            q.pop();
            if(c == end) {printf("%d\n", cnt); return;}
            for(int j=0; j<4; j++) {
                string tmp = to_string(c);
                for(int k='0'; k<='9'; k++) {
                    tmp[j] = k;
                    int idx = stoi(tmp);
                    if(arr[idx] && !visit[idx] && idx >= 1000) {
                        visit[idx] = 1;
                        q.push(idx);
                    }
                }
            }
        }
        cnt++;
    }
    printf("Impossible\n");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    eratos();
    cin >> t;
    while(t--) {
        cin >> a >> b;
        memset(visit, 0, 10000*sizeof(bool));
        bfs(a, b);
    }

    return 0;
}