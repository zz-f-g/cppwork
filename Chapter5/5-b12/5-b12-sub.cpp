/* 2052110 �Զ��� ����հ */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��return 0ֻ��һ��ʾ�����ɸı� */

/* ���������κ���ʽ���ⲿȫ�֡���̬ȫ�֡��궨�塢ֻ������ */

/***************************************************************************
  �������ƣ�tj_strlen
  ��    �ܣ�get the length of a string in character array
  ���������const char str[]
  �� �� ֵ��int len
  ˵    ����
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
  �������ƣ�tj_strcat
  ��    �ܣ�append s2 to s1
  ���������char s1[]: string to be appended to
            const char s2[]: string to be appended
  �� �� ֵ��0
  ˵    ����
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
  �������ƣ�tj_strncat
  ��    �ܣ�append the first len characters of s2 to s1
  ���������char s1[]: string to be appended to
            const char s2[]: string to be appended
  �� �� ֵ��0
  ˵    ����
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strcpy
  ��    �ܣ�copy s2 to s1, cover the previous content of s1
  ���������char s1[]
            const char s2[]
  �� �� ֵ��0
  ˵    ����
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strncpy
  ��    �ܣ�copy the first len characters in s2 to s1
  ���������char s1[]
            const char s2[]
            const int len
  �� �� ֵ��0
  ˵    ����
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strcmp
  ��    �ܣ�compare chars in s1 and s2
  ���������const char s1[]
            const char s2[]
  �� �� ֵ��difference between the first different chars in s1 and s2
  ˵    ����
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strcasecmp
  ��    �ܣ�compare chars in s1, s2 (no difference in capital)
  ���������const char s1[]
            const char s2[]
  �� �� ֵ��difference between the first different chars in s1 and s2
  ˵    ����convert capital letter into non-capital letter first
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strncmp
  ��    �ܣ�compare the first len chars in s1 and s2
  ���������const char s1[]
            const char s2[]
  �� �� ֵ��difference between the first different chars in s1 and s2
  ˵    ����
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strncmp
  ��    �ܣ�compare the first len chars in s1 and s2
  ���������const char s1[]
            const char s2[]
  �� �� ֵ��difference between the first different chars in s1 and s2
  ˵    ����convert capital letter into non-capital letter first
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strupr
  ��    �ܣ�convert lower letters to upper letters
  ���������char str[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strupr(char str[])
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; ++i)
    {
        str[i] += (str[i] >= 'a' && str[i] <= 'z') ? 'A' - 'a' : 0;
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strlwr
  ��    �ܣ�convert upper letters to lower letters
  ���������char str[]
  �� �� ֵ��0
  ˵    ����
***************************************************************************/
int tj_strlwr(char str[])
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; ++i)
    {
        str[i] += (str[i] >= 'A' && str[i] <= 'Z') ? 'a' - 'A' : 0;
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strchr
  ��    �ܣ�find the index where the first character appears
  ��������� const char str[]
            char ch
  �� �� ֵ��int index
  ˵    ����
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    int len = tj_strlen(str);
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == ch)
            return i + 1;
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strstr
  ��    �ܣ�find the index where the substring first appears
  ���������const char str[], const char substr[]
  �� �� ֵ��int index
  ˵    ����
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strrchr
  ��    �ܣ�find the index where the chararacter last appears
  ���������const char str[]
            const char ch
  �� �� ֵ��int index
  ˵    ����
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    int len = tj_strlen(str);
    for (int i = len - 1; i >= 0; --i)
    {
        if (str[i] == ch)
            return i + 1;
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strstr
  ��    �ܣ�find the index where the substring last appears
  ���������const char str[], const char substr[]
  �� �� ֵ��int index
  ˵    ����
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}

/***************************************************************************
  �������ƣ�tj_strrev
  ��    �ܣ�reverse the string
  ���������char str[]
  �� �� ֵ��0
  ˵    ����
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
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}
