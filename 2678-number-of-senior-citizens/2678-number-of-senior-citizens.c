int countSeniors(char **details, int detailsSize) {
    int count = 0;

    for (int i = 0; i < detailsSize; i++) {
        // Age is located at index 11 and 12
        int age = (details[i][11] - '0') * 10 + (details[i][12] - '0');

        if (age > 60)
            count++;
    }

    return count;
}
