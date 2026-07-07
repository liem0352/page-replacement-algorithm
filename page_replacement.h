#ifndef PAGE_REPLACEMENT_H
#define PAGE_REPLACEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义最大页面数和内存帧数
#define MAX_PAGES 100
#define MAX_FRAMES 10

// 页面结构体（用于扩展功能）
typedef struct {
    int page_number;     // 页号
    int last_used_time;  // 上次使用时间（用于LRU算法）
    bool valid;          // 有效位，表示该页面是否在内存中
} Page;

// 内存帧结构体
typedef struct {
    int page_number;     // 当前帧中的页号
    bool occupied;       // 占用标志
} Frame;

// 函数声明

/**
 * 初始化内存帧数组
 * @param frames 内存帧数组
 * @param frame_count 帧数量
 */
void initialize_frames(Frame frames[], int frame_count);

/**
 * 初始化页面数组
 * @param pages 页面数组
 * @param page_count 页面数量
 */
void initialize_pages(Page pages[], int page_count);

/**
 * 打印当前内存状态
 * @param frames 内存帧数组
 * @param frame_count 帧数量
 */
void print_memory_state(Frame frames[], int frame_count);

/**
 * FIFO页面置换算法
 * @param reference_string 页面引用串
 * @param reference_length 页面引用串长度
 * @param frame_count 内存帧数
 * @return 缺页次数
 */
int fifo_algorithm(int reference_string[], int reference_length, int frame_count);

/**
 * LRU页面置换算法
 * @param reference_string 页面引用串
 * @param reference_length 页面引用串长度
 * @param frame_count 内存帧数
 * @return 缺页次数
 */
int lru_algorithm(int reference_string[], int reference_length, int frame_count);

/**
 * 打印菜单选项
 */
void print_menu();

#endif