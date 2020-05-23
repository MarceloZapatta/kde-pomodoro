#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "kde-messages.c"
#include "cli-messages.c"

int startPomodoroRound() {
    showCLIStartMessage();
    showKDEStartMessage();

    return 0;
}

int main(int argc, char *args[]) {
    if (strcmp(args[1], "start") == 0) {
        startPomodoroRound();
    }

    if (strcmp(args[1], "stop") == 0) {
        // stopPomodoroRound();
    }

    printf("%s\n", "não estou morto!");
    return 0;
}
