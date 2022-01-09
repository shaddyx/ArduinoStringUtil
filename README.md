# ArduinoStringUtil - simple strong utilites for arduino

The basic idea of this project is to have the library for simple string tokenization/splitting

Find the index of string
```cpp
    auto a = str_util::index_of("aaadsdbbbdsdccc", "dsd", 0);
    // a == 3
    a = str_util::index_of("aaadsdbbbdsdccc", "dsd", 1);
    // a == 9
```

get token count, the result will be zero if no token found:
```cpp
    auto a = str_util::token_count("aaadsdbbbdsdccc", "dsd");
    //a == 3
```

get token by index (python equivalent "aaadsdbbbdsdccc".split("aaa")[0]), the result will be an empty string if no token found:
```cpp
    auto a = str_util::get_token("aaadsdbbbdsdccc", "dsd", 0);
    //a == "aaa"
```

get left token:
```cpp
    auto res = str_util::get_left_token("aaadsdbbbdsdccc", "dsd");
    //res == "aaa"
```

get right token:
```cpp
    auto res = str_util::get_right_token("aaadsdbbbdsdccc", "dsd");
    //res == "bbbdsdccc"
```


primitive parsers:
```cpp
    TEST_ASSERT_EQUAL(10, str_util::parse_int("10"));
    TEST_ASSERT_EQUAL(11.5, str_util::parse_float("11.5"));
    TEST_ASSERT_EQUAL(true, str_util::parse_bool("true"));
    TEST_ASSERT_EQUAL(false, str_util::parse_bool("false"));
```