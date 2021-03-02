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

#include "rage_math/Math.h"

namespace rage{

    Matrix rotate(Matrix const& matrix, float const& angle, vec3& axis){
        Matrix mat;
        return mat;
    }

    Matrix scale(Matrix const& matrix, const vec3& to){
        Matrix mat(0.f);
        for(short it=0; it<4; ++it){
            mat.mat[0][it] = matrix.mat[it][0] * to.x;
            mat.mat[1][it] = matrix.mat[it][0] * to.y;
            mat.mat[2][it] = matrix.mat[it][0] * to.z;
            mat.mat[3][it] = matrix.mat[it][0];
        }
        mat = mat.transpose();
        return mat;
    }

    mat4 lookAt(const vec3 pos, const vec3 target, const vec3 up){
        vec3 zaxis = normalize(pos - target);
        vec3 xaxis = normalize(cross(normalize(up), zaxis));
        vec3 yaxis = cross(zaxis, xaxis);

        mat4 translation;
        translation.mat[0][3] = -pos.x;
        translation.mat[1][3] = -pos.y;
        translation.mat[2][3] = -pos.z;

        mat4 rotation;
        rotation.mat[0][0] = xaxis.x;
        rotation.mat[0][1] = xaxis.y;
        rotation.mat[0][2] = xaxis.z;
        rotation.mat[1][0] = yaxis.x;
        rotation.mat[1][1] = yaxis.y;
        rotation.mat[1][2] = yaxis.z;
        rotation.mat[2][0] = zaxis.x;
        rotation.mat[2][1] = zaxis.y;
        rotation.mat[2][2] = zaxis.z;

        return rotation * translation;
    }

    mat4 cross_matrix(const mat4& mat, const vec3& vec) {
        float vec4[4][1] = {
                {vec.x},
                {vec.y},
                {vec.z},
                {1.f}
        };

        float res[4][1];
        for(short it=0; it < 4; ++it){
            for(short ij=0; ij < 1; ++ij){
                res[it][ij] = 0;
                for(short ik = 0; ik < 4; ++ik) {
                    res[it][ij] += mat.mat[it][ik] * vec4[ik][ij];
                }
            }
        }

        return mat4();
    }

    Matrix translate(Matrix const& matrix, vec3 const& to){
        Matrix mat(matrix);

        float vec4[4][1] = {
                {to.x},
                {to.y},
                {to.z},
                {1.f}
        };

        float res[4][1];
        for(short it=0; it < 4; ++it){
            for(short ij=0; ij < 1; ++ij){
                res[it][ij] = 0;
                for(short ik = 0; ik < 4; ++ik) {
                    res[it][ij] += mat.mat[it][ik] * vec4[ik][ij];
                }
            }
        }

        mat.mat[0][3] = res[0][0];
        mat.mat[1][3] = res[1][0];
        mat.mat[2][3] = res[2][0];
        mat.mat[3][3] = res[3][0];

        mat = mat.transpose();
        return mat;
    }

    constexpr float radiansCoof = 3.141592f/180.0f;

    float to_radians(const float& degrees) {
        return degrees * radiansCoof;
    }

    mat4 projPerspective() {
        mat4 matrix;
        return matrix;
    }
}