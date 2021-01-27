#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define MAX 1000001

int N, idx=0;
int arr[MAX], ans[MAX];
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    st.push(MAX);
    for(int i=N-1; i>=0; i--) {
        while(st.top() <= arr[i]) st.pop();
        if(st.top() == MAX) ans[idx++] = -1;
        else ans[idx++] = st.top();
        st.push(arr[i]);
    }
    for(int i=N-1; i>=0; i--) cout << ans[i] << ' ';

    return 0;
}