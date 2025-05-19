#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;

    while(num <= n) {
        if (num % w == 0) num++;
        else num += (w - (num % w)) * 2 + 1;
        answer++;
    }

    return answer;
}
