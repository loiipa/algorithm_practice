#include <cmath>
#include <vector>
#include <iostream>
#include <functional>

class Node
{

public:
    Node(const int initValue)
    {
        value = initValue;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    Node(const int initValue, Node* const parentNode)
    {
        value = initValue;
        left = nullptr;
        right = nullptr;
        parent = parentNode;
    }

public:
    bool AddNode(const int targetValue)
    {
        if (left == nullptr && targetValue < value)
        {
            left = new Node(targetValue, this);
            return true;
        }

        if (right == nullptr && targetValue > value)
        {
            right = new Node(targetValue, this);
            return true;
        }

        if (left != nullptr && targetValue < value)
        {
            return left->AddNode(targetValue);
        }

        if (right != nullptr && targetValue > value)
        {
            return right->AddNode(targetValue);
        }

        return false;
    }

    Node* FindNode(const int targetValue)
    {
        if (value == targetValue)
            return this;

        if (left != nullptr && value > targetValue)
            return left->FindNode(targetValue);

        if (right != nullptr && value < targetValue)
            return right->FindNode(targetValue);
        
        return nullptr;
    }

    void GetAllValue(std::vector<int>& vecValue) const
    {
        if (left != nullptr)
            left->GetAllValue(vecValue);
        
            vecValue.emplace_back(value);
        
        if (right != nullptr)
            right->GetAllValue(vecValue);
    }

    Node* GetLeftNode() { return left; }
    Node* GetRightNode() { return right; }
    Node* GetParentNode() { return parent; }
    int GetValue() { return value; }

    void SetLeftNode(Node* left) { this->left = left; }
    void SetRightNode(Node* right) { this->right = right; }
    void SetParentNode(Node* parent) { this->parent = parent; }
    void SetValue(const int value) { this->value = value; }

private:
    int value;
    Node* left;
    Node* right;
    Node* parent;
};

class BinaryTree
{
public:
    BinaryTree()
    : rootNode(nullptr), numOfNode(0) {}

    virtual ~BinaryTree()
    {
        if (rootNode == nullptr)
        {
            // std::cout << "tree is null" << std::endl;
        }
        else
        {
            // std::cout << "delete ... ";
            DeleteAllNode(rootNode);
            // std::cout << std::endl;
        }
    }

    BinaryTree& operator=(const BinaryTree& other)
    {
        if (this == &other)
            return *this;

        // std::cout << "delete ... ";
        DeleteAllNode(rootNode);
        // std::cout << std::endl;

        // deep copy
        rootNode = CopyTree(other.rootNode, nullptr);
        numOfNode = other.numOfNode;

        return *this;
    }

public:
    bool AddNode(const int value)
    {
        if (rootNode == nullptr)
        {
            rootNode = new Node(value);
            ++numOfNode;
            return true;
        }

        bool isSuccess = rootNode->AddNode(value);

        if (isSuccess == true)
            ++numOfNode;

        return isSuccess;
    }
    
    bool DeleteNode(const int value)
    {
        if (rootNode == nullptr)
            return false;

        Node* node = rootNode->FindNode(value);
        if (node == nullptr)
            return false;

        if (node == rootNode && numOfNode == 1)
        {
            delete rootNode;
            rootNode = nullptr;
            numOfNode = 0;
            return true;
        }

        auto deleteNode = [this](Node* node, Node* parentNode, Node* leafNode)
        {
            // rootNode == node
            if (parentNode == nullptr)
            {
                rootNode = leafNode;
                rootNode->SetParentNode(nullptr);
            }
            else
            {
                if (parentNode->GetLeftNode() == node)
                    parentNode->SetLeftNode(leafNode);

                if (parentNode->GetRightNode() == node)
                    parentNode->SetRightNode(leafNode);

                leafNode->SetParentNode(parentNode);
            }

            delete node;
        };

        // 특정 node와 교체, 교체된 node를 삭제
        if (node->GetLeftNode() != nullptr && node->GetRightNode() != nullptr)
        {
            Node* deleteNode = node->GetLeftNode();
            Node* prevRightNode = deleteNode;

            while (deleteNode->GetRightNode() != nullptr)
            {
                prevRightNode = deleteNode;
                deleteNode = deleteNode->GetRightNode();
            }

            if (deleteNode == prevRightNode)
            {
                node->SetLeftNode(deleteNode->GetLeftNode());
                if (node->GetLeftNode() != nullptr)
                    node->GetLeftNode()->SetParentNode(node);
            }
            else
            {
                prevRightNode->SetRightNode(deleteNode->GetLeftNode());
                if (prevRightNode->GetRightNode() != nullptr)
                    prevRightNode->GetRightNode()->SetParentNode(prevRightNode);
            }

            // node value 교체
            node->SetValue(deleteNode->GetValue());

            delete deleteNode;
        }
        else if (node->GetLeftNode() != nullptr && node->GetRightNode() == nullptr)
        {
            Node* parentNode = node->GetParentNode();
            Node* leafNode = node->GetLeftNode();
            deleteNode(node, parentNode, leafNode);
        }
        else if (node->GetLeftNode() == nullptr && node->GetRightNode() != nullptr)
        {
            Node* parentNode = node->GetParentNode();
            Node* leafNode = node->GetRightNode();
            deleteNode(node, parentNode, leafNode);
        }
        else
        {
            Node* parentNode = node->GetParentNode();

            if (parentNode->GetLeftNode() == node)
                parentNode->SetLeftNode(nullptr);
            
            if (parentNode->GetRightNode() == node)
                parentNode->SetRightNode(nullptr);

            delete node;
        }

        --numOfNode;
        return true;
    }

    void DeleteAllNode(Node* node)
    {
        if (node == nullptr)
            return;
            
        DeleteAllNode(node->GetLeftNode());
        DeleteAllNode(node->GetRightNode());

        // std::cout << node->GetValue() << " ";
        delete node;
    }
    
    bool FindNode(const int value)
    {
        if (rootNode == nullptr)
            return false;

        return rootNode->FindNode(value) != nullptr;
    }

    int GetCountNode()
    {
        return numOfNode;
    }

    std::vector<int> GetValue()
    {
        if (rootNode == nullptr)
            return {};

        std::vector<int> vecValue;
        vecValue.reserve(numOfNode);
        rootNode->GetAllValue(vecValue);

        return vecValue;
    }

private:
    Node* CopyTree(Node* node, Node* newParent)
    {
        if (node == nullptr)
            return nullptr;

        Node* newNode = new Node(node->GetValue(), newParent);

        Node* leftNode = CopyTree(node->GetLeftNode(), newNode);
        newNode->SetLeftNode(leftNode);

        Node* rightNode = CopyTree(node->GetRightNode(), newNode);
        newNode->SetRightNode(rightNode);

        return newNode;
    }

private:
    Node* rootNode;
    int numOfNode;
};

class TreeTester
{

public:
    void TreeTesterOn()
    {
        std::cout << "Add:    add  [number]" << std::endl;
        std::cout << "Delete: del  [number]" << std::endl;
        std::cout << "Find:   find [number]" << std::endl;
        std::cout << "count:  count" << std::endl;
        std::cout << "get:    get" << std::endl;
        std::cout << "test:   test" << std::endl;
        std::cout << "Exit:   exit" << std::endl;

        while(true)
        {
            std::string inputOrder, inputNumber;
            std::cin >> inputOrder;
            if (inputOrder == "exit")
            {
                std::cout << "bye" << std::endl;
                return;
            }

            if (inputOrder == "count")
            {
                std::cout << tree.GetCountNode() << std::endl;
                continue;
            }

            if (inputOrder == "get")
            {
                std::vector<int> vecValue = tree.GetValue();

                std::cout << "[ ";
                for (const int& value : vecValue)
                {
                    std::cout << value << " ";
                }

                std::cout << "]" << std::endl;
                continue;
            }

            if (inputOrder == "test")
            {
                RunAutoTreeBasicTest();
                RunAutoTreeComplexTest();
                RunAutoTreeEdgeCaseTest();
                tree = BinaryTree();
                continue;
            }

            std::cin >> inputNumber;
    
            bool isSuccess = false;

            auto ExecuteCommand = [&](bool (BinaryTree::*func)(int))
            {
                int number = 0;
                try
                {
                    number = std::stoi(inputNumber);
                }
                catch (...)
                {
                    return;
                }

                isSuccess = (tree.*func)(number);
            };

            if (inputOrder == "add")
            {
                ExecuteCommand(&BinaryTree::AddNode);
            }

            if (inputOrder == "del")
            {
                ExecuteCommand(&BinaryTree::DeleteNode);
            }

            if (inputOrder == "find")
            {
                ExecuteCommand(&BinaryTree::FindNode);
            }

            if (isSuccess == true)
                std::cout << inputOrder << " success" << std::endl;
            else
                std::cout << inputOrder << " fail" << std::endl;
        }

    }

private:
    void RunAutoTreeBasicTest()
    {
        std::cout << "---------- Binary Tree Basic Test Start ----------" << std::endl;

        int testCase = 0;
        int successCase = 0;

        auto SetSuccessCaseNum = [&testCase, &successCase](bool isSuccess)
        {
            ++testCase;
            if (isSuccess == true)
                ++successCase;
        };

        // add & search
        {
            tree = BinaryTree();
            std::cout << "Test 1: Add and Search" << std::endl;

            tree.AddNode(50);
            tree.AddNode(25);
            tree.AddNode(75);

            bool isSuccess = tree.FindNode(25) && tree.FindNode(50) && tree.FindNode(75) && !tree.FindNode(0);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // 중위 순회 및 순서 확인
        {
            tree = BinaryTree();
            std::cout << "Test 2: inorder traverse" << std::endl;

            tree.AddNode(50);
            tree.AddNode(30);
            tree.AddNode(70);
            tree.AddNode(20);
            tree.AddNode(80);
            tree.AddNode(40);
            tree.AddNode(60);

            auto value = tree.GetValue();
            std::vector<int> expectedValue = {20, 30, 40, 50, 60, 70, 80};

            bool isSuccess = value == expectedValue;
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // 삭제 - leaf node - left
        {
            tree = BinaryTree();
            std::cout << "Test 3-1: Delete left leaf node" << std::endl;

            tree.AddNode(30);
            tree.AddNode(10);
            tree.AddNode(40);

            tree.DeleteNode(10);

            bool isSuccess = !tree.FindNode(10) && tree.FindNode(30) && tree.FindNode(40) && !tree.FindNode(0);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }


        // 삭제 - leaf node - right
        {
            tree = BinaryTree();
            std::cout << "Test 3-2: Delete leaf node" << std::endl;

            tree.AddNode(30);
            tree.AddNode(10);
            tree.AddNode(40);

            tree.DeleteNode(40);

            bool isSuccess = tree.FindNode(10) && tree.FindNode(30) && !tree.FindNode(40) && !tree.FindNode(0);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // 삭제 - root node
        {
            tree = BinaryTree();
            std::cout << "Test 3-3: Delete root node" << std::endl;

            tree.AddNode(30);
            tree.AddNode(10);
            tree.AddNode(40);

            tree.DeleteNode(30);

            bool isSuccess = tree.FindNode(10) && !tree.FindNode(30) && tree.FindNode(40) && !tree.FindNode(0);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // 삭제 - 삭제 대상 노드의 right 자식만 있는 경우
        {
            tree = BinaryTree();
            std::cout << "Test 3-4: Delete middle node (have right node)" << std::endl;

            tree.AddNode(10);
            tree.AddNode(20);
            tree.AddNode(30);

            tree.DeleteNode(20);
            bool isSuccess = tree.FindNode(10) && !tree.FindNode(20) && tree.FindNode(30) && !tree.FindNode(0);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // 삭제 - 삭제 대상 노드의 left 자식만 있는 경우
        {
            tree = BinaryTree();
            std::cout << "Test 3-5: Delete middle node (have left node)" << std::endl;

            tree.AddNode(30);
            tree.AddNode(20);
            tree.AddNode(10);

            tree.DeleteNode(20);
            bool isSuccess = tree.FindNode(10) && !tree.FindNode(20) && tree.FindNode(30) && !tree.FindNode(0);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // 삭제 - 삭제 대상 노드의 left, right 둘 다 있는 경우
        {
            tree = BinaryTree();
            std::cout << "Test 3-6: Delete middle node (have left and right node)" << std::endl;

            tree.AddNode(50);
            tree.AddNode(30);
            tree.AddNode(40);
            tree.AddNode(60);
            tree.AddNode(20);

            tree.DeleteNode(30);

            bool isSuccess = tree.FindNode(20) && !tree.FindNode(30) && tree.FindNode(40) && tree.FindNode(50) && tree.FindNode(60) &&!tree.FindNode(0);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        std::cout << "Test Result : [" << successCase << "/" << testCase << "]" << std::endl;
        std::cout << "---------- Binary Tree Basic Test End ----------\n" << std::endl;

    }

    void RunAutoTreeComplexTest()
    {
        std::cout << "---------- Binary Tree Complex Test Start ----------" << std::endl;

        int testCase = 0;
        int successCase = 0;

        auto SetSuccessCaseNum = [&testCase, &successCase](bool isSuccess)
        {
            ++testCase;
            if (isSuccess == true)
                ++successCase;
        };

        tree = BinaryTree();
        std::vector<int> value = {40, 20, 30, 25, 10, 60, 50, 55, 70, 65, 5, 45, 15, 35, 75};

        for (const auto& v : value)
        {
            tree.AddNode(v);
        }

        auto PrintValue = [](const auto& value)
        {
            std::cout << "[ ";
            for (const auto& v : value)
            {
                std::cout << v << " ";
            }
            std::cout << "]" << std::endl;
        };

        // same as value
        {
            std::cout << "Test 1: Same as Value" << std::endl;

            auto curTree = tree.GetValue();
            PrintValue(curTree);

            std::vector<int> value = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75};
            
            bool isSuccess = (curTree == value);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // delete some value
        {
            std::cout << "Test 2: delete some value" << std::endl;

            tree.DeleteNode(15);
            tree.DeleteNode(30);
            tree.DeleteNode(45);
            tree.DeleteNode(60);

            auto curTree = tree.GetValue();
            PrintValue(curTree);

            std::vector<int> value = {5, 10, 20, 25, 35, 40, 50, 55, 65, 70, 75};
            
            bool isSuccess = (curTree == value);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // add some value
        {
            std::cout << "Test 3: add some value" << std::endl;

            tree.AddNode(15);
            tree.AddNode(30);
            tree.AddNode(45);
            tree.AddNode(60);

            auto curTree = tree.GetValue();
            PrintValue(curTree);

            std::vector<int> value = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75};
            
            bool isSuccess = (curTree == value);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // delete roof node
        {
            std::cout << "Test 4: delete roof node" << std::endl;

            tree.DeleteNode(40);

            auto curTree = tree.GetValue();
            PrintValue(curTree);

            std::vector<int> value = {5, 10, 15, 20, 25, 30, 35, 45, 50, 55, 60, 65, 70, 75};
            
            bool isSuccess = (curTree == value);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        // delete all node
        {
            std::cout << "Test 5: delete all node" << std::endl;

            for (int num = 5; num < 80; num += 5)
            {
                tree.DeleteNode(num);
            }

            auto curTree = tree.GetValue();
            PrintValue(curTree);

            std::vector<int> value = {};
            
            bool isSuccess = (curTree == value);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        std::cout << "Test Result : [" << successCase << "/" << testCase << "]" << std::endl;
        std::cout << "---------- Binary Tree Complex Test End ----------\n" << std::endl;

    }

    void RunAutoTreeEdgeCaseTest()
    {
        std::cout << "---------- Binary Tree Edge Case Test Start ----------" << std::endl;

        int testCase = 0;
        int successCase = 0;

        auto SetSuccessCaseNum = [&testCase, &successCase](bool isSuccess)
        {
            ++testCase;
            if (isSuccess == true)
                ++successCase;
        };

        // 빈 트리 테스트
        {
            // std::cout << "Test 1: empty tree test" << std::endl;
            tree = BinaryTree();

            {
                std::cout << "Test 1-1: delete node" << std::endl;

                bool isSuccess = !tree.DeleteNode(0);
                std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
                SetSuccessCaseNum(isSuccess);
            }

            {
                std::cout << "Test 1-2: find node" << std::endl;

                bool isSuccess = !tree.FindNode(0);
                std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
                SetSuccessCaseNum(isSuccess);
            }

            {
                std::cout << "Test 1-3: count check" << std::endl;

                bool isSuccess = (tree.GetCountNode() == 0);
                std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
                SetSuccessCaseNum(isSuccess);
            }
        }

        // 중복 테스트
        {
            std::cout << "Test 2: duplicate test" << std::endl;
            tree = BinaryTree();

            tree.AddNode(50);

            bool isAdd = tree.AddNode(50);
            int countNode = tree.GetCountNode();

            bool isSuccess = (isAdd == false && countNode == 1);
            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }


        // 단일 노드 테스트
        {
            std::cout << "Test 3: only one node test" << std::endl;
            tree = BinaryTree();

            tree.AddNode(50);

            bool isDelete = tree.DeleteNode(50);
            bool countNode = tree.GetCountNode();

            bool isSuccess = (isDelete == true && countNode == 0);

            std::cout << (isSuccess ? "PASSED" : "FAILED" ) << "\n" << std::endl;
            SetSuccessCaseNum(isSuccess);
        }

        std::cout << "Test Result : [" << successCase << "/" << testCase << "]" << std::endl;
        std::cout << "---------- Binary Tree Edge Case Test End ----------\n" << std::endl;

    }

private:
    BinaryTree tree;
};

int main()
{
    TreeTester treeTester;
    treeTester.TreeTesterOn();
}
