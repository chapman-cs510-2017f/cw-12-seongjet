#include <iostream>
#include "structs.h"

using namespace std;

int main(void)
{
    // The default constructor for a struct just zeroes the values
    Vec3 v = Vec3();
    Vec3 vprime = Vec3();
    Vec2 w = Vec2();
    Vec2 w2 = Vec2();
    Vec3 v3 = Vec3();
    
    cout << "-----Pass by value test-----" << endl;
    cout << "Original 3 vector:" << endl;
    print_vec(v);
    vprime = set_vec(v, 1.0, 2.0, 3.0);
    cout << "Original 3 vector after modification:" << endl;
    print_vec(v);
    cout << "New 3 vector after modification:" << endl;
    print_vec(vprime);
    
    cout << "-----Pass by reference test-----" << endl;
    cout << "Original 2 vector:" << endl;
    print_vec(w);
    set_vec(w, 1.0, 2.0);
    cout << "Original 2 vector after modification:" << endl;
    print_vec(w);

    
    cout << "-----Testing Operator Overloading  Vec2-----" << endl;
    set_vec(w2, 3.0, 4.0);
    print_vec(w2);
    Vec2 sum = w2 + w;
    print_vec(sum);
       
    cout << "-----Testing Operator Overloading Vec3-----" << endl;
    v3 = set_vec(v3, 3.0, 4.0, 5.0);
    print_vec(v3);
    Vec3 sumVec3 = v3 + vprime;
    print_vec(sumVec3);
       

    return 0;
}

Vec3 set_vec(Vec3 v, Component x, Component y, Component z)
{
    // Local value v is a copy of the original v
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

void set_vec(Vec2 &wr, Component x, Component y)
{
    // Local reference wr refers directly to original memory location
    wr.x = x;
    wr.y = y;
}

void print_vec(const Vec3 v)
{
    cout << "3-Vector : [" << v.x << ", " << v.y << ", " << v.z << "]" << endl;
}

void print_vec(const Vec2 &wr)
{
    // Passing in a reference wr prevents unnecessary memory copying
    cout << "2Vector : [" << wr.x << ", " << wr.y << "]" << endl;
}

//TODO : Implement overloaded + operators
Vec3 operator+(const Vec3 &c1, const Vec3 &c2) {
    Vec3 sum;
    sum.x = c1.x + c2.x;
    sum.y = c1.y + c2.y;
    sum.z = c1.z + c2.z;
    return sum;
};

Vec2 operator+(const Vec2 &c1, const Vec2 &c2) {
    Vec2 sum;
    sum.x = c1.x + c2.x;
    sum.y = c1.y + c2.y;
    return sum;
};
