#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  int N; cin >> N;
  priority_queue<int, vector<int>, less<int> > mx;
  priority_queue<int, vector<int>, greater<int> > mn;
  while(N--) {
    int val; cin >> val;
    if(mx.empty() || mx.size() == mn.size()) mx.push(val);
    else mn.push(val);

    if(!mx.empty() && !mn.empty() && !(mx.top() <= mn.top())) {
      int a = mx.top(), b = mn.top();
      mx.pop();
      mn.pop();
      mx.push(b);
      mn.push(a);
    }
    cout << mx.top() << '\n';
  }

  return 0;
}