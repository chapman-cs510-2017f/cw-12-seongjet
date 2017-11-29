#include <iostream>
#include "../src/stack/stack.h"

int main(void) {
    Stack s = Stack();
    SValue val;

    std::cout << "Putting items on the stack: 1,2,3" << std::endl;
    s.push(1);
    s.push(2);
    s.push(3);
    
    std::cout << "Popping items off the stack and printing:" << std::endl;
    val = s.pop();
    std::cout <<val<< std::endl;
    std::cout << std::endl;
    val = s.pop();
    std::cout <<val<< std::endl;
    std::cout << std::endl;
    val = s.pop();
    std::cout <<val<< std::endl;
    std::cout << std::endl;

   std::cout << "Popping an item from an empty stack and printing an error:" << std::endl;
   try {
      val = s.pop();
    std::cout <<val<< std::endl;
   } catch (const char* msg) {
     std::cerr << msg << std::endl;
   }
    std::cout << std::endl;
    

    
    
    std::cout << "Putting items on the stack: 4,5,6" << std::endl;
    s.push(4);
    s.push(5);
    s.push(6);
    std::cout << "Printing the stack:" << std::endl;
    s.print();
    return 0;
}
