#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char type[10];     // MESSAGE or OFFLINE
    int timestamp;     // time
    char *arg;         // dynamic string
} Event;

int cmp(const void *a, const void *b) {
    const Event *e1 = (const Event *)a;
    const Event *e2 = (const Event *)b;

    if (e1->timestamp != e2->timestamp)
        return e1->timestamp - e2->timestamp;

    // OFFLINE must be processed BEFORE MESSAGE at same timestamp
    if (strcmp(e1->type, "OFFLINE") == 0 &&
        strcmp(e2->type, "MESSAGE") == 0)
        return -1;

    if (strcmp(e2->type, "OFFLINE") == 0 &&
        strcmp(e1->type, "MESSAGE") == 0)
        return 1;

    return 0;
}

int* countMentions(int numberOfUsers, char*** events, int eventsSize,
                   int* eventsColSize, int* returnSize) {

    *returnSize = numberOfUsers;
    int *mentions = calloc(numberOfUsers, sizeof(int));

    int online[101];
    int offlineTill[101];

    for (int i = 0; i < numberOfUsers; i++) {
        online[i] = 1;
        offlineTill[i] = -1;
    }

    // Build sortable list of events
    Event *list = malloc(sizeof(Event) * eventsSize);

    for (int i = 0; i < eventsSize; i++) {
        strcpy(list[i].type, events[i][0]);
        list[i].timestamp = atoi(events[i][1]);

        int len = strlen(events[i][2]);
        list[i].arg = malloc(len + 1);
        strcpy(list[i].arg, events[i][2]);
    }

    // Sort events
    qsort(list, eventsSize, sizeof(Event), cmp);

    // Process events in correct order
    for (int i = 0; i < eventsSize; i++) {
        int t = list[i].timestamp;

        // Auto-online restoration before processing event
        for (int u = 0; u < numberOfUsers; u++) {
            if (!online[u] && offlineTill[u] <= t) {
                online[u] = 1;
            }
        }

        // OFFLINE event
        if (strcmp(list[i].type, "OFFLINE") == 0) {
            int uid = atoi(list[i].arg);
            online[uid] = 0;
            offlineTill[uid] = t + 60;
        }

        // MESSAGE event
        else {
            char *msg = list[i].arg;

            if (strcmp(msg, "ALL") == 0) {
                for (int u = 0; u < numberOfUsers; u++)
                    mentions[u]++;
            }
            else if (strcmp(msg, "HERE") == 0) {
                for (int u = 0; u < numberOfUsers; u++)
                    if (online[u]) mentions[u]++;
            }
            else {
                // id<number> parsing
                char *temp = malloc(strlen(msg) + 1);
                strcpy(temp, msg);

                char *tok = strtok(temp, " ");
                while (tok) {
                    if (strncmp(tok, "id", 2) == 0) {
                        int uid = atoi(tok + 2);
                        if (uid >= 0 && uid < numberOfUsers)
                            mentions[uid]++;
                    }
                    tok = strtok(NULL, " ");
                }

                free(temp);
            }
        }
    }

    // free dynamic memory
    for (int i = 0; i < eventsSize; i++)
        free(list[i].arg);

    free(list);

    return mentions;
}
