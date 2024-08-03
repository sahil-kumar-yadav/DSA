# Char Array and String

# Reverse a String

```cpp
void reverse(string &str)
{
    int i = 0, j = str.length() - 1;
    cout << "orginal " << str << endl;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    cout << "reversed " << str << endl;
}

```

# Check Palindrome

```cpp
bool checkPalindrome(string str)
{

    int i = 0, j = str.length()-1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}
```

# check palindrome part 2

- You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

- Note :

   String 'S' is NOT case sensitive

```cpp
bool checkPalindrome(string str)
{

    string newStr = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            newStr += str[i];
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            newStr += str[i] + 32;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            newStr += str[i];
        }
    }

    int i = 0, j = newStr.length() - 1;
    while (i < j)
    {
        if (newStr[i] != newStr[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```

# 

```cpp

```



