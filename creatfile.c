/*===============================================
*   文件名称：creatfile.c
*   创 建 者：     
*   创建日期：2024年02月19日
*   描    述：
================================================*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> // for close
#include <string.h> // for strlen

#define DEFAULT_FILENAME "test.txt"
#define DEFAULT_CONTENT "hello world!\n"

void write_to_file(const char *filename, const char *content);

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : DEFAULT_FILENAME;
    const char *content = DEFAULT_CONTENT;

    write_to_file(filename, content);

    return 0;
}

void write_to_file(const char *filename, const char *content) {
    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }

    ssize_t bytes_written = write(fd, content, strlen(content));
    if (bytes_written == -1) {
        perror("write");
        close(fd);
        return;
    }

    if (close(fd) == -1) {
        perror("close");
    }
}

