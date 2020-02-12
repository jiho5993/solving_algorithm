#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  unsigned long long n, rs=0, R=1, M=1234567891;
  string s;
  cin >> n >> s;
  for(int i=0; i<n; i++) {
    rs += (s[i]-'a'+1)*R;
    rs %= M;
    R *= 31;
    R %= M;
  }
  cout << rs;

  return 0;
}