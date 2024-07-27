/*===============================================
*   文件名称：system_info.c
*   创 建 者：     
*   创建日期：2024年02月19日
*   描    述： 获取并显示系统信息
================================================*/

#include <stdio.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

void print_system_info();

int main() {
    print_system_info();
    return 0;
}

void print_system_info() {
    struct utsname buf;
    struct sysinfo info;

    if (uname(&buf) == -1) {
        perror("uname");
        return;
    }

    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        return;
    }

    // Calculate memory in MB
    long total_ram_mb = info.totalram / 1024 / 1024;
    long free_ram_mb = info.freeram / 1024 / 1024;
    long uptime_minutes = info.uptime / 60;

    // Print system info in a table
    printf("+-------------------+-------------------+\n");
    printf("| 系统信息          | 状态              |\n");
    printf("+-------------------+-------------------+\n");
    printf("| 操作系统          | %-17s |\n", buf.sysname);
    printf("| 内核版本          | %-17s |\n", buf.release);
    printf("| CPU 架构          | %-17s |\n", buf.machine);
    printf("| 总内存大小        | %-13ld MB |\n", total_ram_mb);
    printf("| 可用内存大小      | %-13ld MB |\n", free_ram_mb);
    printf("| 系统运行时间      | %-12ld 分钟 |\n", uptime_minutes);
    printf("| 当前进程数        | %-17d |\n", info.procs);
    printf("+-------------------+-------------------+\n");
}

