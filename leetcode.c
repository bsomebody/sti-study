#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool Match(char* s, char* p,int i,int j) {
    int pl = strlen(p);
    int sl = strlen(s);
    if (j == pl) return i ==sl;
    if(pl-j>1&&p[j+1]=='*') 
    {
        return Match(s, p, i, j + 2) || (i != sl && (s[i] == p[j] || p[j] == '.') && Match(s, p, ++i, ++j));
    }
    else { return i != sl && (s[i] == p[j] || p[j] == '.') && Match(s, p, ++i, ++j); }
}
bool isMatch(char* s, char* p) { return      Match(s, p, 0, 0); }

int main()
{
    bool Match(char* s, char* p, int i, int j);
    bool isMatch(char* s, char* p);
    char s[]= "aaa";
    char p[]= "aaa";
    printf("%d", isMatch(s, p));
}
