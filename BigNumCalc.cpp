#include "BigNumCalc.h"

using namespace std;

list<int> BigNumCalc :: buildBigNum(string numString){
    list<int> bigNum;
    for (char c: numString) {
        int a = c - '0';
        bigNum.push_back(a);
    }
    return bigNum;
}

list<int> BigNumCalc :: add(list<int> num1, list<int> num2){
    auto currentNum1 = prev(num1.end());
    auto currentNum2 = prev(num2.end());
    list<int> result;
    int carry = 0;
    while(currentNum1 != num1.begin() && currentNum2 != num2.begin()){
        int currentResult =  *currentNum1 + *currentNum2 + carry;
        if(currentResult >= 10){
            carry = 1;
            int endNum = currentResult % 10;
            result.push_back(endNum);
        }
        else{
            carry = 0;
            result.push_back(currentResult);
        }
        currentNum1 = prev(currentNum1);
        currentNum2 = prev(currentNum2);
    }
    int beginNum = *currentNum1 + *currentNum2 + carry;
    if(beginNum >= 10){
        result.push_back(beginNum % 10);
        result.push_back(1);
    }  
    else{
        result.push_back(beginNum);
    }
    result.reverse();
    return result;
}

list<int> BigNumCalc :: sub(list<int> num1, list<int> num2){
    auto currentNum1 = prev(num1.end());
    auto currentNum2 = prev(num2.end());
    list<int> result;
    int carry = 0;
    while(currentNum1 != num1.begin() && currentNum2 != num2.begin()){
        int currentResult =  *currentNum1 - *currentNum2 - carry;
        if(currentResult < 0){
            carry = 1;
            int endNum = currentResult + 10;
            result.push_back(endNum);
        }
        else{
            carry = 0;
            result.push_back(currentResult);
        }
        currentNum1 = prev(currentNum1);
        currentNum2 = prev(currentNum2);
    }
    int beginNum = *currentNum1 - *currentNum2 - carry;
    result.push_back(beginNum);
    result.reverse();
    list<int>::iterator it;
    for (it = result.begin(); it != result.end(); ++it){
        if(*it == 0){
            result.remove(*it);
        }
        else
        {
          break;
        }
        
    }
    return result;
}

list<int> BigNumCalc :: mul(list<int> num1, list<int> num2){
    auto currentNum1 = prev(num1.end());
    auto currentNum2 = prev(num2.end());
    list<int> result;
    int carry = 0;
    while(currentNum1 != num1.begin()){
        int currentResult =  *currentNum1 * *currentNum2 + carry;
        if(currentResult >= 10){
            carry = currentResult / 10;
            int endNum = currentResult % 10;
            result.push_back(endNum);
        }
        else{
            carry = 0;
            result.push_back(currentResult);
        }
        currentNum1 = prev(currentNum1);
        currentNum2 = prev(currentNum2);
    }
    int beginNum = *currentNum1 * *currentNum2 + carry;
    if(beginNum >= 10){
        result.push_back(beginNum % 10);
        result.push_back(beginNum / 10);
    }  
    else{
        result.push_back(beginNum);
    }
    result.reverse();
    return result;
}