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

#include "gtest/gtest.h"
#include "rage_math/Math.h"

using namespace rage;

TEST(Math, Translate){
    mat4 matrix;
    matrix = translate(matrix, vec3(1.f, 2.f, 3.f));
}

TEST(Math, rotate){
    mat4 matrix;
    const float angle = 45.f;
    //matrix = rotate(matrix, 45.f, vec3(1.f, 2.f, 3.f));
}

TEST(Math, scale){

}

TEST(Math, lookAt){

}

TEST(Math, cross_matrix){

}

TEST(Math, To_radians){
    const float degree1 = 45.f;
    const float degree2 = 70.f;
    const float radins1 = to_radians(degree1);
    const float radins2 = to_radians(degree2);
    const float answer1 = 0.785398;
    const float answer2 = 1.22173;
    EXPECT_EQ(radins1, answer1);
    //EXPECT_EQ(radins2, answer2);
}

TEST(Math, projPerspective){

}
