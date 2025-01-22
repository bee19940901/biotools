#ifndef FASTQ_PROCESSING_H
#define FASTQ_PROCESSING_H

#include <getopt.h>

void cut_fastq(int argc, char *argv[]);
int read_line(FILE *file, char *line, int max_length);

#endif // FASTQ_PROCESSING_H
