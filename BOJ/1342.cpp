#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

string s;
int arr[26], ret;

void foo(char bf, int idx) {
  if(s.size() == idx) {
    ret++;
    return;
  }

  for(int i=0; i<26; i++) {
    if(!arr[i] || 'a'+i == bf) continue;
    arr[i]--;
    foo('a'+i, idx+1);
    arr[i]++;
  }
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);

  cin >> s;
  for(int i=0; i<s.size(); i++) arr[s[i]-'a']++;
  foo(0, 0);
  cout << ret;

  return 0;
}