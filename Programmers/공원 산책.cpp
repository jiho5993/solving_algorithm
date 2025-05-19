#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> cur(2);

    int N = park.size(), M = park[0].size();

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (park[i][j] == 'S') {
                cur[0] = i, cur[1] = j;
                break;
            }
        }
    }

    for (string route: routes) {
        char op = route[0];
        int n = stoi(route.substr(2));

        pair<int, int> tmp;
        if (op == 'E') tmp = {0, 1};
        else if (op == 'W') tmp = {0, -1};
        else if (op == 'S') tmp = {1, 0};
        else tmp = {-1, 0};

        int nx = cur[0] + tmp.first * n;
        int ny = cur[1] + tmp.second * n;
        if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;

        bool flag = false;
        int mn_x = min(cur[0], nx), mx_x = max(cur[0], nx);
        int mn_y = min(cur[1], ny), mx_y = max(cur[1], ny);
        for (int i=mn_x; i<=mx_x; i++) {
            if (park[i][cur[1]] == 'X') {
                flag = true;
                break;
            }
        }
        for (int i=mn_y; i<=mx_y; i++) {
            if (park[cur[0]][i] == 'X') {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        cur[0] = nx, cur[1] = ny;
    }

    return cur;
}
