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

#include "Matrix.h"
#include "Vector3.h"

namespace rage{
    mat4 translate(Matrix const& matrix, vec3 const& to);
    mat4 rotate(Matrix const& matrix, float const& angle, vec3& axis);
    mat4 scale(Matrix const& matrix, const vec3& size);

    mat4 projPerspective();
    mat4 lookAt(const vec3 pos, const vec3 target, const vec3 up);
    mat4 cross_matrix(const mat4& mat, const vec3& vec);

    float to_radians(const float& degrees);
}
