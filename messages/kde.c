int showKDEStartMessage() {
    if (fork() == 0) {
        if (fork() == 0) {
            execl(
                "/usr/bin/kdialog", 
                "/usr/bin/kdialog",  
                "--title",
                "Pomodoro CLI",
                "--passivepopup", 
                "Iniciar um ciclo pomodoro: 25 minutos", 
                NULL
            );

        } else {
            writeProcessFileLock();
            
            sleep(30);

            execl(
                "/usr/bin/kdialog", 
                "/usr/bin/kdialog",  
                "--title",
                "Pomodoro CLI",
                "--msgbox", 
                "Pomodoro finalizado!", 
                NULL
            );
        }

        printf("passou o exec né!\n"); 
    }

    return 0;
}
