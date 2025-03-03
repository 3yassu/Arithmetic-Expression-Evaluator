#include "binaryTree.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string equation;
    cout << "Enter Arithmetic Equation: ";
    cin >> equation;
    BinaryExpressionTree<string> expressionTree(equation);
    float answer = expressionTree.evaluate();
    cout << "Result: " << answer << endl; 
    return 0;
}