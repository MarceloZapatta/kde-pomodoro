#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libconfig.h>
#include <pwd.h>
#include "files/process.c"
#include "messages/kde.c"
#include "messages/cli.c"

int startPomodoroRound() {
    showCLIStartMessage();
    showKDEStartMessage();

    return 0;
}

int main(int argc, char *args[]) {
    config_t cfg;
    config_setting_t *setting;
    int tempoCiclo;

	config_init(&cfg);

    const char *homePath;

    if ((homePath = getenv("HOME")) == NULL) {
        homePath = getpwuid(getuid())->pw_dir;
    }

    const char *fileName = "pomodoro.cfg";
    const char *configPath;

    strcat(configPath, homePath);
    strcat(configPath, "/.pomodoro-cli/");
    strcat(configPath, fileName);

	if (!config_read_file(&cfg, &configPath)) {
		fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
            config_error_line(&cfg), config_error_text(&cfg));
        config_destroy(&cfg);
        return(EXIT_FAILURE);
	}

    if (config_lookup_int(&cfg, "tempoCiclo", &tempoCiclo)) {
        printf("Tempo de ciclo pomodoro: %d\n", tempoCiclo);
        exit;
    } else {
        printf("Não encontrou");
    }

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
