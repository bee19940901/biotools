#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>  // 需要添加头文件支持 getopt_long

#define MAX_LINE_LENGTH 1000

// 读取一行内容
int read_line(FILE *file, char *line, int max_length) {
    if (fgets(line, max_length, file) != NULL) {
        line[strcspn(line, "\n")] = '\0';  // 移除行末的换行符
        return 1;
    }
    return 0;
}

// 处理 fastq 文件
void process_fastq(FILE *in_file, FILE *out_file, int cutoff) {
    char line[MAX_LINE_LENGTH];
    while (1) {
        if (!read_line(in_file, line, MAX_LINE_LENGTH)) break;
        fprintf(out_file, "%s\n", line);  // 输出第一行

        if (!read_line(in_file, line, MAX_LINE_LENGTH)) break;
        line[cutoff] = '\0';  // 截断第二行
        fprintf(out_file, "%s\n", line);

        if (!read_line(in_file, line, MAX_LINE_LENGTH)) break;
        fprintf(out_file, "%s\n", line);  // 输出第三行

        if (!read_line(in_file, line, MAX_LINE_LENGTH)) break;
        line[cutoff] = '\0';  // 截断第四行
        fprintf(out_file, "%s\n", line);
    }
}

// 主函数，解析命令行参数
void split_fastq(int argc, char *argv[]) {
    int cutoff = 50;
    char *in_file_path = NULL;
    char *out_file_path = NULL;

    struct option long_options[] = {
            {"input", required_argument, NULL, 'i'},
            {"output", required_argument, NULL, 'o'},
            {"cutoff", required_argument, NULL, 'c'},
            {NULL, 0, NULL, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "i:o:c:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'i':
                in_file_path = optarg;
                break;
            case 'o':
                out_file_path = optarg;
                break;
            case 'c':
                cutoff = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: bedtools split  --input <input_file> --output <output_file> --cutoff <cutoff>\n");
                return;
        }
    }

    if (in_file_path == NULL || out_file_path == NULL) {
        fprintf(stderr, "Error: input and output files are required.\n");
        return;
    }

    FILE *in_file = fopen(in_file_path, "r");
    if (!in_file) {
        fprintf(stderr, "Error opening input file: %s\n", in_file_path);
        return;
    }

    FILE *out_file = fopen(out_file_path, "w");
    if (!out_file) {
        fprintf(stderr, "Error opening output file: %s\n", out_file_path);
        fclose(in_file);
        return;
    }

    process_fastq(in_file, out_file, cutoff);

    fclose(in_file);
    fclose(out_file);
}
