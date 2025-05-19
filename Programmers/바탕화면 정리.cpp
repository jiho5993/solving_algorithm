#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {51, 51, -1, -1};

    for (int i=0; i<wallpaper.size(); i++) {
        for (int j=0; j<wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i+1);
                answer[3] = max(answer[3], j+1);
            }
        }
    }

    return answer;
}
