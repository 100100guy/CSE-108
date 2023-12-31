#include <iostream>
#include <cstring>
using namespace std;

class Vector
{
    char *name;
    int x, y, z;

public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
        x = 0;
        y = 0;
        z = 0;
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
        x = a;
        y = b;
        z = c;
    }
    Vector(const Vector &obj)
    {
        int l = strlen(obj.name);
        this->name = new char[l + 1];
        strcpy(this->name, obj.name);
        this->x = obj.x;
        this->y = obj.y;
        this->z = obj.z;
    }

    int setX(int a) { x = a; }
    int setY(int b) { y = b; }
    int setZ(int c) { z = c; }

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l + 1];
        strcpy(name, n);
    }

    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }

    char *getName() { return name; }

    ~Vector()
    {
        delete[] name;
    }
    void print()
    {

        cout << this->name << ": ";
        cout << this->x;
        cout << "x";
        if (this->y < 0)
            cout << this->y << "y";
        else
            cout << "+" << this->y << "y";
        if (this->z < 0)
            cout << this->z << "z" << endl;
        else
            cout << "+" << this->z << "z" << endl;
    }
    int operator==(Vector &obj)
    {
        return (this->x == obj.x) && (this->y == obj.y) && (this->z == obj.z);
    }
    Vector operator*(Vector &obj)
    {
        Vector temp("tempvec");
        temp.x = this->x * obj.x;
        temp.y = this->y * obj.y;
        temp.z = this->z * obj.z;
        return temp;
    }
    Vector operator*(int n)
    {
        Vector temp("tempvec");
        temp.x = this->x * n;
        temp.y = this->y * n;
        temp.z = this->z * n;
        return temp;
    }
    Vector operator^(Vector &obj)
    {
        Vector temp("tempvec");
        temp.x = this->y * obj.z - this->z * obj.y;
        temp.y = this->z * obj.x - this->x * obj.z;
        temp.z = this->x * obj.y - this->y * obj.x;
        return temp;
    }
    Vector &operator=(const Vector &obj)
    {

        this->x = obj.x;
        this->y = obj.y;
        this->z = obj.z;
        return *this;
    }
    friend Vector operator*(int i, Vector &obj);
};
Vector operator*(int n, Vector &obj)
{
    Vector temp("");
    temp.x = obj.x * n;
    temp.y = obj.y * n;
    temp.z = obj.z * n;
    return temp;
}

int main()
{
    Vector v1("v1", 1, 2, 3), v2("v2", 4, 5, -6), v3("Result1"), v4("Result2", -27, 18, -3);

    v1.print(); /// Print the components of vector v1
    v2.print(); /// Print the components of vector v2

    v3 = v1 ^ v2; /// Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    v3.print();   /// Print the modified components of vector v3 (Name: Result1)

    if (v3 == v4) /// Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout << "Vectors are equal" << endl;
    else
        cout << "Vectors are not equal" << endl;

    v1 = v1 * 2; /// Multiply each component of vector v1 with the given value
    v1.print();  /// Print the modified components of vector v1

    v2 = 2 * v2; /// Multiply each component of vector v2 with the given value
    v2.print();  /// Print the modified components of vector v2

    v3 = v1 * v2; /// Multiply each component of vector v1 with the corresponding component of vector v2.
    v3.print();   /// Print the modified components of vector v3 (Name: Result1)

    if (v3 == v4) /// Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout << "Vectors are equal" << endl;
    else
        cout << "Vectors are not equal" << endl;

    return 0;
}
