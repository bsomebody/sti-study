#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isMatch(char* s, char* p) {
    if (*s == '\0' && *p == '\0') return true;//s和p均为空，匹配成功
    if (*p == '\0') return false;//s非空，p 空，失败
    //s,p非空时情况
    int flag = false;
    if (*s != '\0' && (*s == *p || *p == '.')) flag = true;//s和p均非空， 相等或p为‘.’时匹配成功
    //当p的下一位为‘*‘时，*代表0个则s中该字母与p中*后字母比较，*代表多个则s中下一个字母与p中该字母比较
    if (*(p + 1) == '*') {
        return isMatch(s, p + 2) || flag && isMatch(s + 1, p);
    }
    //若p下一位不为’*‘，则s，p均向后一位进行比较
    else {
        return flag && isMatch(s + 1, p + 1);
    }
}

int main()
{
    bool isMatch(char* s, char* p);
    char s[]= "mississippi";
    char p[]= "mis*is*p*.";
    printf("%d", isMatch(s, p));
}
