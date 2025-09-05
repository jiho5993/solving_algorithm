#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define ACC_SIZE 256 // 0 ~ 2^8-1
#define PC_SIZE 32 // 0 ~ 2^5-1

int mem[32];
int acc = 0;
int pc = 0;

int b2i(string s) {
    int res = 0;
    int sz = s.size();
    for (int i=sz-1; i>=0; i--) {
        res += (s[i]-'0') * pow(2, sz-i-1);
    }
    return res;
}

void solve() {
    while (1) {
        acc = 0;
        pc = 0;

        for (int i=0; i<32; i++) {
            string s; cin >> s;
            mem[i] = b2i(s);
            if (cin.eof()) return;
        }

        while (1) {
            int cmd = mem[pc] / 32;
            int op = mem[pc] % 32;

            pc = (pc+1) % PC_SIZE;
    
            if (cmd == 0) {
                mem[op] = acc;
            } else if (cmd == 1) {
                acc = mem[op];
            } else if (cmd == 2) {
                if (acc == 0) {
                    pc = op;
                }
            } else if (cmd == 3) {
                continue;
            } else if (cmd == 4) {
                acc = (acc+255) % ACC_SIZE;
            } else if (cmd == 5) {
                acc = (acc + 1) % ACC_SIZE;
            } else if (cmd == 6) {
                pc = op;
            } else if (cmd == 7) {
                break;
            }
        }
    
        for (int i=7; i>=0; i--) cout << ((acc >> i) & 1);
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
