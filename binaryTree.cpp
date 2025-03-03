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
        void sortExpression(BinaryNode<T>* currentNode){
        T entry = currentNode->entry; int unary = 0;
            if(isNum(entry)){return;}
            if(entry[0] == '+'){entry.erase(0, 1);}
            else if(entry[0] == '-'){entry.erase(0, 1); unary = 1;}
            vector<string> equation {}; int parenthCheck = 0; int entrySize = entry.size();
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
                if((j == entrySize - 1) || (parenthCheck == 0 && (isOperator(entry[j + 1]) || (isOperator(entryJ) && !isOperator(entry[j - 1]))))){equation.push_back(operand); operand.clear();}
            }
            if(unary == 1 && equation[1] != "^"){equation[0] = "(-1)*(" + equation[0] + ")";}
            else if(unary == 1 && equation[1] == "^"){equation.insert(equation.begin(), "*"); equation.insert(equation.begin(), "-1");}
            int equationSize = equation.size(); int prec = 0;
            if(equationSize == 1){
                currentNode->entry = equation[0];
                sortExpression(currentNode);
            }else{
                int precCheck = 0;
                for(int j = 0; j < equationSize; j++){
                    char currentEqu = equation[j][0]; char precedenceEqu = equation[prec][0];
                    if(equation[j].size() > 1 || !isOperator(currentEqu)){continue;}
                    else{
                        if(precCheck == 0){prec = j; precCheck++;}
                        else if(precedence(currentEqu) <= precedence(precedenceEqu)){prec = j;}
                    }
                }
                currentNode->entry = equation[prec];
                string left = ""; string right = ""; int lower = 0;
                for(int j = 0; j < equationSize; j++){
                    int jSize = equation[j].size(); 
                    if(jSize > 1 && !isNum(equation[j])){equation[j] = '(' + equation[j] + ')';}
                    if(j == prec){lower = 1;}
                    else if(lower == 0){left += equation[j];}
                    else if(lower == 1){right += equation[j];}
                }
                currentNode->left = new BinaryNode<T>(left); sortExpression(currentNode->left);
                currentNode->right = new BinaryNode<T>(right); sortExpression(currentNode->right);
            }
        }
        bool isNum(string numb){
            int decimalPoint = 0;
            if(numb[0] == '+' || numb[0] == '-'){
                int numbSize = numb.size();
                if(numbSize == 1){return false;}
                for(int i = 1; i < numbSize; i++){
                    if((!isdigit(numb[i]) && decimalPoint == 1) || isOperator(numb[i]) || numb[i] == '(' || numb[i] == ')'){return false;}
                    if(numb[i] == '.'){decimalPoint++;}
                }
            }else{
                for(char x : numb){
                    if((!isdigit(x) && decimalPoint == 1) || isOperator(x) || x == '(' || x == ')'){return false;}
                    else if(x == '.'){decimalPoint++;}
                }
            }
            return true;
        }
        int precedence(char oper){
            if(oper == '^'){
                return 4;
            }else if(oper == '*' || oper == '/' || oper == '%'){
                return 3;
            }else if(oper == '-'){
                return 2;
            }else if(oper == '+'){
                return 1;
            }else{
                return 5;
            }  
        }
        bool isOperator(char object){return (object == '+' || object == '-' || object == '*' || object == '/' || object == '^' || object == '%' );}
        float evaluator(BinaryNode<T>* currentNode){
            if(isNum(currentNode->entry)){
                return stof(currentNode->entry);
            }else{
                float left = evaluator(currentNode->left);
                float right = evaluator(currentNode->right);
                char oper = currentNode->entry[0];
                switch(oper){
                    case '+': return(left + right);
                    case '-': return(left - right);
                    case '*': return(left * right);
                    case '/': return(left / right);
                    case '^': return(pow(left, right));
                    case '%': 
                        float divisor = left / right;
                        float mod = right*(divisor - int(divisor));
                        return(mod);
                }
            }
            return 0;
        }
    public:
        string equation;
        BinaryExpressionTree(string x) : equation(x) {root = new BinaryNode<T>(x); sortExpression(root);}
        float evaluate() {return evaluator(root);}
};