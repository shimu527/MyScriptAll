#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void print_file_type(mode_t mode) {
    printf("+----------------+---------------+\n");
    printf("| 文件类型       | 状态          |\n");
    printf("+----------------+---------------+\n");
    printf("| 普通文件       | %s            |\n", S_ISREG(mode) ? "(✓)" : "   ");
    printf("| 目录           | %s            |\n", S_ISDIR(mode) ? "(✓)" : "   ");
    printf("| 字符设备       | %s            |\n", S_ISCHR(mode) ? "(✓)" : "   ");
    printf("| 块设备         | %s            |\n", S_ISBLK(mode) ? "(✓)" : "   ");
    printf("| 管道           | %s            |\n", S_ISFIFO(mode) ? "(✓)" : "   ");
    printf("| 符号链接       | %s            |\n", S_ISLNK(mode) ? "(✓)" : "   ");
    printf("| 未知类型       | %s            |\n", !S_ISREG(mode) && !S_ISDIR(mode) && !S_ISCHR(mode) && !S_ISBLK(mode) && !S_ISFIFO(mode) && !S_ISLNK(mode) ? "(✓)" : "   ");
    printf("+----------------+---------------+\n");
}

void format_time(time_t t) {
    struct tm *tm = localtime(&t);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm);
    printf("文件创建时间: %s\n", time_str);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "用法: %s <文件路径>\n", argv[0]);
        return 1;
    }

    struct stat st;
    if (stat(argv[1], &st) == -1) {
        perror("stat");
        return 1;
    }

    print_file_type(st.st_mode);
    printf("文件大小: %ld 字节\n", st.st_size);
    format_time(st.st_ctime);

    return 0;
}

