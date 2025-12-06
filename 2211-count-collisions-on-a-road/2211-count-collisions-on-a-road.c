int countCollisions(char *directions) {
    int n = strlen(directions);
    int i = 0, j = n - 1;

    // skip leading 'L'
    while (i < n && directions[i] == 'L')
        i++;

    // skip trailing 'R'
    while (j >= 0 && directions[j] == 'R')
        j--;

    int collisions = 0;
    for (int k = i; k <= j; k++) {
        if (directions[k] == 'R' || directions[k] == 'L')
            collisions++;
    }

    return collisions;
}

        