#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string; using std::cin;
using std::equal; using std::remove;

int main(){
    string s1 = "radar";
    string s2 = "Was it a cat I saw";

    equal(s1.begin(), s1.begin() + s1.size()/2, s1.rbegin()) ?
        cout << "s1 is a palindrome" << endl :
        cout << "s1 is not a palindrome" << endl;

    equal(s2.begin(), s2.begin() + s2.size()/2, s2.rbegin()) ?
        cout << "s2 is a palindrome" << endl :
        cout << "s2 is not a palindrome" << endl;

    return EXIT_SUCCESS;
}