@echo off
chcp 65001 >nul
echo ========================
echo 页面置换算法演示程序测试
echo ========================
echo.

echo 正在运行页面置换算法演示程序...
echo.

echo 7 | page_replacement.exe
echo 1 2 3 4 2 1 5
echo 3
echo 1
echo 0

echo.
echo 测试完成！
pause