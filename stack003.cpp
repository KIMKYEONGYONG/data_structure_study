#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string; using std::cin;
using std::equal; using std::remove;

string checkPalindrome(string& s) {
    string tmp = s;

    if (equal(tmp.begin(), tmp.begin() + tmp.size()/2, tmp.rbegin())) {
        return s + " is a palindrome";
    } else {
        return s + " is not a palindrome";
    }
}

int main(){
    string s1 = "radar";
    string s2 = "Was it a cat I saw";
    cout << checkPalindrome(s1)<< endl;
	  cout << checkPalindrome(s2)<< endl;
    return EXIT_SUCCESS;
}