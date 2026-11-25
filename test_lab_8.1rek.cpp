
#include <gtest/gtest.h>
#include <cstring>
#include "lab_8.1rek.cpp"

// Тест 1. Знаходження трьох зірочок у рядку
TEST(Lab81Rek, FindThreeStars) {
    char str[101] = "Hello *** world";

    EXPECT_TRUE(Find(str, 0));
}

// Тест 2. Рядок не містить трьох зірочок
TEST(Lab81Rek, NoThreeStars) {
    char str[101] = "Hello ** world";

    EXPECT_FALSE(Find(str, 0));
}

// Тест 3. Три зірочки наприкінці рядка
TEST(Lab81Rek, StarsAtEnd) {
    char str[101] = "Hello***";

    EXPECT_TRUE(Find(str, 0));
}

// Тест 4. Заміна однієї групи зірочок
TEST(Lab81Rek, ChangeThreeStars) {
    char str[101] = "Hello *** world";

    Change(str, 0);

    EXPECT_STREQ(str, "Hello !! world");
}

// Тест 5. Заміна декількох груп зірочок
TEST(Lab81Rek, ChangeMultipleStars) {
    char str[101] = "*** Hello ***";

    Change(str, 0);

    EXPECT_STREQ(str, "!! Hello !!");
}

// Тест 6. Рядок без трьох зірочок залишається незмінним
TEST(Lab81Rek, ChangeWithoutStars) {
    char str[101] = "Hello ** world";

    Change(str, 0);

    EXPECT_STREQ(str, "Hello ** world");
}

// Тест 7. Заміна двох послідовних груп зірочок
TEST(Lab81Rek, ChangeSixStars) {
    char str[101] = "******";

    Change(str, 0);

    EXPECT_STREQ(str, "!!!!");
}