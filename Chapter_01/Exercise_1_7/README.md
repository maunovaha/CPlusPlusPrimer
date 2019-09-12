# Exercise 1.7

> Compile a program that has incorrectly nested comments.

```cpp
/*
 * Comment pairs /* */ cannot nest.
 * "cannot nest" is considered source code, 
 * as is the rest of the program
 */
int main()
{
    return 0;
}
```

**Output**

```
1>------ Build started: Project: Exercise_1_7, Configuration: Debug Win32 ------
1>Main.cpp
1>D:\...\Exercise_1_7\Source\Main.cpp(2,35): error C4430:  missing type specifier - int assumed. Note: C++ does not support default-int
1>D:\...\Exercise_1_7\Source\Main.cpp(2,31): error C2146:  syntax error: missing ';' before identifier 'nest'
1>D:\...\Exercise_1_7\Source\Main.cpp(5,2): warning C4138:  '*/' found outside of comment
1>D:\...\Exercise_1_7\Source\Main.cpp(7,1): error C2143:  syntax error: missing ';' before '{'
1>D:\...\Exercise_1_7\Source\Main.cpp(7,1): error C2447:  '{': missing function header (old-style formal list?)
1>Done building project "Exercise_1_7.vcxproj" -- FAILED.
========== Build: 0 succeeded, 1 failed, 0 up-to-date, 0 skipped ==========

```