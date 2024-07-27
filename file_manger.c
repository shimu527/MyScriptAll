#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // 获取当前目录
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));

  // 打开当前目录
  DIR *dir = opendir(cwd);
  if (dir == NULL) {
    perror("opendir");
    return 1;
  }

  // 遍历目录中的所有文件
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // 打印文件名
    printf("%s\n", entry->d_name);
  }

  // 关闭目录
  closedir(dir);

  return 0;
}
