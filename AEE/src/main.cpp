#include "binaryTree.hpp"

int main(){
    string equation;
    while(true){
        cout << "Enter Arithmetic Equation ('E' for exit): ";
        cin >> equation;
        if(equation[0] == 'E'){
            break;
        }
        BinaryExpressionTree<string> expressionTree(equation);
        double answer = expressionTree.evaluate();
        cout << "Result: " << answer << endl << endl; 
    }
    return 0;
}