#include <stdio.h>
#include <stdlib.h>

int** gen(int nR, int* rS, int** rCS) {
    if (nR <= 0) {
        *rS = 0;
        return NULL;
    }

    int** tri = (int**)malloc(nR * sizeof(int*));
    *rCS = (int*)malloc(nR * sizeof(int));

    for (int i = 0; i < nR; i++) {
        tri[i] = (int*)malloc((i + 1) * sizeof(int));
        (*rCS)[i] = i + 1;
    }

    for (int i = 0; i < nR; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                tri[i][j] = 1;
            } else {
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }
        }
    }

    *rS = nR;
    return tri;
}

void priTri(int** tri, int nR, int* rCS) {
    printf("[\n");
    for (int i = 0; i < nR; i++) {
        printf("  [");
        for (int j = 0; j < rCS[i]; j++) {
            printf("%d", tri[i][j]);
            if (j < rCS[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < nR - 1) {
            printf(",");
        }
        printf("\n");
    }
    printf("]\n");
}

int main() {
    int nR = 5;
    int rS;
    int* rCS;

    int** tri = gen(nR, &rS, &rCS);

    printf("Output:\n");
    priTri(tri, nR, rCS);

    for (int i = 0; i < nR; i++) {
        free(tri[i]);
    }
    free(tri);
    free(rCS);

    return 0;
}
