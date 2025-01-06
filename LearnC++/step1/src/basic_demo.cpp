// ### 第1步：基础入门
// - 开发环境设置 ✓
// - C++ 程序结构
// - 变量和基本数据类型
// - 运算符
// - 控制流程（if-else, switch）
// - 循环（for, while, do-while）

#include <iostream>
#include <string>

// 演示函数声明
void showDataTypes();
void showOperators();
void showControlFlow(int number);
void showLoops();

int main()
{
    std::cout << "C++ 基础知识演示程序\n";
    std::cout << "=====================\n\n";

    // 1. 基本数据类型演示
    std::cout << "1. 基本数据类型演示:\n";
    std::cout << "--------------------\n";
    showDataTypes();
    std::cout << "\n";

    // 2. 运算符演示
    std::cout << "2. 运算符演示:\n";
    std::cout << "-------------\n";
    showOperators();
    std::cout << "\n";

    // 3. 控制流程演示
    std::cout << "3. 控制流程演示:\n";
    std::cout << "---------------\n";
    showControlFlow(75);
    std::cout << "\n";

    // 4. 循环演示
    std::cout << "4. 循环演示:\n";
    std::cout << "-----------\n";
    showLoops();

    return 0;
}

// 演示各种数据类型
void showDataTypes()
{
    // 整数类型
    int integer = 42;
    short shortNum = 32767;
    long longNum = 2147483647;

    // 浮点类型
    float floatNum = 3.14f;
    double doubleNum = 3.14159265359;

    // 字符类型
    char character = 'A';

    // 布尔类型
    bool boolean = true;

    // 字符串（C++ 标准库）
    std::string text = "Hello, C++!";

    // 补充的整数类型
    unsigned int unsignedInt = 4294967295U;
    long long longLongNum = 9223372036854775807LL;

    // 补充的字符类型
    wchar_t wideChar = L'世';
    char16_t utf16Char = u'世';
    char32_t utf32Char = U'世';

    // 补充的浮点类型
    long double longDouble = 3.14159265358979323846L;

    // 固定大小的整数类型
    int8_t i8 = 127;
    uint8_t ui8 = 255;
    int16_t i16 = 32767;
    uint16_t ui16 = 65535;

    // 输出各种数据类型的值和大小
    std::cout << "整数 (int): " << integer << " [大小: " << sizeof(integer) << " 字节]\n";
    std::cout << "短整数 (short): " << shortNum << " [大小: " << sizeof(shortNum) << " 字节]\n";
    std::cout << "长整数 (long): " << longNum << " [大小: " << sizeof(longNum) << " 字节]\n";
    std::cout << "浮点数 (float): " << floatNum << " [大小: " << sizeof(floatNum) << " 字节]\n";
    std::cout << "双精度 (double): " << doubleNum << " [大小: " << sizeof(doubleNum) << " 字节]\n";
    std::cout << "字符 (char): " << character << " [大小: " << sizeof(character) << " 字节]\n";
    std::cout << "布尔值 (bool): " << boolean << " [大小: " << sizeof(boolean) << " 字节]\n";
    std::cout << "字符串 (string): " << text << "\n";
    std::cout << "无符号整数 (unsigned int): " << unsignedInt
              << " [大小: " << sizeof(unsignedInt) << " 字节]\n";
    std::cout << "长长整数 (long long): " << longLongNum
              << " [大小: " << sizeof(longLongNum) << " 字节]\n";
    std::cout << "长双精度 (long double): " << longDouble
              << " [大小: " << sizeof(longDouble) << " 字节]\n";
    std::cout << "宽字符 (wchar_t): " << static_cast<int>(wideChar)
              << " [大小: " << sizeof(wideChar) << " 字节]\n";
}

// 演示基本运算符
void showOperators()
{
    int a = 10, b = 3;

    // 算术运算符
    std::cout << "算术运算符:\n";
    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";
    std::cout << "a / b = " << (a / b) << "\n";
    std::cout << "a % b = " << (a % b) << "\n\n";

    // 比较运算符
    std::cout << "比较运算符:\n";
    std::cout << "a > b: " << (a > b) << "\n";
    std::cout << "a < b: " << (a < b) << "\n";
    std::cout << "a == b: " << (a == b) << "\n";
    std::cout << "a != b: " << (a != b) << "\n\n";

    // 逻辑运算符
    bool x = true, y = false;
    std::cout << "逻辑运算符:\n";
    std::cout << "x && y: " << (x && y) << "\n";
    std::cout << "x || y: " << (x || y) << "\n";
    std::cout << "!x: " << (!x) << "\n";
}

// 演示控制流程
void showControlFlow(int score)
{
    std::cout << "成绩评级系统 (分数: " << score << ")\n";

    // if-else 语句
    if (score >= 90)
    {
        std::cout << "优秀\n";
    }
    else if (score >= 80)
    {
        std::cout << "良好\n";
    }
    else if (score >= 60)
    {
        std::cout << "及格\n";
    }
    else
    {
        std::cout << "不及格\n";
    }

    // switch 语句
    std::cout << "\n按等级划分:\n";
    switch (score / 10)
    {
    case 10:
    case 9:
        std::cout << "等级: A\n";
        break;
    case 8:
        std::cout << "等级: B\n";
        break;
    case 7:
        std::cout << "等级: C\n";
        break;
    case 6:
        std::cout << "等级: D\n";
        break;
    default:
        std::cout << "等级: F\n";
    }
}

// 演示循环
void showLoops()
{
    // for 循环
    std::cout << "For 循环示例:\n";
    for (int i = 1; i <= 5; i++)
    {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    // while 循环
    std::cout << "While 循环示例:\n";
    int count = 5;
    while (count > 0)
    {
        std::cout << count << " ";
        count--;
    }
    std::cout << "\n\n";

    // do-while 循环
    std::cout << "Do-While 循环示例:\n";
    int num = 1;
    do
    {
        std::cout << num << " ";
        num *= 2;
    } while (num <= 16);
    std::cout << "\n";
}