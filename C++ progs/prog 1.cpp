#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;   
        left++;
        right--;
    }
    return true;}
    bool toPalindrome(int n) {
    if (n < 0) return false;       
    int original = n;
    int reversed = 0;
    while (n > 0) {
        int digit = n % 10;         
        reversed = reversed * 10 + digit;
        n /= 10;                     
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
