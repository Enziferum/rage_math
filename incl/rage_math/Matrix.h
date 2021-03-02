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

namespace rage{
    class Matrix {
    public:
        Matrix();
        Matrix(float x, float y, float z, float w,
               float x1, float y1, float z1, float w1,
               float x2, float y2, float z2, float w2,
               float x3, float y3, float z3, float w3);
        ~Matrix() = default;

        Matrix(const float& value);
        Matrix(const Matrix&);
        Matrix& operator=(const Matrix&);

        friend bool operator==(const Matrix&, const Matrix&);
        friend bool operator!=(const Matrix&, const Matrix&);

        Matrix operator*(const Matrix& r);
        Matrix transpose();

        const float* getPointer() const {
            return &(mat[0][0]);
        }
    public:
        float mat[4][4];
    };

    using mat4 = Matrix;
}
