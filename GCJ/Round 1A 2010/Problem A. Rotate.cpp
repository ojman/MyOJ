#include <cstdio>
#include <vector>
using namespace std;

bool checkWinner(const vector< vector< int > >& board, int C, int N, int K) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(board[i][j] == C) {
                int k = 0;
                for(int x = j; x < N; ++x) {
                    if(board[i][x] == C) {
                        ++k;
                    } else {
                        break;
                    }
                }
                if(k >= K) {
                    return true;
                }
                k = 0;
                for(int x = j; x >= 0; --x) {
                    if(board[i][x] == C) {
                        ++k;
                    } else {
                        break;
                    }
                }
                if(k >= K) {
                    return true;
                }
                k = 0;
                for(int y = i; y < N; ++y) {
                    if(board[y][j] == C) {
                        ++k;
                    } else {
                        break;
                    }
                }
                if(k >= K) {
                    return true;
                }
                k = 0;
                for(int y = i; y >= 0; --y) {
                    if(board[y][j] == C) {
                        ++k;
                    } else {
                        break;
                    }
                }
                if(k >= K) {
                    return true;
                }
                k = 0;
                for(int y = i, x = j; x < N && y < N; ++y, ++x) {
                    if(board[y][x] == C) {
                        ++k;
                    } else {
                        break;
                    }
                }
                if(k >= K) {
                    return true;
                }
                k = 0;
                for(int y = i, x = j; x >= 0 && y >= 0; --y, --x) {
                    if(board[y][x] == C) {
                        ++k;
                    } else {
                        break;
                    }
                }
                if(k >= K) {
                    return true;
                }
                k = 0;
                for(int y = i, x = j; x >= 0 && y < N; ++y, --x) {
                    if(board[y][x] == C) {
                        ++k;
                    } else {
                        break;
                    }
                }
                if(k >= K) {
                    return true;
                }
                k = 0;
                for(int y = i, x = j; x < N && y >= 0; --y, ++x) {
                    if(board[y][x] == C) {
                        ++k;
                    } else {
                        break;
                    }
                }
                if(k >= K) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T, N, K;
    int space = '.', R = 'R', B = 'B';
    scanf("%d", &T);
    for(int cases = 1; cases <= T; ++cases) {
        printf("Case #%d: ", cases);

        scanf("%d%d", &N, &K);
        vector< int > vec(N, space);
        vector< vector< int > > board(N, vec);

        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                char c;
                while(!((c = getchar()) == space || c == B || c == R)) {
                }
                board[j][N - i - 1] = (int)c;
            }
        }

        int action = 1;
        while(action == 1) {
            action = 0;
            for(int i = N - 1; i >= 0; --i) {
                for(int j = 0; j < N; ++j) {
                    if(i + 1 < N && board[i][j] != space && board[i + 1][j] == space) {
                        board[i + 1][j] = board[i][j];
                        board[i][j] = space;
                        action = 1;
                    }
                }
            }
        }

        int winner = 0;     //  B = 1, R = 2, Both = 3, Nither = 0
        if(checkWinner(board, B, N, K)) {
            winner += 1;
        }
        if(checkWinner(board, R, N, K)) {
            winner += 2;
        }
        switch(winner) {
            case 0:
                puts("Neither");
            break;
            case 1:
                puts("Blue");
            break;
            case 2:
                puts("Red");
            break;
            case 3:
                puts("Both");
            break;
        }
    }
    return 0;
}
