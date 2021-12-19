#include <unity.h>
#include "str_util/str_util.h"

void test_count(){
   
    auto a = str_util::substr_count("aabba dsd retwretoip dsd fgjklsdfg;m ansmf,.sdfgjkloeqrtoiu dsd asdfjkl;s'dfg", String("dsd"));
    TEST_ASSERT_EQUAL_INT(3, a);
}

void test_indexof(){
    auto a = str_util::index_of("aaadsdbbbdsdccc", "dsd", 0);
    TEST_ASSERT_EQUAL_INT(3, a);
    a = str_util::index_of("aaadsdbbbdsdccc", "dsd", 1);
    TEST_ASSERT_EQUAL_INT(9, a);

    a = str_util::index_of("aabba dsd retwretoip dsd fgjklsdfg;m ansmf,.sdfgjkloeqrtoiu dsd asdfjkl;s'dfg", "dsd", 2);
    TEST_ASSERT_EQUAL_INT(60, a);
    a = str_util::index_of("aabba dsd retwretoip dsd fgjklsdfg;m ansmf,.sdfgjkloeqrtoiu dsd asdfjkl;s'dfg", "dsd", 3);
    TEST_ASSERT_EQUAL_INT(-1, a);
}

void test_get_token(){
    auto a = str_util::get_token("aaadsdbbbdsdccc", "dsd", 0);
    TEST_ASSERT_EQUAL_STRING("aaa", a.c_str());
    a = str_util::get_token("aaadsdbbbdsdccc", "dsd", 1);
    TEST_ASSERT_EQUAL_STRING("bbb", a.c_str());
    a = str_util::get_token("aaadsdbbbdsdccc", "dsd", 2);
    TEST_ASSERT_EQUAL_STRING("ccc", a.c_str());
    
    a = str_util::get_token("aabba dsd retwretoip dsd fgjklsdfg;m ansmf,.sdfgjkloeqrtoiu dsd asdfjkl;s'dfg", "dsd", 1);
    TEST_ASSERT_EQUAL_STRING(" retwretoip ", a.c_str());
}

void test_get_left_token(){
    auto res = str_util::get_left_token("aaadsdbbbdsdccc", "dsd");
    TEST_ASSERT_EQUAL_STRING("aaa", res.c_str());
    res = str_util::get_left_token("aaadsbbbdsccc", "dsd");
    TEST_ASSERT_EQUAL_STRING("aaadsbbbdsccc", res.c_str());
}

void test_get_right_token(){
    auto res = str_util::get_right_token("aaadsdbbbdsdccc", "dsd");
    TEST_ASSERT_EQUAL_STRING("bbbdsdccc", res.c_str());
    res = str_util::get_right_token("aaadsbbbdsccc", "dsd");
    TEST_ASSERT_EQUAL_STRING("", res.c_str());
}


void test_str_main(void){
    RUN_TEST(test_count);
    RUN_TEST(test_indexof);
    RUN_TEST(test_get_token);
    RUN_TEST(test_get_left_token);
    RUN_TEST(test_get_right_token);
    //RUN_TEST(test_split);
}