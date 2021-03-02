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

#include "rage_math/Matrix.h"

namespace rage{
    struct mat1{
        mat1(){
            mat[0][0] = 0.f;
            mat[1][0] = 0.f;
            mat[2][0] = 0.f;
            mat[3][0] = 0.f;
        }
        float mat [4][1];
    };

    Matrix::Matrix(){
        mat[0][0] = 1.f;mat[0][1] = 0.f;mat[0][2] = 0.f;mat[0][3] = 0.f;
        mat[1][0] = 0.f;mat[1][1] = 1.f;mat[1][2] = 0.f;mat[1][3] = 0.f;
        mat[2][0] = 0.f;mat[2][1] = 0.f;mat[2][2] = 1.f;mat[2][3] = 0.f;
        mat[3][0] = 0.f;mat[3][1] = 0.f;mat[3][2] = 0.f;mat[3][3] = 1.f;
    }

    Matrix::Matrix(float x, float y, float z, float w,
                   float x1, float y1, float z1, float w1,
                   float x2, float y2, float z2, float w2,
                   float x3, float y3, float z3, float w3){
        mat[0][0] = x;mat[0][1] = y;mat[0][2] = z;mat[0][3] = w;
        mat[1][0] = x1;mat[1][1] = y1;mat[1][2] = z1;mat[1][3] = w1;
        mat[2][0] = x2;mat[2][1] = y2;mat[2][2] = z2;mat[2][3] = w2;
        mat[3][0] = x3;mat[3][1] = y3;mat[3][2] = z3;mat[3][3] = w3;
    }

    Matrix::Matrix(const float& value) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mat[i][j] = value;
            }
        }
    }

    Matrix::Matrix(const Matrix& other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mat[i][j] = other.mat[i][j];
            }
        }

    }

    Matrix& Matrix::operator=(const Matrix& other) {
        if (other == *this)
            return *this;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mat[i][j] = other.mat[i][j];
            }
        }
        return *this;
    }

    bool operator==(const Matrix& lhs, const Matrix& rhs) {
        bool res = true;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                res *= lhs.mat[i][j] == rhs.mat[i][j];
            }
        }
        return res;
    }

    bool operator!=(const Matrix& lhs, const Matrix& rhs) {
        return !(lhs==rhs);
    }

    Matrix Matrix::operator*(const Matrix& r) {
        Matrix m(0.f);

        for(short it = 0; it < 4; ++it){
            for(short ij = 0; ij < 4; ++ij){
                m.mat[it][ij] = 0;
                for(short ik = 0; ik < 4; ++ik)
                    m.mat[it][ij] += mat[it][ik] * r.mat[ik][ij];
            }
        }

        return m;
    }

    mat4 Matrix::transpose() {
        mat4 matrix;
        for(int it=0; it < 4; ++it){
            for (int ij=0; ij < 4; ++ij){
                matrix.mat[ij][it] = mat[it][ij];
            }
        }
        return matrix;
    }
}