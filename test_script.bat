@echo off
echo 测试页面置换算法程序
echo ========================
echo 创建测试输入文件...
echo 7 > input.txt
echo 1 2 3 4 2 1 5 >> input.txt
echo 3 >> input.txt
echo 1 >> input.txt

echo 运行测试...
type input.txt | .\page_replacement.exe

echo.
echo 测试完成
del input.txt
pause