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
        int precedence(char oper){
            if(oper == '^'){
                return 3;
            }else if(oper == '*' || oper == '/' || oper == '%'){
                return 2;
            }else if(oper == '+' || oper == '-'){
                return 1;
            }else{
                throw runtime_error("Not a valid operator!")
            }  
        }
        bool isOperator(char object){return if(object == '+' || object == '-' || object == '*' || object == '/' || object == '^' || object == '%' );}
        float evaluator(BinaryNode<T>* currentNode){
            if(!(isOperator(currentNode->entry))){
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
                    case('%'): return(left % right);
                }
            }
        }
    public:
        string equation;
        BinaryExpressionTree(string x) : equation(x) {}
};