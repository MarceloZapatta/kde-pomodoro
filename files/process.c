int writeProcessFileLock() {
    char * home = getenv("HOME");
    char * filePath;
    FILE * fp;

    if (!home) {
        printf("HOME enviroment not found.");
        return 0;
    }

    sprintf(filePath, "%s/.pomodoro-cli/process.lock", home);

    fp = fopen(filePath, "w");

    fprintf(fp, "%u", getpid());

    fclose(fp);

    return 0;
}