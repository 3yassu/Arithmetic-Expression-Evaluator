#include <iostream>
#include <vector>
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
    void addExpression(T x, BinaryNode<T> currentNode){
        int parenthCheck = 1
        int xLength = x.length()
        if(x[0] == '('){
            int j = 1;
            for(;(j < xLength) && (parenthCheck == 0); j++){
                if(x[j] == '('){
                    parenthCheck++;
                }
                else if(x[j] == ')'){
                    parenthCheck--;
                }
            }
            string left = x.substr(1, j);
            string right = x.substr(j + 3, xLength - 2);
            if(j < x.length() - 1){
                currentNode.entry = x[j + 1];
                currentNode.left->BinaryNode(left); addExpression(left, currentNode.left);
                currentNode.right->BinaryNode(right); addExpression(right, currentNode.right);
            }
            else{

            }
        }
        addExpression(x, i+1, currentNode.left);
    }
    float evaluator(T x){

    }
};