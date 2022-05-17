/* 2052110 郭子瞻 自动化 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    const char *p_char = str;
    if (str)
    {
        while (*p_char)
        {
            ++p_char;
        }
    }
    return (p_char - str);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    char *s1cpy = s1;
    if (s1 && s2)
    {
        while (*s1)
        {
            ++s1;
        }
        while (*s1 = *s2)
        {
            ++s1;
            ++s2;
        }
    }
    return s1cpy;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    char *s1cpy = s1;
    if (s1 && s2)
    {
        while (*s1)
        {
            ++s1;
        }
        const char *p_char = s2;
        while (*p_char && (p_char - s2) < len)
        {
            *s1 = *p_char;
            ++s1;
            ++p_char;
        }
        *s1 = '\0';
    }
    return s1cpy;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    char *s1cpy = s1;
    if (s1)
    {
        if (!s2)
        {
            *s1 = '\0';
            return s1cpy;
        }
        while (*s1 = *s2)
        {
            ++s1;
            ++s2;
        }
    }
    return s1cpy;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char *s1cpy = s1;
    if (s1 && s2)
    {
        const char *p_char = s2;
        while (*p_char && (p_char - s2) < len)
        {
            *s1 = *p_char;
            ++s1;
            ++p_char;
        }
    }
    return s1cpy;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    if (s1 && !s2)
        return 1;
    else if (!s1 && s2)
        return -1;
    else if (!s1 && !s2)
        return 0;
    else
    {
        while (*s1 || *s2)
        {
            if (*s1 != *s2)
                return (int)(*s1 - *s2);
            ++s1;
            ++s2;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    if (s1 && !s2)
        return 1;
    else if (!s1 && s2)
        return -1;
    else if (!s1 && !s2)
        return 0;
    else
    {
        char tmp1, tmp2;
        while (*s1 || *s2)
        {
            tmp1 = *s1;
            tmp2 = *s2;
            if (*s1 >= 'A' && *s1 <= 'Z')
                tmp1 += 'a' - 'A';
            if (*s2 >= 'A' && *s2 <= 'Z')
                tmp2 += 'a' - 'A';
            if (tmp1 != tmp2)
                return (int)(tmp1 - tmp2);
            ++s1;
            ++s2;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    if (s1 && !s2)
        return 1;
    else if (!s1 && s2)
        return -1;
    else if (!s1 && !s2)
        return 0;
    else
    {
        const char *s1cpy = s1;
        const char *s2cpy = s2;
        while ((*s1 || *s2) && (s1 - s1cpy) < len)
        {
            if (*s1 != *s2)
                return (int)(*s1 - *s2);
            ++s1;
            ++s2;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    if (s1 && !s2)
        return 1;
    else if (!s1 && s2)
        return -1;
    else if (!s1 && !s2)
        return 0;
    else
    {
        const char *s1cpy = s1;
        const char *s2cpy = s2;
        char tmp1;
        char tmp2;
        while ((*s1 || *s2) && (s1 - s1cpy) < len)
        {
            tmp1 = *s1;
            tmp2 = *s2;
            if (*s1 >= 'A' && *s1 <= 'Z')
                tmp1 += 'a' - 'A';
            if (*s2 >= 'A' && *s2 <= 'Z')
                tmp2 += 'a' - 'A';
            if (tmp1 != tmp2)
                return (int)(tmp1 - tmp2);
            ++s1;
            ++s2;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    if (!str)
        return str;    
    char *p_char = str;
    while (*p_char)
    {
        if (*p_char >= 'a' && *p_char <= 'z')
            *p_char += 'A' - 'a';
        ++p_char;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    if (!str)
        return str;    
    char *p_char = str;
    while (*p_char)
    {
        if (*p_char >= 'A' && *p_char <= 'Z')
            *p_char += 'a' - 'A';
        ++p_char;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    if (!str)
        return 0;    
    int index = 0;
    while (*str)
    {
        if (*str == ch)
            return index + 1;
        ++index;
        ++str;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    if (!str)
        return 0;    
    if (!substr)
        return 0;    
    const char *p = str;
    const char *p_ch = p;
    const char *p_sub = substr;
    int len = tj_strlen(str);
    int sublen = tj_strlen(substr);
    int flag = 1;
    while (p - str < len - sublen + 1)
    {
        flag = 1;
        while (*p_sub)
        {
            if (*p_ch != *p_sub)
            {
                flag = 0;
                break;
            }
            ++p_ch;
            ++p_sub;
        }
        if (flag)
            return (int)(p - str) + 1;
        ++p;
        p_ch = p;
        p_sub = substr;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    if (!str)
        return 0;    
    const char *p_char = str;
    int index = 0;
    while (*p_char)
    {
        ++p_char;
        ++index;
    }
    while (p_char >= str)
    {
        if (*p_char == ch)
            return index + 1;
        --index;
        --p_char;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    if (!str)
        return 0;    
    if (!substr)
        return 0;    
    int len = tj_strlen(str);
    int sublen = tj_strlen(substr);
    const char *p = str + (len - sublen);
    const char *p_ch = p;
    const char *p_sub = substr;
    int flag = 1;
    while (p >= str)
    {
        flag = 1;
        while (*p_sub)
        {
            if (*p_ch != *p_sub)
            {
                flag = 0;
                break;
            }
            ++p_ch;
            ++p_sub;
        }
        if (flag)
            return (int)(p - str) + 1;
        --p;
        p_ch = p;
        p_sub = substr;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    if (!str)
        return str;
    char * p_rev = str;
    char * p = str;
    char tmp;
    while (*p_rev)
    {
        ++p_rev;
    }
    --p_rev;
    while (p < p_rev)
    {
        tmp = *p;
        *p = *p_rev;
        *p_rev = tmp;
        ++p;
        --p_rev;
    }
    return str;
}
