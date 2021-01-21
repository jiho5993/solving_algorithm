#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M;
int arr[27][27];

void foo() {
    for(int k=0; k<26; k++)
        for(int i=0; i<26; i++)
            for(int j=0; j<26; j++)
                arr[i][j] = min(arr[i][k]+arr[k][j], arr[i][j]);
}

int main() {
    ios_base::sync_with_stdio(false),cin.tie(0);

    for(int i=0; i<26; i++)
        for(int j=0; j<26; j++)
            if(i != j) arr[i][j] = INF;
    cin >> N;
    cin.ignore();
    for(int i=0; i<N; i++) {
        string s; getline(cin, s);
        arr[s[0]-'a'][s[s.size()-1]-'a'] = 1;
    }
    foo();
    cin >> M;
    cin.ignore();
    for(int i=0; i<M; i++) {
        string s; getline(cin, s);
        if(arr[s[0]-'a'][s[s.size()-1]-'a'] != INF) cout << "T\n";
        else cout << "F\n";
    }

    return 0;
}