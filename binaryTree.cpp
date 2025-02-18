#include <iostream>
#include <vector>
#include <string>
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
            T entry = currentNode->entry; int entrySize = entry.size();
            string equation {}; int parenthCheck = 0;
            string operand = {};
            for(int j = 0; j < entrySize; j++){
                char entryJ = entry[j];
                if(entryJ == '('){parenthCheck++;}
                else if(entryJ == ')'){parenthCheck--;}
                operand += entryJ;
                if(parenthCheck == 0 && j != (entrySize - 1)){equation += operand; operand = {};}
            }
            int equationSize = equation.size(); int prec = 0;
            for(int j = 0; j < equationSize; j++){
                if(isOperator(equation[j][0])){
                    if(precedence(equation[j][0]) == 1){
                        prec = j; break;
                    }else if(prec == 0 || precedence(equation[j][0]) < precedence(equation[prec][0])){
                        prec = j;
                    }
                }
            }
            string left = equation.substr(0, prec - 1);
            string right = equation.substr(prec + 1);
            currentNode->left = new BinaryNode<T>(left); sortExpression(currentNode->left);
            currentNode->right = new BinaryNode<T>(right); sortExpression(currentNode->right);
        }
        int precedence(char oper){
            if(oper == '^'){
                return 3;
            }else if(oper == '*' || oper == '/' || oper == '%'){
                return 2;
            }else if(oper == '+' || oper == '-'){
                return 1;
            }else{
                throw runtime_error("Not a valid operator!");
            }  
        }
        bool isOperator(char object){return (object == '+' || object == '-' || object == '*' || object == '/' || object == '^' || object == '%' );}
        float evaluator(BinaryNode<T>* currentNode){
            if(!(isOperator(currentNode->entry[0]))){
                return stof(currentNode->entry);
            }else{
                float left = evaluator(currentNode->left);
                float right = evaluator(currentNode->right);
                char oper = currentNode->entry[0];
                float power = 1;
                switch(oper){
                    case '+': return(left + right);
                    case '-': return(left - right);
                    case '*': return(left * right);
                    case '/': return(left / right);
                    case '^': for(int i = 0; i < right; ++i){power *= left;}return(power);
                    case '%': return(left % right);
                }
            }
        }
    public:
        string equation;
        BinaryExpressionTree(string x) : equation(x) {}
};