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
            if (pl - j > 1 && p[j + 1] == '*')// ��һ���Ǵ�*�����
            {
                dp[i][j] = dp[i][j + 2] || (i < sl && (p[j] == '.' || p[j] == s[i]) && dp[i + 1][j]);// *����Ϊ��������Ե�һ���������������ֱ���ж�֮ǰ�����ͨ��ͨ�����ǲ����棬�ڶ��־�������ͬ�ģ�����.������������ͬ��������Ϊtrue
            }
            else
            {
                dp[i][j] = i < sl && (p[j] == '.' || p[j] == s[i]) && dp[i + 1][j + 1];// �������������.������������ͬ��Ϊ��
            }
        }
    }

    return dp[0][0];//����жϵ���һλ�����������Ϊ����������֤����һ�����ϵ�·��ͬ��
}


int main()
{
    bool isMatch(char* s, char* p);
    char s[] = "mississippi";
    char p[] = "mis*is*ip*.";
    printf("%d", isMatch(s, p));
}
