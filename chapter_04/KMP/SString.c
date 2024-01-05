#include "SString.h"

/**
 * 初始化一个顺序串
 */
Status StrAssign(SString T, const char* chars) {
    int len = (int)strlen(chars);
    // 如果字符超过了顺序串的最大长度，错误
    if (len > MAXSIZE) {
        return ERROR;
    }
    // T[0] 存储字符串长度
    T[0] = len;
    for (int i = 0; i < len; i++) {
        T[i + 1] = chars[i];
    }
    return OK;
}