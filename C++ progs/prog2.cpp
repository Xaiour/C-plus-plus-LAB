 #include <iostream>
void callByValue(int x) {
    x = x + 10;
    std::cout << "Inside call by value: x = " << x << "\n";
}
void callByReference(int &x) {
    x = x + 10;
    std::cout << "Inside call by reference: x = " << x << "\n";
}

int main() {
    int a, b;
    
    std::cout << "Enter a number: ";
    std::cin >> a;
    b = a;
    
    std::cout << "\nBefore call by value: a = " << a << "\n";
    callByValue(a);
    std::cout << "After call by value: a = " << a << "\n";
    
    std::cout << "\nBefore call by reference: b = " << b << "\n";
    callByReference(b); 
    std::cout << "After call by reference: b = " << b << "\n";
    
    return 0;
}
