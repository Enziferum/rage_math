/*********************************************************************
(c) Alex Raag 2021
https://github.com/Enziferum
rage_math - Zlib license.
This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.
2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#pragma once

#include <math.h>

namespace rage{
    template<typename T>
    struct Vector3{
        Vector3();
        Vector3(const T& value);
        Vector3(const T& x1, const T&y1, const T& z1);
        ~Vector3() = default;

        Vector3(const Vector3& other);
        Vector3& operator=(const Vector3& other);
        Vector3& operator+= (const Vector3& other);
        Vector3& operator-= (const Vector3& other);
        Vector3 operator* (const T& value);

        friend Vector3 operator+ (Vector3 l, const Vector3& r){
            l += r;
            return l;
        }

        friend Vector3 operator- (Vector3 l, const Vector3& r){
            l -= r;
            return l;
        }

        T x;
        T y;
        T z;
    };

    using vec3 = Vector3<float>;
    using vec3d = Vector3<double>;
    using vec3i = Vector3<int>;

    template<typename T>
    Vector3<T>::Vector3(): x(0),
                           y(0), z(0)
    {}

    template<typename T>
    Vector3<T>::Vector3(const T& value):
            x(value), y(value), z(value)
    {}

    template<typename T>
    Vector3<T>::Vector3(const T& x1, const T& y1,const T& z1):x(x1), y(y1), z(z1)
    {}

    template<typename T>
    bool operator==(const Vector3<T>& lhs, const Vector3<T>& rhs){
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
    }

    template<typename T>
    bool operator!=(const Vector3<T>& lhs, const Vector3<T>& rhs){
        return !(lhs == rhs);
    }

    template<typename T>
    Vector3<T>::Vector3(const Vector3& other):
            x(other.x), y(other.y), z(other.z){
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator=(const Vector3<T> &other) {
        if(*this == other)
            return *this;

        x = other.x;
        y = other.y;
        z = other.z;

        return *this;
    }

    template<typename T>
    Vector3<T> Vector3<T>::operator*(const T& value) {
        return Vector3<T>(x * value, y * value, z * value);
    }

    template<typename T>
    Vector3<T>& Vector3<T>::operator+=(const Vector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    template<typename T>
    Vector3<T> &Vector3<T>::operator-=(const Vector3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    template<typename T>
    Vector3<T> normalize(const Vector3<T>& t) {
        Vector3<T> res;
        float inv_length =
                1.f / sqrt(t.x * t.x + t.y * t.y + t.z * t.z);
        res.x = t.x * inv_length;
        res.y = t.y * inv_length;
        res.z = t.z * inv_length;
        return res;
    }

    template<typename T>
    Vector3<T> cross(const Vector3<T>& lhs, const Vector3<T>& rhs) {
        Vector3<T> res;
        res.x = lhs.y * rhs.z - lhs.z * rhs.y;
        res.y = lhs.z * rhs.x - lhs.x * rhs.z;
        res.z = lhs.x * rhs.y - lhs.y * rhs.x;
        return res;
    }
}
