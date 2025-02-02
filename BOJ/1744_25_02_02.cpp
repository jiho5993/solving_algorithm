#include <bits/stdc++.h>
using namespace std;

int p[51], m[51], zero = 0, one = 0;
int p_N = 0, m_N = 0;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int a; cin >> a;
        if (a > 1) p[p_N++] = a;
        else if (a < 0) m[m_N++] = a;
        else if (a == 1) one++;
        else zero++;
    }

    sort(p, p+p_N, cmp);
    sort(m, m+m_N);

    int res = one;

    for (int i=0; i<p_N; i+=2) {
        res += p[i] * (p[i+1] == 0 ? 1 : p[i+1]);
    }

    bool is_left = m_N & 1;
    for (int i=0; i<(is_left ? m_N - 1 : m_N); i+=2) {
        res += m[i] * m[i+1];
    }

    if (is_left && zero == 0) {
        res += m[m_N-1];
    }

    cout << res;

    return 0;
}
