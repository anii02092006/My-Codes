int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int total = 0;

    for (int i = 1; i < pointsSize; i++) {
        int dx = abs(points[i][0] - points[i-1][0]);
        int dy = abs(points[i][1] - points[i-1][1]);

        total += (dx > dy ? dx : dy);
    }

    return total;
}
