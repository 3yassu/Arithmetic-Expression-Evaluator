#include <iostream>
#include <vector>
#include <regex>
using namespace std;

template <typename T>
class BinaryNode{
    public:
        T entry;
        BinaryNode* left;
        BinaryNode* right;
    BinaryNode(T x) : entry(x), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryExpressionTree{
    private:
        BinaryNode<T>* root;
    void sortExpression(BinaryNode<T> currentNode){
        T entry = currentNode.entry
        int parenthCheck = 1
        int entryLength = entry.length()
        
        std::regex patten(R"(.+[+-*^.])")
        currentNode.left->BinaryNode(left)
        currentNode.right->BinaryNode(right)
    }
    float evaluator(T x){

    }
};