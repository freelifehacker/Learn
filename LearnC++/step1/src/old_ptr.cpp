#include <iostream>
#include <cstring>

// 1. 数据结构示例
struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// 2. 多态性示例
class Animal
{
public:
    virtual void makeSound() = 0;
    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Meow!\n";
    }
};

// 3. 共享资源示例
class Resource
{
public:
    int data;
    Resource(int d) : data(d) {}
};

class ResourceUser
{
private:
    Resource *res;

public:
    ResourceUser(Resource *r) : res(r) {}
    void useResource()
    {
        std::cout << "使用资源，数据为: " << res->data << std::endl;
    }
};

// 4. 通过指针修改值的函数示例
void modifyValue(int *ptr)
{
    *ptr = 100;
}

// 5. 链表操作示例
void appendNode(Node *head, int value)
{
    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Node(value);
}

// 主函数，演示各种指针用法
int main()
{
    std::cout << "C++ 指针综合演示\n";
    std::cout << "================\n\n";

    // 1. 动态内存分配演示
    std::cout << "1. 动态内存分配\n";
    std::cout << "---------------\n";
    int *singleInt = new int(42);
    int *intArray = new int[5]{1, 2, 3, 4, 5};

    std::cout << "单个整数值: " << *singleInt << std::endl;
    std::cout << "数组内容: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << "\n\n";

    // 2. 数据结构演示
    std::cout << "2. 数据结构（链表）\n";
    std::cout << "-------------------\n";
    Node *head = new Node(1);
    appendNode(head, 2);
    appendNode(head, 3);

    std::cout << "链表内容: ";
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n\n";

    // 3. 多态性演示
    std::cout << "3. 多态性\n";
    std::cout << "----------\n";
    Animal *animals[2];
    animals[0] = new Dog();
    animals[1] = new Cat();

    std::cout << "动物叫声: \n";
    for (int i = 0; i < 2; i++)
    {
        animals[i]->makeSound();
    }
    std::cout << "\n";

    // 4. 共享资源演示
    std::cout << "4. 共享资源\n";
    std::cout << "------------\n";
    Resource *sharedResource = new Resource(42);
    ResourceUser user1(sharedResource);
    ResourceUser user2(sharedResource);

    user1.useResource();
    user2.useResource();
    std::cout << "\n";

    // 5. 指针修改值演示
    std::cout << "5. 通过指针修改值\n";
    std::cout << "-----------------\n";
    int number = 42;
    std::cout << "原始值: " << number << std::endl;
    modifyValue(&number);
    std::cout << "修改后: " << number << std::endl;
    std::cout << "\n";

    // 6. 底层内存操作演示
    std::cout << "6. 底层内存操作\n";
    std::cout << "---------------\n";
    char *buffer = new char[64];
    const char *message = "Hello, Memory!";
    std::memcpy(buffer, message, strlen(message) + 1);
    std::cout << "复制的内存内容: " << buffer << std::endl;

    // 清理内存
    delete singleInt;
    delete[] intArray;

    // 清理链表
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // 清理动物对象
    for (int i = 0; i < 2; i++)
    {
        delete animals[i];
    }

    delete sharedResource;
    delete[] buffer;

    return 0;
}
