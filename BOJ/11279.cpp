#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<int> pqi;

#define fr(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define pt(a) cout << (a) << '\n'
#define pt1(a) cout << (a) << ' '
#define pt2(a, b) cout << (a) << ' ' << (b) << ' '

const int INF = 1e9;
const int MOD = 1000000007;

int heap[100001];
int heap_size=0;

void pop() {
    if(!heap_size) return;
    heap[1] = heap[heap_size--];
    int idx = 1;
    while(2*idx <= heap_size) {
        int left_ch = 2*idx;
        int right_ch = 2*idx+1;
        int min_idx;
        if(heap[left_ch] > heap[right_ch]) min_idx = left_ch;
        else min_idx = right_ch;
        if(heap[min_idx] < heap[idx]) break;
        swap(heap[min_idx], heap[idx]);
        idx = min_idx;
    }
}

void push(int val) {
    heap[++heap_size] = val;
    int idx = heap_size;
    while(idx != 1) {
        int par = idx/2;
        if(heap[par] > heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top() {
    if(!heap_size) return 0;
    else return heap[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n; cin >> n;
    while(n--) {
        int val; cin >> val;
        if(!val) {
            pt(top());
            pop();
        }
        else push(val);
    }

    return 0;
}