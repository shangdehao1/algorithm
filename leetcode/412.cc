/*
 * 
 * Write a program that outputs the string representation of numbers from 1 to n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. 
 * 
 * For numbers which are multiples of both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 *     "1",
 *     "2",
 *     "Fizz",
 *     "4",
 *     "Buzz",
 *     "Fizz",
 *     "7",
 *     "8",
 *     "Fizz",
 *     "Buzz",
 *     "11",
 *     "Fizz",
 *     "13",
 *     "14",
 *     "FizzBuzz"
 * ]
 * 
 * 
 */

#include <sstream>


vector<string> fizzBuzz(int n) {
        
    auto int_to_string = [](int index) {
        if((index % 3 == 0) && (index % 5 != 0)) {
            return string("Fizz");
        } else if((index % 3 != 0) && (index % 5 == 0)) {
            return string("Buzz");
        } else if((index % 3 == 0) && (index % 5 == 0)){
            return string("FizzBuzz");
        } else {
            stringstream temp;
            (temp<<index);
            return temp.str();
        }
     };

    vector<string> results;
    for(int i = 1; i <= n; i++) {
        results.push_back(int_to_string(i));
    }
    return results;
}


vector<string> fizzBuzz(int n) {
    vector<string> results(n);

    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0) {
            results[i-1] += "Fizz";
        }
        if(i % 5 == 0) {
            results[i-1] += "Buzz";
        }
        if(results[i-1].empty()) {
            results[i-1] += to_string(i);
        }        
    }
    return results;
}










