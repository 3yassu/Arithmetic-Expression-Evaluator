#include <iostream>
#include <vector>
#include <set>
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
    void sortExpression(BinaryNode<T>* currentNode){
        T entry = currentNode.entry;
        int parenthCheck = 1;
        int entryLength = entry.length();
        int j = 1;
        string left; string right;
        if(entry[0] == '('){
            for(;(j < entryLength) && (parenthCheck > 0); j++){
                if(entry[j] == '(') parenthCheck++;
                else if(entry[j] == ')')parenthCheck--;
            }
            left = entry.substr(1, j - 1);
            right = entry.substr(j + 2, entryLength - 2);  
            if(j < entryLength - 1){
                currentNode->entry = entry[j + 1];
                currentNode->left = new BinaryNode<T>(left); sortExpression(currentNode.left);
                currentNode->right = new BinaryNode<T>(right); sortExpression(currentNode.right);
            }
            else{
                currentNode.entry = entry.substr(1, j - 1); sortExpression(currentNode);
            }
        }else{
            set<char> operators {'+', '-', '*', '/', '^'};
            for(;j < entryLength; j++){
                if(operators.find(entry[j]) != operators.end() && j > 0){
                    left = entry.substr(0, j - 1);
                    right = entry.substr(j + 1);
                    currentNode->left = new BinaryNode<T>(left);
                    currentNode->right = new BinaryNode<T>(right);
                    currentNode->entry = entry[j];
                    break;
                }
            }
        }
    }
    
    float evaluator(BinaryNode<T>* currentNode){
        set<char> operators {'+', '-', '*', '/', '^'};
        if(operators.find(currentNode->entry) == operators.end()){
            return stof(currentNode->entry);
        }else{
            left = evaluator(currentNode->left);
            right = evaluator(currentNode->right);
            char oper = currentNode->entry[0];
            switch(oper){
                case('+'): return(left + right);
                case('-'): return(left - right);
                case('*'): return(left * right);
                case('/'): return(left / right);
                case('^'): for(int i = 0; int i < right;i++){left *= left}return(left);
            }
        }
    }
};