#include <stdio.h>
#include <string.h>
#include "include/cut_fastq.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <subcommand> [options]\n", argv[0]);
        return 1;
    }
    // 判断用户输入的子命令并调用对应的函数
    if (strcmp(argv[1], "split") == 0) {
        cut_fastq(argc - 1, argv + 1);
    } else {
        fprintf(stderr, "Unknown subcommand: %s\n", argv[1]);
        fprintf(stderr, "Usage: %s <subcommand> [options]\n", argv[0]);
        return 1;
    }

    return 0;
}
