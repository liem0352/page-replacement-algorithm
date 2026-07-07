#include "page_replacement.h"

/**
 * LRU页面置换算法实现
 * LRU (Least Recently Used) 算法淘汰最近最久未被访问的页面
 * 
 * @param reference_string 页面引用串
 * @param reference_length 页面引用串长度
 * @param frame_count 内存帧数
 * @return 缺页次数
 */
int lru_algorithm(int reference_string[], int reference_length, int frame_count) {
    // 初始化内存帧
    Frame* frames = (Frame*)malloc(frame_count * sizeof(Frame));
    for (int i = 0; i < frame_count; i++) {
        frames[i].page_number = -1;  // -1表示空帧
        frames[i].occupied = false;
    }
    
    // 初始化页面使用时间记录数组，记录每个页面最后被访问的时间
    int* page_last_used = (int*)malloc(MAX_PAGES * sizeof(int));
    for (int i = 0; i < MAX_PAGES; i++) {
        page_last_used[i] = -1;
    }
    
    int page_faults = 0;  // 缺页次数
    int current_time = 0; // 当前时间，用于记录页面访问时间
    
    printf("\n页面引用串: ");
    for (int i = 0; i < reference_length; i++) {
        printf("%d ", reference_string[i]);
    }
    printf("\n\n");
    
    // 处理每个页面引用
    for (int i = 0; i < reference_length; i++) {
        int current_page = reference_string[i];
        current_time++;  // 时间递增
        page_last_used[current_page] = current_time;  // 更新页面最后使用时间
        
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
                // 根据LRU算法，找到最久未使用的页面进行置换
                
                // 寻找内存中最早被访问的页面（LRU页面）
                int lru_page_index = 0;
                int earliest_time = page_last_used[frames[0].page_number];
                
                for (int j = 1; j < frame_count; j++) {
                    // 如果当前页面的最后访问时间更早，则更新LRU页面
                    if (page_last_used[frames[j].page_number] < earliest_time) {
                        earliest_time = page_last_used[frames[j].page_number];
                        lru_page_index = j;
                    }
                }
                
                // 置换页面
                frames[lru_page_index].page_number = current_page;
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
    free(page_last_used);
    return page_faults;
}