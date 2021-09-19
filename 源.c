#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isMatch(char* s, char* p) {
    if (*s == '\0' && *p == '\0') return true;//s��p��Ϊ�գ�ƥ��ɹ�
    if (*p == '\0') return false;//s�ǿգ�p �գ�ʧ��
    //s,p�ǿ�ʱ���
    int flag = false;
    if (*s != '\0' && (*s == *p || *p == '.')) flag = true;//s��p���ǿգ� ��Ȼ�pΪ��.��ʱƥ��ɹ�
    //��p����һλΪ��*��ʱ��*����0����s�и���ĸ��p��*����ĸ�Ƚϣ�*��������s����һ����ĸ��p�и���ĸ�Ƚ�
    if (*(p + 1) == '*') {
        return isMatch(s, p + 2) || flag && isMatch(s + 1, p);
    }
    //��p��һλ��Ϊ��*������s��p�����һλ���бȽ�
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
