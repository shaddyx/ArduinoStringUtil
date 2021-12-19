#include <Arduino.h>
#include "str_util.h"
namespace str_util {
     int atoi(const String &str_value){
        int num = 0;
        int i = 0;
        bool isNegetive = false;
        auto str = str_value.c_str();
        if(str[i] == '-'){
            isNegetive = true;
            i++;
        }
        while (str[i] && (str[i] >= '0' && str[i] <= '9')){
            num = num * 10 + (str[i] - '0');
            i++;
        }
        if(isNegetive) num = -1 * num;
        return num;
    }

    bool parse_bool(const String &str_value){
        auto lowercased = String(str_value);
        lowercased.toLowerCase();
        return lowercased == "true";
    }
    
    int substr_count(const String * str, const String * delimiter) {
        int count = 0;
        const char *tmp = str->c_str();
        while(tmp = strstr(tmp, delimiter->c_str())){
            count++;
            tmp+= delimiter->length();
        }
        return count;
    }
    int substr_count(const String &str, const String &delimiter){
        return substr_count(&str, &delimiter);
    }

    int index_of(const String * str, const String * delimiter){
        return index_of(str, delimiter, 0);
    }

     int index_of(const String &str, const String &delimiter){
        return index_of(&str, &delimiter);
    }

    int index_of(const String * str, const String * delimiter, int number){
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
    
    int index_of(const String &str, const String &delimiter, int number) {
        return index_of(&str, &delimiter, number);
    }
    
    int token_count(const String * str, const String * delimiter) {
        return substr_count(str, delimiter) + 1;
    }

    int token_count(const String &str, const String &delimiter) {
        return token_count(&str, &delimiter);
    }

    String get_token(const String * str, const String * delimiter, int number){
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
    String get_token(const String &str, const String &delimiter, int number){
        return get_token(&str, &delimiter, number);
    }
    
    String get_right_token(const String * str, const String * delimiter) {
        auto start = index_of(str, delimiter);
        if (start != -1){
            return str ->substring(start + delimiter->length());
        }
        return String();
    }
    
    String get_right_token(const String &str, const String &delimiter) {
        return get_right_token(&str, &delimiter);
    }
    
    String get_left_token(const String * str, const String * delimiter) {
        auto end = index_of(str, delimiter);
        if (end != -1){
            return str ->substring(0, end);
        }
        return *str;
    }
    
    String get_left_token(const String &str, const String &delimiter) {
        return get_left_token(&str, &delimiter);
    }

}