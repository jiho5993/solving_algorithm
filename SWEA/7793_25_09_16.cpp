/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

#define SUYEON 1
#define GODDESS 2
#define DEVIL -1
#define ROCK -2

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int N, M;
int arr[51][51];
bool visited[51][51];
int devil_arr[51][51];
int st[2], en[2];

bool is_range(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

void spread(queue<pair<int, int> > q) {
    int t = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (!is_range(nx, ny)) continue;
                if (arr[nx][ny] == ROCK || arr[nx][ny] == GODDESS) continue;
                if (devil_arr[nx][ny] > devil_arr[x][y]+1) {
                    devil_arr[nx][ny] = devil_arr[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
        t++;
    }

}

int bfs() {
    queue<pair<int, pair<int, int > > > qp;

    qp.push({0, {st[0], st[1]}});
    visited[st[0]][st[1]] = true;

    int res = 1e9;
    while (!qp.empty()) {
        int cnt = qp.front().first;
        int x = qp.front().second.first, y = qp.front().second.second;
        qp.pop();
        
        if (x == en[0] && y == en[1]) {
            res = min(res, cnt);
            continue;
        }

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!is_range(nx, ny)) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] == ROCK) continue;
            if (devil_arr[nx][ny] <= cnt+1) continue;
            visited[nx][ny] = true;
            qp.push({cnt+1, {nx, ny}});
        }
    }

    return res;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        for (int i=0; i<51; i++) fill(devil_arr[i], devil_arr[i]+51, 1e9);
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        
        queue<pair<int, int> > dsq;

        cin >> N >> M;

        for (int i=0; i<N; i++) {
            string s; cin >> s;
            for (int j=0; j<M; j++) {
                if (s[j] == 'S') {
                    arr[i][j] = SUYEON;
                    st[0] = i, st[1] = j;
                } else if (s[j] == 'D') {
                    arr[i][j] = GODDESS;
                    en[0] = i, en[1] = j;
                } else if (s[j] == '*') {
                    arr[i][j] = DEVIL;
                    devil_arr[i][j] = 0;
                    dsq.push({i, j});
                } else if (s[j] == 'X') arr[i][j] = ROCK;
            }
        }

        spread(dsq);
        int res = bfs();

        cout << "#" << test_case << ' ';
        if (res == 1e9) cout << "GAME OVER\n";
        else cout << res << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
