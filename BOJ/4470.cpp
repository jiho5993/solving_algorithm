#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int n; cin >> n;
  cin.ignore();
  for(int i=1; i<=n; i++) {
    string s; getline(cin, s);
    cout << i << ". " << s << '\n';
  }
  
  return 0;
}