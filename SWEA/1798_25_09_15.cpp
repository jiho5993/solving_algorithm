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

#define MAX_TIME 540

int N, M;
int dist[40][40];
vector<pair<int, pair<int, int> > > point;
vector<int> hotel;
int airport = -1;
bool visited[40];

int res=0;
vector<int> res_path;

void dfs(int x, int time, int day, int total, vector<int> path, int depth) {
    if (depth > 0 && x == airport && day == M) {
        if (res < total) {
            res = total;
            res_path = path;
        }
        return;
    }

    bool flag = false;
    for (int i=0; i<point.size(); i++) {
        int nx = point[i].first;
        int d = point[i].second.first;
        int sc = point[i].second.second;
        int t = dist[x][nx];

        if (x == nx || visited[nx]) continue;
        if (time + t + d > MAX_TIME) continue;

        flag = true;
        visited[nx] = true;
        path.push_back(nx);
        dfs(nx, time + t + d, day, total+sc, path, depth+1);
        visited[nx] = false;
        path.pop_back();
    }

    if (flag) return;
    if (day == M) {
        if (time+dist[x][airport] <= MAX_TIME) {
            path.push_back(airport);
            dfs(airport, time+dist[x][airport], day, total, path, depth+1);
            path.pop_back();
        }
    } else {
        for (int h: hotel) {
            if (time+dist[x][h] <= MAX_TIME) {
                path.push_back(h);
                dfs(h, 0, day+1, total, path, depth+1);
                path.pop_back();
            }
        }
    }
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
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        res = 0;
        hotel.clear();
        point.clear();
        res_path.clear();

        cin >> N >> M;
        for (int i=0; i<N-1; i++) {
            for (int j=i+1; j<N; j++) {
                int a; cin >> a;
                dist[i][j] = a;
                dist[j][i] = a;
            }
        }

        for (int i=0; i<N; i++) {
            char a; cin >> a;
            if (a == 'P') {
                int b, c; cin >> b >> c;
                point.push_back({i, {b, c}});
            } else {
                if (a == 'A') airport = i;
                else if (a == 'H') hotel.push_back(i);
            }
        }

        dfs(airport, 0, 1, 0, vector<int>(), 0);
        cout << "#" << test_case << ' ' << res << ' ';
        for (auto i: res_path) cout << i+1 << ' ';
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
