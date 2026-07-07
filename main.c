#include "page_replacement.h"
#include <time.h>
#include <Windows.h>

// 定义是否使用中文界面
#define CHINESE_INTERFACE

int main() {
    // 设置控制台代码页为UTF-8
    UINT oldCodePage = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    
    int choice;
    int reference_string[MAX_PAGES];
    int reference_length;
    int frame_count;
    
#ifdef CHINESE_INTERFACE
    printf("=== 页面置换算法演示程序 ===\n");
#else
    printf("=== Page Replacement Algorithm Demo ===\n");
#endif
    
    // 获取用户输入
#ifdef CHINESE_INTERFACE
    printf("请输入页面引用串的长度: ");
#else
    printf("Enter the length of page reference string: ");
#endif
    if (scanf("%d", &reference_length) != 1) {
#ifdef CHINESE_INTERFACE
        printf("错误: 页面引用串长度输入无效。\n");
#else
        printf("Error: Invalid input for reference string length.\n");
#endif
        SetConsoleOutputCP(oldCodePage); // 恢复原始代码页
        return 1;
    }
    
    if (reference_length <= 0 || reference_length > MAX_PAGES) {
#ifdef CHINESE_INTERFACE
        printf("错误: 页面引用串长度必须在1到%d之间\n", MAX_PAGES);
#else
        printf("Error: Reference string length must be between 1 and %d\n", MAX_PAGES);
#endif
        SetConsoleOutputCP(oldCodePage); // 恢复原始代码页
        return 1;
    }
    
#ifdef CHINESE_INTERFACE
    printf("请输入页面引用串（用空格分隔）: ");
#else
    printf("Enter the page reference string (separated by spaces): ");
#endif
    for (int i = 0; i < reference_length; i++) {
        if (scanf("%d", &reference_string[i]) != 1) {
#ifdef CHINESE_INTERFACE
            printf("错误: 页面引用串输入无效。\n");
#else
            printf("Error: Invalid input for page reference string.\n");
#endif
            SetConsoleOutputCP(oldCodePage); // 恢复原始代码页
            return 1;
        }
    }
    
#ifdef CHINESE_INTERFACE
    printf("请输入内存帧数: ");
#else
    printf("Enter the number of memory frames: ");
#endif
    if (scanf("%d", &frame_count) != 1) {
#ifdef CHINESE_INTERFACE
        printf("错误: 内存帧数输入无效。\n");
#else
        printf("Error: Invalid input for frame count.\n");
#endif
        SetConsoleOutputCP(oldCodePage); // 恢复原始代码页
        return 1;
    }
    
    if (frame_count <= 0 || frame_count > MAX_FRAMES) {
#ifdef CHINESE_INTERFACE
        printf("错误: 内存帧数必须在1到%d之间\n", MAX_FRAMES);
#else
        printf("Error: Frame count must be between 1 and %d\n", MAX_FRAMES);
#endif
        SetConsoleOutputCP(oldCodePage); // 恢复原始代码页
        return 1;
    }
    
    do {
        print_menu();
#ifdef CHINESE_INTERFACE
        printf("请选择算法: ");
#else
        printf("Please select an algorithm: ");
#endif
        if (scanf("%d", &choice) != 1) {
#ifdef CHINESE_INTERFACE
            printf("错误: 输入无效。\n");
#else
            printf("Error: Invalid input.\n");
#endif
            while (getchar() != '\n'); // 清除输入缓冲区
            continue;
        }
        
        switch (choice) {
            case 1: {
#ifdef CHINESE_INTERFACE
                printf("\n=== FIFO算法 ===\n");
#else
                printf("\n=== FIFO Algorithm ===\n");
#endif
                int page_faults = fifo_algorithm(reference_string, reference_length, frame_count);
                double page_fault_rate = (double)page_faults / reference_length * 100;
#ifdef CHINESE_INTERFACE
                printf("缺页次数: %d\n", page_faults);
                printf("缺页率: %.2f%%\n", page_fault_rate);
#else
                printf("Page faults: %d\n", page_faults);
                printf("Page fault rate: %.2f%%\n", page_fault_rate);
#endif
                break;
            }
            case 2: {
#ifdef CHINESE_INTERFACE
                printf("\n=== LRU算法 ===\n");
#else
                printf("\n=== LRU Algorithm ===\n");
#endif
                int page_faults = lru_algorithm(reference_string, reference_length, frame_count);
                double page_fault_rate = (double)page_faults / reference_length * 100;
#ifdef CHINESE_INTERFACE
                printf("缺页次数: %d\n", page_faults);
                printf("缺页率: %.2f%%\n", page_fault_rate);
#else
                printf("Page faults: %d\n", page_faults);
                printf("Page fault rate: %.2f%%\n", page_fault_rate);
#endif
                break;
            }
            case 3: {
#ifdef CHINESE_INTERFACE
                printf("\n=== 比较两种算法 ===\n");
#else
                printf("\n=== Comparing Both Algorithms ===\n");
#endif
                
#ifdef CHINESE_INTERFACE
                printf("FIFO算法:\n");
#else
                printf("FIFO Algorithm:\n");
#endif
                int fifo_page_faults = fifo_algorithm(reference_string, reference_length, frame_count);
                double fifo_page_fault_rate = (double)fifo_page_faults / reference_length * 100;
#ifdef CHINESE_INTERFACE
                printf("缺页次数: %d\n", fifo_page_faults);
                printf("缺页率: %.2f%%\n\n", fifo_page_fault_rate);
#else
                printf("Page faults: %d\n", fifo_page_faults);
                printf("Page fault rate: %.2f%%\n\n", fifo_page_fault_rate);
#endif
                
#ifdef CHINESE_INTERFACE
                printf("LRU算法:\n");
#else
                printf("LRU Algorithm:\n");
#endif
                int lru_page_faults = lru_algorithm(reference_string, reference_length, frame_count);
                double lru_page_fault_rate = (double)lru_page_faults / reference_length * 100;
#ifdef CHINESE_INTERFACE
                printf("缺页次数: %d\n", lru_page_faults);
                printf("缺页率: %.2f%%\n\n", lru_page_fault_rate);
#else
                printf("Page faults: %d\n", lru_page_faults);
                printf("Page fault rate: %.2f%%\n\n", lru_page_fault_rate);
#endif
                
                if (fifo_page_faults < lru_page_faults) {
#ifdef CHINESE_INTERFACE
                    printf("结论: FIFO算法性能更好\n");
#else
                    printf("Conclusion: FIFO algorithm performs better\n");
#endif
                } else if (lru_page_faults < fifo_page_faults) {
#ifdef CHINESE_INTERFACE
                    printf("结论: LRU算法性能更好\n");
#else
                    printf("Conclusion: LRU algorithm performs better\n");
#endif
                } else {
#ifdef CHINESE_INTERFACE
                    printf("结论: 两种算法性能相同\n");
#else
                    printf("Conclusion: Both algorithms perform equally\n");
#endif
                }
                break;
            }
            case 0:
#ifdef CHINESE_INTERFACE
                printf("程序结束，谢谢使用！\n");
#else
                printf("Program terminated. Thank you!\n");
#endif
                break;
            default:
#ifdef CHINESE_INTERFACE
                printf("无效选择，请重新输入。\n");
#else
                printf("Invalid choice. Please try again.\n");
#endif
        }
    } while (choice != 0);
    
    // 恢复原始代码页
    SetConsoleOutputCP(oldCodePage);
    
    return 0;
}

void print_menu() {
    printf("\n========================\n");
#ifdef CHINESE_INTERFACE
    printf("1. FIFO算法\n");
    printf("2. LRU算法\n");
    printf("3. 比较两种算法\n");
    printf("0. 退出程序\n");
#else
    printf("1. FIFO Algorithm\n");
    printf("2. LRU Algorithm\n");
    printf("3. Compare Both Algorithms\n");
    printf("0. Exit Program\n");
#endif
    printf("========================\n");
}