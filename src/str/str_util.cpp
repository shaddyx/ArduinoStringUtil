#include <Arduino.h>
#include "str_util.h"
namespace str_util {
    int substr_count(String * str, String * delimiter) {
        int count = 0;
        const char *tmp = str->c_str();
        while(tmp = strstr(tmp, delimiter->c_str())){
            count++;
            tmp+= delimiter->length();
        }
        return count;
    }
    int substr_count(String str, String delimiter){
        return substr_count(&str, &delimiter);
    }

    int index_of(String * str, String * delimiter, int number){
        int count = 0;
        const char *tmp = str->c_str();
        while(tmp = strstr(tmp, delimiter->c_str())){
            if (count == number){
                break;
            }
            count++;
            tmp+= delimiter->length();
        }
        if (!tmp){
            return -1;
        }
        return tmp - str->c_str();
    }
    
    int index_of(String str, String delimiter, int number) {
        return index_of(&str, &delimiter, number);
    }
    
    int token_count(String * str, String * delimiter) {
        return substr_count(str, delimiter) + 1;
    }
    String get_token(String * str, String * delimiter, int number){
        auto end = index_of(str, delimiter, number);
        if (number == 0){
            return str -> substring(0, end);
        }
        auto start = index_of(str, delimiter, number - 1);
        if (start != -1){
            start += delimiter->length();
            if (end == -1){
                end = str->length();
            }
            return str -> substring(start, end);
        }
        return String();
    }    
    String get_token(String str, String delimiter, int number){
        return get_token(&str, &delimiter, number);
    }
}