#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_TEST
constexpr bool isLOCAL = true;
#else
constexpr bool isLOCAL = false;
#endif

#define debug if constexpr (isLOCAL) cerr

#define pii pair<int, int>

#define SOLD_LAND -100
#define GOLD_KEY -50
#define START -1
#define DESERT_ISLAND -2
#define WELFARE -3
#define SPACE -4

int N, S, W, G, MX_N=0;
queue<pii> gold_key_q;
/**
 * -100: 팔린 땅
 * -50: 황금 열쇠
 * -1: 시작
 * -2: 무인도
 * -3: 사회복지기금
 * -4: 우주여행
 * 자연수: 팔리지 않은 땅
 */
int board[50], b_idx = 0;
int remain_land;
int lock_move = 0;
int acc_price = 0;
bool win_flag = true;

void init_board();
pii get_gold_key();
void move(int d);
void buy_land(int idx);
void start_cell();
void desert_island_cell();
void welfare_cell();
void space_cell();
void action();
void gold_key_cell();

void start_game() {
    int I; cin >> I;

    while (I--) {
        if (!win_flag) {
            cout << "LOSE";
            return;
        }

        int a, b; cin >> a >> b;

        if (lock_move > 0) {
            if (a == b) lock_move = 0;
            else lock_move--;
            continue;
        }

        move(a + b);

        action();
    }
    if (!win_flag) cout << "LOSE";
    else if (remain_land == 0) cout << "WIN";
    else if (remain_land > 0) cout << "LOSE";
}

void init_board() {
    board[0] = START;
    board[N-1] = DESERT_ISLAND;
    board[2*N-2] = WELFARE;
    board[3*N-3] = SPACE;

    for (int i=0; i<4*N-8; i++) {
        char a; cin >> a;
        while (board[MX_N] != 0) MX_N++;
        if (a == 'G') board[MX_N] = GOLD_KEY;
        else if (a == 'L') {
            int b; cin >> b;
            board[MX_N] = b;
            remain_land++;
        }
        MX_N++;
    }
}

pii get_gold_key() {
    pii res = gold_key_q.front();
    gold_key_q.pop();
    gold_key_q.push(res);
    return res;
}

void move(int d) {
    b_idx += d;
    if (b_idx >= MX_N) {
        S += W * (b_idx / MX_N);
    }
    b_idx %= MX_N;
}

void buy_land(int idx) {
    int p = board[idx];
    if (p > S) return;

    board[idx] = SOLD_LAND;
    S -= p;
    remain_land--;
}

void start_cell() {
    S += W;
}

void desert_island_cell() {
    lock_move = 3;
}

void welfare_cell() {
    S += acc_price;
    acc_price = 0;
}

void space_cell() {
    b_idx = 0;
    start_cell();
}

void action() {
    int t = board[b_idx];

    if (t > 0) buy_land(b_idx);
    else if (t == SOLD_LAND) return;
    else if (t == START) return;
    else if (t == DESERT_ISLAND) desert_island_cell();
    else if (t == WELFARE) welfare_cell();
    else if (t == SPACE) space_cell();
    else if (t == GOLD_KEY) gold_key_cell();
}

void gold_key_cell() {
    pii g = get_gold_key();

    switch (g.first)
    {
    case 1:
        S += g.second;
        break;

    case 2:
        if (S < g.second) {
            win_flag = false;
            break;
        }
        S -= g.second;
        break;

    case 3:
        if (S < g.second) {
            win_flag = false;
            break;
        }
        acc_price += g.second;
        S -= g.second;
        break;
    
    case 4:
        move(g.second);
        action();
        break;
    
    default:
        break;
    }
}

void solve() {
    cin >> N >> S >> W >> G;
    while (G--) {
        int a, b; cin >> a >> b;
        gold_key_q.push({a, b});
    }

    init_board();
    start_game();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    solve();

    debug << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
