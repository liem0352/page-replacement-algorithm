@echo off
cls
echo =====================================================================
echo           页面置换算法演示程序 (Page Replacement Algorithms Demo)
echo =====================================================================
echo.
echo 本程序实现了两种经典的页面置换算法：
echo 1. FIFO (First In First Out) 先进先出算法
echo 2. LRU (Least Recently Used) 最近最久未使用算法
echo.
echo 程序功能：
echo - 模拟页面置换过程
echo - 显示每步的内存状态
echo - 计算缺页次数和缺页率
echo - 比较两种算法的性能
echo.
echo 使用方法：
echo 1. 双击运行 page_replacement.exe
echo 2. 按提示输入页面引用串和内存帧数
echo 3. 选择要演示的算法
echo.
echo 示例输入：
echo 页面引用串长度：7
echo 页面引用串：1 2 3 4 2 1 5
echo 内存帧数：3
echo.
echo 按任意键运行程序...
pause >nul
.\page_replacement.exe
echo.
echo 演示完成。
pause