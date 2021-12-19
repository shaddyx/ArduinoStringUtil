#pragma once
#include <Arduino.h>
namespace str_util {
    float parse_float(const String &str_value);
    int parse_int(const String &str_value);
    bool parse_bool(const String &str_value);
    int substr_count(const String * str, const String * delimiter);
    int substr_count(const String &str, const String &delimiter);
    int token_count(const String * str, const String * delimiter);
    int token_count(const String &str, const String &delimiter);
    int index_of(const String * str, const String * delimiter);
    int index_of(const String &str, const String &delimiter);
    int index_of(const String * str, const String * delimiter, int number);
    int index_of(const String &str, const String &delimiter, int number);
    String get_token(const String * str, const String * delimiter, int number);
    String get_token(const String &str, const String &delimiter, int number);
    String get_right_token(const String * str, const String * delimiter);
    String get_right_token(const String &str, const String &delimiter);
    String get_left_token(const String * str, const String * delimiter);
    String get_left_token(const String &str, const String &delimiter);
}
