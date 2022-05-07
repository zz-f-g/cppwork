/* 2052110 自动化 郭子瞻 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：tj_strlen
  功    能：get the length of a string in character array
  输入参数：const char str[]
  返 回 值：int len
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        ++len;
    }
    return len;
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：append s2 to s1
  输入参数：char s1[]: string to be appended to
            const char s2[]: string to be appended
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    /*
    if (sizeof(s1) / sizeof(s1[0]) < len1 + len2 + 1)
        return 1;
    */
    for (int i = 0; i < len2; ++i)
    {
        s1[len1 + i] = s2[i];
    }
    s1[len1 + len2] = '\0';
    return 0;
}

/***************************************************************************
  函数名称：tj_strncat
  功    能：append the first len characters of s2 to s1
  输入参数：char s1[]: string to be appended to
            const char s2[]: string to be appended
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    int len1 = tj_strlen(s1);
    int i = 0;
    /*
    if (sizeof(s1) / sizeof(s1[0]) < len1 + len + 1)
        return 1;
    */
    for (; i < len; ++i)
    {
        if (s2[i] == '\0')
            break;
        s1[len1 + i] = s2[i];
    }
    s1[len1 + i] = '\0';
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcpy
  功    能：copy s2 to s1, cover the previous content of s1
  输入参数：char s1[]
            const char s2[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    int len2 = tj_strlen(s2);
    int i = 0;
    /*
    if (sizeof(s1) / sizeof(s1[0]) < len2 + 1)
        return 1;
    */
    for (i = 0; i < len2; ++i)
    {
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strncpy
  功    能：copy the first len characters in s2 to s1
  输入参数：char s1[]
            const char s2[]
            const int len
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    int n = tj_strlen(s2);
    n = (n < len) ? n : len;
    /*
    if (tj_strlen(s1) < n)
        return 1;
    */
    for (int i = 0; i < n; ++i)
    {
        s1[i] = s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcmp
  功    能：compare chars in s1 and s2
  输入参数：const char s1[]
            const char s2[]
  返 回 值：difference between the first different chars in s1 and s2
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    int i = 0;
    while (1)
    {
        if (s1[i] == '\0' && s2[i] == '\0')
            break;
        else if (s1[i] != s2[i])
            return s1[i] - s2[i];
        ++i;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcasecmp
  功    能：compare chars in s1, s2 (no difference in capital)
  输入参数：const char s1[]
            const char s2[]
  返 回 值：difference between the first different chars in s1 and s2
  说    明：convert capital letter into non-capital letter first
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    int i = 0;
    char tmp1;
    char tmp2;
    while (1)
    {
        tmp1 = (s1[i] >= 'A' && s1[i] <= 'Z') ? s1[i] - 'A' + 'a' : s1[i];
        tmp2 = (s2[i] >= 'A' && s2[i] <= 'Z') ? s2[i] - 'A' + 'a' : s2[i];
        if (tmp1 == '\0' && tmp2 == '\0')
            break;
        else if (tmp1 != tmp2)
            return tmp1 - tmp2;
        ++i;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：compare the first len chars in s1 and s2
  输入参数：const char s1[]
            const char s2[]
  返 回 值：difference between the first different chars in s1 and s2
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (s1[i] == '\0' && s2[i] == '\0')
            break;
        else if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：compare the first len chars in s1 and s2
  输入参数：const char s1[]
            const char s2[]
  返 回 值：difference between the first different chars in s1 and s2
  说    明：convert capital letter into non-capital letter first
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    char tmp1;
    char tmp2;
    for (int i = 0; i < len; ++i)
    {
        tmp1 = (s1[i] >= 'A' && s1[i] <= 'Z') ? s1[i] - 'A' + 'a' : s1[i];
        tmp2 = (s2[i] >= 'A' && s2[i] <= 'Z') ? s2[i] - 'A' + 'a' : s2[i];
        if (tmp1 == '\0' && tmp2 == '\0')
            break;
        else if (tmp1 != tmp2)
            return tmp1 - tmp2;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strupr
  功    能：convert lower letters to upper letters
  输入参数：char str[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; ++i)
    {
        str[i] += (str[i] >= 'a' && str[i] <= 'z') ? 'A' - 'a' : 0;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strlwr
  功    能：convert upper letters to lower letters
  输入参数：char str[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; ++i)
    {
        str[i] += (str[i] >= 'A' && str[i] <= 'Z') ? 'a' - 'A' : 0;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strchr
  功    能：find the index where the first character appears
  输入参数： const char str[]
            char ch
  返 回 值：int index
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == ch)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strstr
  功    能：find the index where the substring first appears
  输入参数：const char str[], const char substr[]
  返 回 值：int index
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    int len = tj_strlen(str);
    int sublen = tj_strlen(substr);
    int flag = 1;
    for (int i = 0; i < len - sublen + 1; ++i)
    {
        flag = 1;
        for (int j = 0; j < sublen; ++j)
        {
            if (str[i + j] != substr[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strrchr
  功    能：find the index where the chararacter last appears
  输入参数：const char str[]
            const char ch
  返 回 值：int index
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    int len = tj_strlen(str);
    for (int i = len - 1; i >= 0; --i)
    {
        if (str[i] == ch)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strstr
  功    能：find the index where the substring last appears
  输入参数：const char str[], const char substr[]
  返 回 值：int index
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    int len = tj_strlen(str);
    int sublen = tj_strlen(substr);
    int flag = 1;
    for (int i = len - sublen; i >= 0; --i)
    {
        flag = 1;
        for (int j = 0; j < sublen; ++j)
        {
            if (str[i + j] != substr[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            return i + 1;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strrev
  功    能：reverse the string
  输入参数：char str[]
  返 回 值：0
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    char tmp;
    int i = 0;
    int j = tj_strlen(str) - 1;
    while (i < j)
    {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        ++i;
        --j;
    }
    return 0; //return值可根据需要修改
}
