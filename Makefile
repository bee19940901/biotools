CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS = -lz

SRC_DIR = src
OBJ_DIR = build
OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/cut_fastq.o

TARGET = biotools

# 编译目标
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

# 编译 main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

# 编译 fastq_processing.o
$(OBJ_DIR)/cut_fastq.o: $(SRC_DIR)/cut_fastq.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/cut_fastq.c -o $(OBJ_DIR)/cut_fastq.o

# 清理
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)

# 创建构建目录
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
