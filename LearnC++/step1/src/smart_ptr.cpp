#include <iostream>
#include <memory> // 智能指针
#include <vector> // 容器
#include <string>

// 1. 数据结构示例（使用智能指针）
struct Node
{
    int data;
    std::shared_ptr<Node> next;

    Node(int value) : data(value), next(nullptr) {}
};

struct TreeNode
{
    int data;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(int value) : data(value) {}
};

// 2. 多态性示例
class Animal
{
public:
    virtual void makeSound() = 0;
    virtual ~Animal() = default;
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

// 3. 共享资源示例（使用shared_ptr）
class Resource
{
public:
    int data;
    Resource(int d) : data(d)
    {
        std::cout << "Resource created with data: " << data << std::endl;
    }
    ~Resource()
    {
        std::cout << "Resource destroyed with data: " << data << std::endl;
    }
};

class ResourceUser
{
private:
    std::shared_ptr<Resource> res;

public:
    ResourceUser(const std::shared_ptr<Resource> &r) : res(r) {}
    void useResource()
    {
        std::cout << "使用资源，数据为: " << res->data
                  << " (引用计数: " << res.use_count() << ")" << std::endl;
    }
};

// 4. 通过引用修改值（替代指针参数）
void modifyValue(int &value)
{
    value = 100;
}

// 5. 链表操作示例（使用智能指针）
void appendNode(std::shared_ptr<Node> &head, int value)
{
    auto current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = std::make_shared<Node>(value);
}

int main()
{
    std::cout << "现代 C++ 智能指针演示\n";
    std::cout << "====================\n\n";

    // 1. 智能指针内存管理演示
    std::cout << "1. 智能指针内存管理\n";
    std::cout << "-------------------\n";
    auto singleInt = std::make_unique<int>(42);
    std::vector<int> modernArray = {1, 2, 3, 4, 5}; // 使用vector替代原始数组

    std::cout << "单个整数值: " << *singleInt << std::endl;
    std::cout << "vector内容: ";
    for (const auto &num : modernArray)
    {
        std::cout << num << " ";
    }
    std::cout << "\n\n";

    // 2. 数据结构演示
    std::cout << "2. 数据结构（智能指针链表）\n";
    std::cout << "---------------------------\n";
    auto head = std::make_shared<Node>(1);
    appendNode(head, 2);
    appendNode(head, 3);

    std::cout << "链表内容: ";
    auto current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n\n";

    // 3. 多态性演示（使用智能指针）
    std::cout << "3. 多态性（使用智能指针）\n";
    std::cout << "-------------------------\n";
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    std::cout << "动物叫声: \n";
    for (const auto &animal : animals)
    {
        animal->makeSound();
    }
    std::cout << "\n";

    // 4. 共享资源演示（使用shared_ptr）
    std::cout << "4. 共享资源（使用shared_ptr）\n";
    std::cout << "----------------------------\n";
    auto sharedResource = std::make_shared<Resource>(42);
    ResourceUser user1(sharedResource);
    ResourceUser user2(sharedResource);

    user1.useResource();
    user2.useResource();
    std::cout << "\n";

    // 5. 引用代替指针
    std::cout << "5. 使用引用代替指针\n";
    std::cout << "-------------------\n";
    int number = 42;
    std::cout << "原始值: " << number << std::endl;
    modifyValue(number);
    std::cout << "修改后: " << number << std::endl;
    std::cout << "\n";

    // 6. 安全的字符串处理（使用string代替char*）
    std::cout << "6. 现代字符串处理\n";
    std::cout << "-----------------\n";
    std::string message = "Hello, Modern C++!";
    std::string copy = message;
    std::cout << "字符串内容: " << copy << std::endl;

    // 智能指针会自动清理内存，不需要手动删除
    return 0;
}
