#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int K, L;
string arr[500005];
map<string, int> m;

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> K >> L;
  for(int i=0; i<L; i++) {
    cin >> arr[i];
    m[arr[i]] = i;
  }
  int cnt=0;
  for(int i=0; i<L; i++) {
    if(cnt == K) break;
    if(m[arr[i]] == i) {
      cout << arr[i] << '\n';
      cnt++;
    }
  }
  
  return 0;
}