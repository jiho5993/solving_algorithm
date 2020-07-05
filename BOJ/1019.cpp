#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int arr[10];

void foo1(int n, int val) {
  while(n) {
    arr[n%10] += val;
    n /= 10;
  }
}

void foo2(int a, int b, int val) {
  while(a%10 != 0 && a <= b) {
    foo1(a, val);
    a++;
  }
  if(a > b) return;
  while(b%10 != 9 && b >= a) {
    foo1(b, val);
    b--;
  }
  for(auto &i:arr) i += (b/10 - a/10 + 1) * val;
  foo2(a/10, b/10, val*10);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N; cin >> N;
  foo2(1, N, 1);
  for(auto i:arr) cout << i << ' ';
  
  return 0;
}