/*===============================================
*   文件名称：readfile.c
*   创 建 者：     
*   创建日期：2024年02月19日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // for close
#include <stdlib.h> // for exit

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    char buf[BUFFER_SIZE];
    ssize_t n;

    if (argc != 2) {
        fprintf(stderr, "用法: %s <文件路径>\n", argv[0]);
        return 1;
    }

    // open file
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // read data from file
    while ((n = read(fd, buf, sizeof(buf) - 1)) > 0) {
        buf[n] = '\0'; // Null-terminate the buffer to print it as a string
        printf("%s", buf);
    }

    if (n == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    // close file
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}

