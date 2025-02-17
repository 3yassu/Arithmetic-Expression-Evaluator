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
    void sortExpression(BinaryNode<T> currentNode){
    }
    float evaluator(BinaryNode<T>* currentNode){
        set<char> operators {'+', '-', '*', '/', '^'};
        if(operators.find(currentNode->entry) == operators.end()){
            return stof(currentNode->entry);
        }else{
            float left = evaluator(currentNode->left);
            float right = evaluator(currentNode->right);
            char oper = currentNode->entry[0];
            float power = 1;
            switch(oper){
                case('+'): return(left + right);
                case('-'): return(left - right);
                case('*'): return(left * right);
                case('/'): return(left / right);
                case('^'): for(int i = 0; i < right; ++i){power *= left;}return(power);
            }
        }
    }
};