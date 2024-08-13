# Char Array and String

# String methods

- **`at()`**
  - **Description:** Returns an indexed character from a string.
  - **Example:**
    ```cpp
    string str = "Hello, World!";
    char ch = str.at(7); // ch will be 'W'
    ```

- **`length()`**
  - **Description:** Returns the length of a string.
  - **Example:**
    ```cpp
    string str = "Hello";
    int len = str.length(); // len will be 5
    ```

- **`size()`**
  - **Description:** Alias of `length()`. Returns the length of a string.
  - **Example:**
    ```cpp
    string str = "Hello";
    int sz = str.size(); // sz will be 5
    ```

- **`max_size()`**
  - **Description:** Returns the maximum length of a string.
  - **Example:**
    ```cpp
    string str = "Hello";
    size_t maxLen = str.max_size(); // maxLen will be implementation-defined, often very large
    ```

- **`empty()`**
  - **Description:** Checks whether a string is empty or not.
  - **Example:**
    ```cpp
    string str = "";
    bool isEmpty = str.empty(); // isEmpty will be true
    ```

- **`append()`**
  - **Description:** Appends a string (or a part of a string) to another string.
  - **Example:**
    ```cpp
    string str1 = "Hello";
    string str2 = " World!";
    str1.append(str2); // str1 will be "Hello World!"
    ```

- **`substr()`**
  - **Description:** Returns a part of a string from a start index (position) and length.
  - **Example:**
    ```cpp
    string str = "Hello, World!";
    string sub = str.substr(7, 5); // sub will be "World"
    ```

- **`find()`**
  - **Description:** Returns the index (position) of the first occurrence of a string or character.
  - **Example:**
    ```cpp
    string str = "Hello, World!";
    size_t pos = str.find("World"); // pos will be 7
    ```

- **`rfind()`**
  - **Description:** Returns the index (position) of the last occurrence of a string or character.
  - **Example:**
    ```cpp
    string str = "Hello, World! World!";
    size_t pos = str.rfind("World"); // pos will be 13
    ```

- **`replace()`**
  - **Description:** Replaces a part of a string with another string.
  - **Example:**
    ```cpp
    string str = "Hello, World!";
    str.replace(7, 5, "Universe"); // str will be "Hello, Universe!"
    ```

- **`insert()`**
  - **Description:** Inserts a string at a specified index (position).
  - **Example:**
    ```cpp
    string str = "Hello, World!";
    str.insert(7, "Beautiful "); // str will be "Hello, Beautiful World!"
    ```

- **`erase()`**
  - **Description:** Removes characters from a string.
  - **Example:**
    ```cpp
    string str = "Hello, World!";
    str.erase(5, 7); // str will be "Hello!"
    ```

- **`compare()`**
  - **Description:** Compares two strings.
  - **Example:**
    ```cpp
    string str1 = "Hello";
    string str2 = "World";
    int result = str1.compare(str2); // result will be negative because "Hello" < "World"
    ```

These methods offer a versatile toolkit for managing and manipulating strings, providing essential functionalities for effective text processing.

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



