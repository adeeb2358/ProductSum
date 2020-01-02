//
//  main.cpp
//  ProductSum
//
//  Created by adeeb mohammed on 02/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
/*
   this is a function to find the sum of elements in an array.
   The array is a special array which contains either numbers or arrays.
   Every sum has to be multiplied by the depth of the array
   eg [1,2,[3,4],5]
 so the sum calculation formula will be as follows
 1*(1+2+5+(2*(3+4)))
 
*/


#include <iostream>
#include <typeinfo>
#include <vector>
#include <any>


// the time complexity of the function is 0(n) n-> total number of the elements in the array
// including the subelements in the array
// the space complexity of this function is 0(d)  :-> total depth of the array
// here std::any is used this is same as the object type in java and dotnet
int productSum(std::vector<std::any> array, int dephtOfArray = 1){
    int resultSum = 0;
    for(auto object: array){
        if(object.type() == typeid(std::vector<std::any>)){
            resultSum += productSum(std::any_cast<std::vector<std::any> >(object),dephtOfArray+1);
        }else{
            resultSum += std::any_cast<int>(object);
        }
    }
    resultSum *= dephtOfArray;
    return resultSum;
}

int main(int argc, const char * argv[]) {
    std::cout<< "Program for finding the product sum of a special array"<< std::endl;
    std::vector<std::any> array ;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    std::vector<std::any> oneInnerArray;
    oneInnerArray.push_back(5);
    oneInnerArray.push_back(6);
    oneInnerArray.push_back(7);
    oneInnerArray.push_back(8);
    array.push_back(oneInnerArray);
    std::cout<< "productSum = "<< productSum(array);
    return 0;
}
