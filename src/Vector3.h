#pragma once
#include <math.h>
template<typename T>
struct Vector3
{
    public:
    Vector3()               : x(0), y(0), z(0) {};
    Vector3(T x, T y, T z)  : x(x), y(y), z(z) {};
    ~Vector3() {};

    T x, y, z;
    //// Operators ////

    // copy operator
    Vector3& operator=(const Vector3& other)
    {
        return Vector3(x, y, z);
    }

    // addition
    Vector3 operator+(const Vector3& other)
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3& operator+=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    // scalar multiplication
    Vector3 operator*(T scalar)
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    };

    Vector3& operator*=(T scalar) 
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    };

    // dot product
    T operator*(Vector3& other)
    {
        return x * other.x + y * other.y + z * other.z;
    };

    // zero vector
    static const Vector3 zero();

    static Vector3 cross(Vector3& a, Vector3& b);

    T mag() const 
    {
        return sqrt(x*x + y*y + z*z);
    };

    T magSquared() const
    {
        return x*x + y*y + z*z;
    };

    Vector3 normalize() const;
};

template<typename T>
Vector3<T> const Vector3<T>::zero()
{
    return Vector3();
}

template<typename T>
Vector3<T> Vector3<T>::cross(Vector3& a, Vector3& b)
{
    T x = a.y * b.z - a.z * b.y;
    T y = a.z * b.x - a.x * b.z;
    T z = a.x * b.y - a.y * b.x;
    return Vector3(x, y, z);
}

template<typename T>
Vector3<T> Vector3<T>::normalize() const
{
    T m = mag();
    return Vector3(x / m, y / m, z / m);
}


// for convenience
typedef Vector3<float> vec3f;
typedef Vector3<double> vec3d;