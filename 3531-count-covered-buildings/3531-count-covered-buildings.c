#include <limits.h>
#include <stdlib.h>

int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
    if (buildingsSize == 0) return 0;

    // allocate arrays for rows and columns
    int *minY = malloc((n + 1) * sizeof(int));
    int *maxY = malloc((n + 1) * sizeof(int));
    int *minX = malloc((n + 1) * sizeof(int));
    int *maxX = malloc((n + 1) * sizeof(int));

    // initialize
    for (int i = 1; i <= n; i++) {
        minY[i] = INT_MAX;
        maxY[i] = INT_MIN;
        minX[i] = INT_MAX;
        maxX[i] = INT_MIN;
    }

    // fill min/max for rows and columns
    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];

        if (y < minY[x]) minY[x] = y;
        if (y > maxY[x]) maxY[x] = y;

        if (x < minX[y]) minX[y] = x;
        if (x > maxX[y]) maxX[y] = x;
    }

    int covered = 0;

    // check each building
    for (int i = 0; i < buildingsSize; i++) {
        int x = buildings[i][0];
        int y = buildings[i][1];

        // must have both left & right buildings
        if (minY[x] < y && y < maxY[x] &&
            minX[y] < x && x < maxX[y]) {

            covered++;
        }
    }

    free(minY);
    free(maxY);
    free(minX);
    free(maxX);

    return covered;
}
