#ifndef FASTQ_PROCESSING_H
#define FASTQ_PROCESSING_H

#include <zlib.h>
#include <getopt.h>

void split_fastq(int argc, char *argv[]);
void process_fastq(gzFile in_file, gzFile out_file, int cutoff);
int read_line(gzFile file, char *line, int max_length);

#endif // FASTQ_PROCESSING_H
