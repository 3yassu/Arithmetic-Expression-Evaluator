#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
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
        void sortExpression(BinaryNode<T>* currentNode);
        bool isNum(string numb);
        int precedence(char oper);
        bool isOperator(char object);
        float evaluator(BinaryNode<T>* currentNode);
    public:
        string equation;
        BinaryExpressionTree(string x);
        float evaluate();
};
#endif

