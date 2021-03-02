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
#include "rage_math/Vector3.h"

using namespace rage;

TEST(Vector3, Constructor) {
    vec3 test_vec3(1.f, 2.f, 3.f);
    EXPECT_EQ(test_vec3.x, 1.f);
    EXPECT_EQ(test_vec3.y, 2.f);
    EXPECT_EQ(test_vec3.z, 3.f);
}

TEST(Vector3, CopyConstructor) {
    vec3 test_vec3(1.f, 2.f, 3.f);
    vec3 copy_test_vec3 = test_vec3;
    EXPECT_EQ(copy_test_vec3.x, 1.f);
    EXPECT_EQ(copy_test_vec3.y, 2.f);
    EXPECT_EQ(copy_test_vec3.z, 3.f);
}

TEST(Vector3, AssignOperartor) {
    vec3 test_vec3(1.f, 2.f, 3.f);
    vec3 assign_test_vec3;
    assign_test_vec3 = test_vec3;
    EXPECT_EQ(assign_test_vec3.x, 1.f);
    EXPECT_EQ(assign_test_vec3.y, 2.f);
    EXPECT_EQ(assign_test_vec3.z, 3.f);
}

TEST(Vector3, EqualOperartor) {
    EXPECT_EQ(vec3(1.f, 2.f, 3.f) == vec3(1.f, 2.f, 3.f), true);
}

TEST(Vector3, NotEqualOperartor) {
    EXPECT_EQ(vec3(1.f, 2.f, 3.f) != vec3(1.f, 2.f, 4.f), true);
}

TEST(Vector3, OperatorPlusEqual) {
    vec3 lhs(1.f, 2.f, 3.f);
    vec3 rhs(1.f, 2.f, 3.f);
    EXPECT_EQ(lhs + rhs, vec3(2.f, 4.f, 6.f));
}

TEST(Vector3, OperatorMinusEqual) {
    vec3 lhs(1.f, 2.f, 3.f);
    vec3 rhs(1.f, 2.f, 3.f);
    EXPECT_EQ(lhs - rhs, vec3());
}

TEST(Vector3, OperatorMul) {
    vec3 lhs(1.f, 2.f, 3.f);
    float value = 4.f;
    EXPECT_EQ(lhs * value, vec3(4.f, 8.f, 12.f));
}

TEST(Vector3, OperatorPlus) {

}

TEST(Vector3, OperatorMinus) {

}

TEST(Vector3, Normalize) {

}

TEST(Vector3, Cross) {

}