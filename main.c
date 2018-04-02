#include <stdio.h>

int main() {
    int weight[] = {13, 8, 21, 14, 23, 16};
    int n = sizeof(weight)/sizeof(weight[0]);
    int count = 1;
    for (int i = 0; i < n; i++) count = count*2;

    int maxweight = 0;
    int maxcount = 0;
    int curweight = 0;
    count--;

    while (count >= 0) {
        int copcount = count;
        for (int i = n-1; i >= 0; i--){
            int m = copcount & 1;
            if (m == 1) curweight = curweight+weight[i];
            copcount = copcount >> 1;
        }
        if (maxweight < curweight) {
            maxcount = count;
            maxweight = curweight;
        }
        count--;
    }

    printf("%i, %i", maxcount, maxweight);
    return 0;
}