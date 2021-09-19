#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
bool isMatch(char* s, char* p) {
    int sl = strlen(s);
    int pl = strlen(p);
    bool dp[20][30];
    memset(dp, 0, sizeof(dp));
    for (int i = sl; i > -1; --i)
    {
        for (int j = pl; j > -1; --j)
        {
            if (i == sl && j == pl)
            {
                dp[i][j] = true;
                continue;
            }
            if (pl - j > 1 && p[j + 1] == '*')// 第一种是带*的情况
            {
                dp[i][j] = dp[i][j + 2] || (i < sl && (p[j] == '.' || p[j] == s[i]) && dp[i + 1][j]);// *可能为零个，所以第一种情况是零的情况，直接判断之前的情况通不通过，是不是真，第二种就是有相同的，符号.或者是两者相同，都可以为true
            }
            else
            {
                dp[i][j] = i < sl && (p[j] == '.' || p[j] == s[i]) && dp[i + 1][j + 1];// 正常情况，符号.或者是两者相同则为真
            }
        }
    }

    return dp[0][0];//最后判断到第一位，如果还是有为真的情况，这证明有一条以上的路是同的
}


int main()
{
    bool isMatch(char* s, char* p);
    char s[] = "mississippi";
    char p[] = "mis*is*ip*.";
    printf("%d", isMatch(s, p));
}
