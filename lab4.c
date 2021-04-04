#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include "libsrc/libs/myReadKey.h"
int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);
int main(void)
{
    int fd, read_chars;
    rk_mytermregime(1, 0, 1, 1, 1);
    char buf[6] = {0};

    //char buf[200]; /* Открываем файл для терминала2 на запись*/
    fd = open("/dev/pts/1", O_WRONLY);
    printf("fd = %d\n", fd);
    if (fd == -1)
    {
        fprintf(stderr, "Ошибка открытия терминала.\n");
        return (1);
    } /* Читаем  с  клавиатуры  последовательность  символов  ивыводимих на терминал 2*/
    read(STDIN_FILENO, buf, 6);
    while (buf[0] != 'q')
    {
        read(STDIN_FILENO, buf, 6);
    }

    //if ((read_chars = read(0, buf, 199)) > 0)
    //{
    write(fd, buf, 6);
    //}
    //else
    //{
    //    write(fd, "Ошибка", 6);
    //}
    close(fd);
    rk_mytermregime(0, 0, 0, 0, 0);
    return (0);
}