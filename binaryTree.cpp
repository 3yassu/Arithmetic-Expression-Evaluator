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
            vector<string> equation {}; int parenthCheck = 0;
            string operand = "";
            for(int j = 0; j < entrySize; j++){
                char entryJ = entry[j];
                if(entryJ == '('){
                    if(parenthCheck != 0){operand += entryJ;}
                    parenthCheck++;
                }
                else if(entryJ == ')'){
                    if(parenthCheck != 1){operand += entryJ;}
                    parenthCheck--;
                }else{operand += entryJ;}
                if(parenthCheck == 0){equation.push_back(operand); operand.clear();}
            }
            
            int equationSize = equation.size(); int prec = 0;
            for(int j = 0; j < equationSize; j++){
                char currentEqu = equation[j][0]; char precedenceEqu = equation[prec][0];
                if(isOperator(currentEqu)){
                    if(precedence(currentEqu) == 1){
                        prec = j; break;
                    }else if(precedence(currentEqu) < precedence(precedenceEqu)){
                        prec = j;
                    }
                }
            }
            currentNode->entry = equation[prec];
            string left = ""; string right = ""; int lower = 0;
            for(int j = 0; j < equationSize; j++){
                if(j == prec){lower = 1;}
                else if(lower == 0){left += equation[j];}
                else if(lower == 1){right += equation[j];}
            }
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
            return 0;
        }
    public:
        string equation;
        BinaryExpressionTree(string x) : equation(x) {root = new BinaryNode<T>(x); sortExpression(root);}
        float evaluate() {return evaluator(root);}
};