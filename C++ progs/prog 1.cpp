#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;  // mismatch found
        left++;
        right--;
    }
    return true;}
    bool toPalindrome(int n) {
    if (n < 0) return false;       // negatives like -121 aren't palindromes
    int original = n;
    int reversed = 0;
    while (n > 0) {
        int digit = n % 10;        // last digit
        reversed = reversed * 10 + digit;
        n /= 10;                    // remove last digit
    }
    return original == reversed;
}
int main(){
    int n; string s;
    cout<<"enter the number to be palindrome"<< endl;
    cin>>n;
    cout <<"enter the string"<< endl;
    cin>>s;
    std::cout << std::boolalpha;
    cout<< isPalindrome(s)<<endl;
    cout<<toPalindrome(n)<<endl;
     return 0;

    

}