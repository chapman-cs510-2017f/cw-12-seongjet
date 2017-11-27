#ifndef CW12_STACK_H_
#define CW12_STACK_H_

#include <memory>

// Define types as abstraction layer to protect against implementation changes
typedef int SValue;

// Printer for svalue - same as C implementation
void print(SValue);

// In C++ a class is just a fancy struct
// Both struct and class have two internal namespaces:
//    private: only accessible by the struct/class itself
//    public: accessible by other code that is using the struct/class
//
// When both private and public are explicitly declared, there is no
// difference between a class and a struct
//
// However, when neither private nor public are declared, then:
//    struct: defaults to public
//    class: defaults to private
//
// By convention (Google), use structs for static data, and use
// classes for everything else
//
// Notably, classes can include internal function definitions (like in Python)
// Internal functions of a class are called "methods"
//
// A class also always has a pointer to itself available, named "this"
// The keyword "this" serves a similar purpose to "self" in Python
// It allows you to access a specific "instance" of the class so that
// you can manipulate it within the definitions of your methods
//
// Recall that C++ automatically typedefs structs/classes
class Stack
{
// By convention, private and public declarations are not indented
private:
    // This structure type is private to the class, and used as a form of
    // linked list in order to contain the actual (static) data stored
    // by the Stack class
    struct Node {
        // An fixed type is used here - we will return to this later
        // for how to make the type flexible
        SValue data;
        // As with the C STACK, this type definition is recursive
        // Unlike C, we use a memory-safe "unique_ptr" to Node rather
        // than a straight (Node *), which has to be handled more carefully
        // http://www.cplusplus.com/reference/memory/unique_ptr/
        //
        // The funny syntax of <Node> indicates that the unique_ptr being
        // created will have the specific type (Node *) - this is an example
        // of a "parametrized type" for a "template", which we will return to
        //
        std::unique_ptr<Node> next;
        // Similarly, the default null pointer value "NULL" is replaced in 
        // C++11 by the keyword "nullptr" for safety, and will indicate an
        // empty Node in this case
    };

    // Private field of Stack class to specify its depth
    // Note the special type for storing sizes of objects
    // This is a safer version of an "unsigned int" used in C
    std::size_t depth;

    // Private pointer to the current head of the Stack
    std::unique_ptr<Node> head;

// Again, by convention this is not indented
public:
    // Public interface type specifications go here

    // Default constructor for class, equivalent of "new_stack" in the C version
    // Note lack of specified type : a class should have at least one constructor
    // Several constructors that take different arguments may be specified
    Stack();

    // Normally we would have to implement the following things in C++ here:
    //    1) Class Destructor : to deallocate memory when a Stack is deleted
    //       ~Stack();
    //
    //    2) Copy Constructor : to define what Stack b(a) does when a is a Stack
    //                          This should create a copy b of the Stack a, but
    //                          should be defined appropriately to do that
    //       Stack(const Stack&);
    //
    //    3) Copy Assignment  : to define what b = a does when a is a Stack
    //                          This should create a shallow copy of the outer
    //                          structure of a, but leave the inner structure as
    //                          pointers to the memory contained in a, and should
    //                          be defined appropriately to do that
    //       Stack& operator=(const Stack&);
    //
    // The need for defining ALL THREE of these things when managing memory for a
    // class explicitly is known as the "Rule of Three", and is standard
    //   http://stackoverflow.com/questions/4172722/what-is-the-rule-of-three
    //
    // However, by using the "unique_ptr" type above, we carefully avoid any
    // explicit memory allocation by using the allocation pre-defined inside the
    // unique_ptr itself. By using memory-safe structures in this way, we are using
    // the "Rule of Zero" and simplifying our life by defining ZERO of them:
    //   https://rmf.io/cxx11/rule-of-zero/
    //   http://www.cplusplus.com/reference/memory/unique_ptr/

    // Size method
    // Specifying const tells the compiler that the method will not change the
    // internal state of the instance of the class
    std::size_t size() const;

    // Push method
    void push(SValue);

    // Pop method
    SValue pop();

    // Empty check method
    // Observe that C++ now has a true Boolean type with keywords 
    // "true" and "false" (equivalent to ints 1 and 0, which is opposite
    // to the C convention, where 0 is true and anything else is false)
    bool empty() const;
    
    // Full check method
    bool full() const;

    // Print method
    void print() const;
};

#endif // CW12_STACK_H_
