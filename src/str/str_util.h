#pragma once
#include <Arduino.h>
namespace str_util {
    int substr_count(String * str, String * delimiter);
    int substr_count(String str, String delimiter);
    int token_count(String * str, String * delimiter);
    int index_of(String * str, String * delimiter, int number);
    int index_of(String str, String delimiter, int number);
    String get_token(String * str, String * delimiter, int number);
    String get_token(String str, String delimiter, int number);
}
