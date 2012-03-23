#include <cstdio>
#include <cstring>

long long transform(char* symbol, int len_c) {
    long long d10 = 0;
    if(len_c > 0) {
        char symbol_m[100] = {0};
        symbol_m[0] = 1;
        int num = 0;
        for(int i = 1; i < len_c; ++i) {
            int j;
            for(j = 0; j < i; ++j) {
                if(symbol[i] == symbol[j]) {
                    symbol_m[i] = symbol_m[j];
                    break;
                }
            }
            if(j == i) {
                if(num == 1) {
                    num = 2;
                }
                symbol_m[i] = char(num);
                ++num;
            }
        }
        if(num == 1 || num == 0) {
            num = 2;
        }
        long long t = 1, c = 0;
        for(int i = len_c - 1; i >= 0; --i, t *= num) {
            d10 += symbol_m[i] * t + c;
        }
    }
    return d10;
}

int main() {
    int cases;
    scanf("%d", &cases);

    const int SIZE = 100;
    char symbol[SIZE];

    for(int i = 1; i <= cases; ++i) {
        printf("Case #%d: ", i);
        scanf("%s", symbol);
        printf("%lld\n", transform(symbol, strlen(symbol)));
    }
    return 0;
}
