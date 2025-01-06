// ### 第2-3周：基础进阶
// - 函数基础
// - 数组和字符串
// - 指针基础
// - 引用
// - 命名空间
// - 基本输入输出

#include <iostream>
#include <string>
#include <array>

// 命名空间演示
namespace Math
{
    double PI = 3.14159;

    double square(double x)
    {
        return x * x;
    }
}

namespace Physics
{
    double PI = 3.141592653589793;

    // 函数重载示例
    double calculateEnergy(double mass)
    {
        return mass * 299792458.0 * 299792458.0; // E = mc²
    }

    double calculateEnergy(double mass, double height)
    {
        return mass * 9.81 * height; // E = mgh
    }
}

// 函数基础演示
void functionDemo()
{
    std::cout << "\n1. 函数演示\n";
    std::cout << "----------------\n";

    // 使用命名空间
    std::cout << "Math::PI = " << Math::PI << "\n";
    std::cout << "Physics::PI = " << Physics::PI << "\n";

    // 函数重载
    std::cout << "质量为2kg的物体的相对论能量: "
              << Physics::calculateEnergy(2.0) << " 焦耳\n";
    std::cout << "质量为2kg, 高度为10m的物体的势能: "
              << Physics::calculateEnergy(2.0, 10.0) << " 焦耳\n";
}

// 数组演示
void arrayDemo()
{
    std::cout << "\n2. 数组演示\n";
    std::cout << "----------------\n";

    // 基本数组
    int numbers[5] = {1, 2, 3, 4, 5};

    // C++ 11 标准数组
    std::array<int, 5> modernNumbers = {1, 2, 3, 4, 5};

    // 遍历数组
    std::cout << "传统数组遍历: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    std::cout << "现代数组遍历: ";
    for (const auto &num : modernNumbers)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // 字符串数组
    std::string fruits[] = {"apple", "banana", "orange"};
    std::cout << "水果数组: ";
    for (const auto &fruit : fruits)
    {
        std::cout << fruit << " ";
    }
    std::cout << "\n";
}

// 指针演示
void pointerDemo()
{
    std::cout << "\n3. 指针演示\n";
    std::cout << "----------------\n";

    int number = 42;
    int *ptr = &number;

    std::cout << "number的值: " << number << "\n";
    std::cout << "number的地址: " << ptr << "\n";
    std::cout << "通过指针访问number: " << *ptr << "\n";

    // 指针数组演示
    std::cout << "\n指针数组演示:\n";
    int a = 1, b = 2, c = 3;
    int *pointerArray[3] = {&a, &b, &c}; // 这是指针数组

    for (int i = 0; i < 3; i++)
    {
        std::cout << "指针数组元素 " << i << " 指向的值: "
                  << *pointerArray[i] << "\n";
    }

    // 对比：动态数组（之前的代码）
    int *dynamicArray = new int[3]{1, 2, 3}; // 这是动态数组
    std::cout << "\n动态数组演示:\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "动态数组元素 " << i << ": "
                  << dynamicArray[i] << "\n";
    }

    // 记得释放内存
    delete[] dynamicArray;
}

// 引用演示
void referenceDemo()
{
    std::cout << "\n4. 引用演示\n";
    std::cout << "----------------\n";

    int original = 42;
    int &ref = original;

    std::cout << "原始值: " << original << "\n";
    std::cout << "引用值: " << ref << "\n";

    ref = 100;
    std::cout << "通过引用修改后的原始值: " << original << "\n";
}

// 输入输出演示
void ioDemo()
{
    std::cout << "\n5. 输入输出演示\n";
    std::cout << "----------------\n";

    std::string name;
    int age;

    std::cout << "请输入您的名字: ";
    std::getline(std::cin, name);

    std::cout << "请输入您的年龄: ";
    std::cin >> age;

    std::cout << "你好, " << name << "! 你今年" << age << "岁。\n";
}

int main()
{
    std::cout << "C++ 基础进阶演示程序\n";
    std::cout << "=====================\n";

    functionDemo();  // 函数和命名空间演示
    arrayDemo();     // 数组演示
    pointerDemo();   // 指针演示
    referenceDemo(); // 引用演示
    ioDemo();        // 输入输出演示

    return 0;
}
