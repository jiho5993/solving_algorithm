#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int MAX = 250001;
bool prime[MAX];

void eratos() {
  prime[1] = 1;
  for(int i=2; i*i<=MAX; i++) {
    if(prime[i]) continue;
    for(int j=i+i; j<=MAX; j+=i) prime[j] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  eratos();
  while(1) {
    int N, ret=0; cin >> N;
    if(!N) break;
    for(int i=N+1; i<=N*2; i++)
      ret += !prime[i];
    cout << ret << '\n';
  }
  
  return 0;
}