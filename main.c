#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "files/process.c"
#include "messages/kde.c"
#include "messages/cli.c"

int startPomodoroRound() {
    showCLIStartMessage();
    showKDEStartMessage();

    return 0;
}

int main(int argc, char *args[]) {
    if (strcmp(args[1], "start") == 0) {
        startPomodoroRound();
    }

    if (strcmp(args[1], "list") == 0 ||
        strcmp(args[1], "check") == 0) {
        // checkPomodoroRound();
    }

    if (strcmp(args[1], "stop") == 0) {
        // stopPomodoroRound();
    }

    return 0;
}
