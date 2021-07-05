// I could get this to work with the help of the official guide:
// https://google.github.io/googletest/advanced.html, section 'Typed tests'
//

#include <gtest/gtest.h>
#include <Vector3.h>
#include <list>

const static double DELTA = 0.00001;

template <typename T>
class Vector3Test : public ::testing::Test
{
    public:
    using List = std::list<T>;
    static T shared_;
    T value_;
};

// test template classes
using MyTypes = ::testing::Types<float, double>;
// define the test suite
TYPED_TEST_SUITE(Vector3Test, MyTypes);

TYPED_TEST(Vector3Test, constructorTest) 
{
    // arrange
    TypeParam x = 1, y = 2, z = 3;
    // act
    Vector3<TypeParam> testVector(x, y, z);
    // assert
    EXPECT_EQ(x, testVector.x);
    EXPECT_EQ(y, testVector.y);
    EXPECT_EQ(z, testVector.z);
}

TYPED_TEST(Vector3Test, copyContructorTest)
{
    Vector3<TypeParam> vec1(1.0, 2.0, 3.0);
    Vector3<TypeParam> vec2 = vec1;
    EXPECT_EQ(vec1.x, vec2.x);
    EXPECT_EQ(vec1.y, vec2.y);
    EXPECT_EQ(vec1.z, vec2.z);
}

TYPED_TEST(Vector3Test, additionExecuteTest)
{
    Vector3<TypeParam> vec1(1, 2, 3);
    Vector3<TypeParam> vec2(4, 5, 6);

    vec1 += vec2;

    EXPECT_EQ(vec1.x, 5);
    EXPECT_EQ(vec1.y, 7);
    EXPECT_EQ(vec1.z, 9);
}

TYPED_TEST(Vector3Test, additionReturnTest)
{
    Vector3<TypeParam> vec1(1, 2, 3);
    Vector3<TypeParam> vec2(4, 5, 6);

    Vector3<TypeParam> result = vec1 + vec2;

    EXPECT_EQ(result.x, 5);
    EXPECT_EQ(result.y, 7);
    EXPECT_EQ(result.z, 9);
}

TYPED_TEST(Vector3Test, dotProductTest)
{
    Vector3<TypeParam> vec1(1, 2, 3);
    Vector3<TypeParam> vec2(4, 5, 6);

    TypeParam result = vec1 * vec2;

    // dot product = 1*4 + 2*5 + 3*6 = 4 + 10 + 18 = 32
    EXPECT_EQ(result, 32);
}

TYPED_TEST(Vector3Test, scalarMultiplicationExecuteTest)
{
    Vector3<TypeParam> vec1(1.0, 2.0, 3.0);
    vec1 *= 2.0;
    EXPECT_EQ(vec1.x, 2);
    EXPECT_EQ(vec1.y, 4);
    EXPECT_EQ(vec1.z, 6);

    Vector3<TypeParam> vec2(1, 2, 3);
    vec2 *= 0.5;
    EXPECT_EQ(vec2.x, 0.5);
    EXPECT_EQ(vec2.y, 1.0);
    EXPECT_EQ(vec2.z, 1.5);
}

TYPED_TEST(Vector3Test, scalarMultiplicationReturnTest)
{
    Vector3<TypeParam> vec1(1.0, 2.0, 3.0);
    Vector3<TypeParam> vec2 = vec1 * 2.0;

    EXPECT_EQ(vec2.x, 2.0);
    EXPECT_EQ(vec2.y, 4.0);
    EXPECT_EQ(vec2.z, 6.0);
}

TYPED_TEST(Vector3Test, zeroVectorTest)
{
    Vector3<TypeParam> vec = Vector3<TypeParam>::zero();
    EXPECT_EQ(vec.x, 0);
    EXPECT_EQ(vec.y, 0);
    EXPECT_EQ(vec.z, 0);
}

TYPED_TEST(Vector3Test, magnitudeTest)
{
    Vector3<TypeParam> vec(1.0, 2.0, 3.0);
    TypeParam result = vec.mag();
    EXPECT_NEAR(result, 3.741657, DELTA);
}

TYPED_TEST(Vector3Test, magSquaredTest)
{
    Vector3<TypeParam> vec(1.0, 2.0, 3.0);
    TypeParam result = vec.magSquared();
    EXPECT_NEAR(result, 14.0, DELTA);
}

TYPED_TEST(Vector3Test, normalizeTest)
{
    Vector3<TypeParam> vec(1.0, 2.0, 3.0);
    Vector3<TypeParam> result = vec.normalize();
    TypeParam newx = vec.x / vec.mag();
    TypeParam newy = vec.y / vec.mag();
    TypeParam newz = vec.z / vec.mag();
    EXPECT_NEAR(result.x, newx, DELTA);
    EXPECT_NEAR(result.y, newy, DELTA);
    EXPECT_NEAR(result.z, newz, DELTA);
}

TYPED_TEST(Vector3Test, crossProductTest)
{
    Vector3<TypeParam> vec1(1.0, 2.0, 3.0);
    Vector3<TypeParam> vec2(4.0, 5.0, 6.0);
    Vector3<TypeParam> result = Vector3<TypeParam>::cross(vec1, vec2);

    EXPECT_NEAR(result.x, -3, DELTA);
    EXPECT_NEAR(result.y, 6, DELTA);
    EXPECT_NEAR(result.z, -3, DELTA);
}
