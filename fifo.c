#include "page_replacement.h"

/**
 * FIFO页面置换算法实现
 * FIFO (First In First Out) 算法总是淘汰最先进入内存的页面
 * 
 * @param reference_string 页面引用串
 * @param reference_length 页面引用串长度
 * @param frame_count 内存帧数
 * @return 缺页次数
 */
int fifo_algorithm(int reference_string[], int reference_length, int frame_count) {
    // 初始化内存帧
    Frame* frames = (Frame*)malloc(frame_count * sizeof(Frame));
    for (int i = 0; i < frame_count; i++) {
        frames[i].page_number = -1;  // -1表示空帧
        frames[i].occupied = false;
    }
    
    int page_faults = 0;  // 缺页次数
    int front = 0;        // 队列前端指针（用于FIFO）
    
    printf("\n页面引用串: ");
    for (int i = 0; i < reference_length; i++) {
        printf("%d ", reference_string[i]);
    }
    printf("\n\n");
    
    // 处理每个页面引用
    for (int i = 0; i < reference_length; i++) {
        int current_page = reference_string[i];
        bool page_found = false;
        
        // 检查页面是否已在内存中
        for (int j = 0; j < frame_count; j++) {
            if (frames[j].occupied && frames[j].page_number == current_page) {
                page_found = true;
                break;
            }
        }
        
        // 如果页面不在内存中，发生缺页中断
        if (!page_found) {
            page_faults++;
            
            // 查找空闲帧
            int free_frame = -1;
            for (int j = 0; j < frame_count; j++) {
                if (!frames[j].occupied) {
                    free_frame = j;
                    break;
                }
            }
            
            if (free_frame != -1) {
                // 有空闲帧，直接放入
                frames[free_frame].page_number = current_page;
                frames[free_frame].occupied = true;
            } else {
                // 没有空闲帧，需要置换页面
                // 根据FIFO算法，置换最早进入的页面
                frames[front].page_number = current_page;
                // 更新队列前端指针，循环队列实现
                front = (front + 1) % frame_count;
            }
            
            // 打印当前内存状态
            printf("访问页面 %d: ", current_page);
            for (int j = 0; j < frame_count; j++) {
                if (frames[j].occupied) {
                    printf("%d ", frames[j].page_number);
                } else {
                    printf("- ");
                }
            }
            printf("(缺页)\n");
        } else {
            // 页面已在内存中
            printf("访问页面 %d: ", current_page);
            for (int j = 0; j < frame_count; j++) {
                if (frames[j].occupied) {
                    printf("%d ", frames[j].page_number);
                } else {
                    printf("- ");
                }
            }
            printf("(命中)\n");
        }
    }
    
    free(frames);
    return page_faults;
}