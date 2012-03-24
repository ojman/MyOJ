#include <cstdio>

int neighbor[6][2] = {{-1, -1}, {-1,  0},
                      { 0, -1}, { 0,  1},
                      { 1,  0}, { 1,  1}};
int board[205][205];
int visited[205][205];
int mark[205];
int N;
int count;
const int NOT_VISITED = 0;
const int VISITED = 1;
const int BLACK = 'b';
const int WHITE = 'w';
const int NEIGHBORS = 6;

void get_newline() {
    while(getchar() != '\n') {
    }
}

void input() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            board[i][j] = getchar();
        }
        get_newline();
    }
}

void initialize() {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            visited[i][j] = NOT_VISITED;
        }
    }
    for(int i = 0; i < N; ++i) {
        mark[i] = NOT_VISITED;
    }
    count = 0;
}

bool flood_fill(int& count, int y, int x, int color) {
    if(color == BLACK) {
        if(y >= 0 && y < N && x >= 0 && x < N &&
           visited[y][x] == NOT_VISITED && board[y][x] == BLACK) {
            visited[y][x] = VISITED;
            if(mark[y] == NOT_VISITED) {
                mark[y] = VISITED;
                ++count;
            }
            if(count == N) {
                return true;
            } else {
                for(int i = 0; i < NEIGHBORS; ++i) {
                    int next_y = y + neighbor[i][0];
                    int next_x = x + neighbor[i][1];
                    if(flood_fill(count, next_y, next_x, BLACK)) {
                        return true;
                    }
                }
            }
        }
    } else {
        if(y >= 0 && y < N && x >= 0 && x < N &&
           visited[y][x] == NOT_VISITED && board[y][x] == WHITE) {
            visited[y][x] = VISITED;
            if(mark[x] == NOT_VISITED) {
                mark[x] = VISITED;
                ++count;
            }
            if(count == N) {
                return true;
            } else {
                for(int i = 0; i < NEIGHBORS; ++i) {
                    int next_y = y + neighbor[i][0];
                    int next_x = x + neighbor[i][1];
                    if(flood_fill(count, next_y, next_x, WHITE)) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int cal_winner() {
    for(int i = 0; i < N; ++i) {
        if(board[0][i] == BLACK) {
            initialize();
            if(flood_fill(count, 0, i, BLACK)) {
                return BLACK;
            }
        }
    }
    for(int i = 0; i < N; ++i) {
        if(board[i][0] == WHITE) {
            initialize();
            if(flood_fill(count, i, 0, WHITE)) {
                return WHITE;
            }
        }
    }
    return -1;
}

void output(int cases) {
    printf("%d ", cases);
    if(cal_winner() == BLACK) {
        putchar('B');
    } else {
        putchar('W');
    }
    puts("");
}

int main() {
    for(int cases = 1; ~scanf("%d", &N) && N > 0; ++cases) {
        get_newline();
        input();
        output(cases);
    }
    return 0;
}
