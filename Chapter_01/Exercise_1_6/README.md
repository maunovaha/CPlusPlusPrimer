# Exercise 1.6

> Explain whether the following program fragment is legal.

```cpp
std::cout << "The sum of " << v1;
		  << " and " << v2;
		  << " is " << v1 + v2 << std::endl;
```

The program is illegal because a semicolon at the end of *v1;* and *v2;* stops the chaining of more values to the *ostream* object, named as *std::cout*. The fixed version of the code would look like the following:

```cpp
std::cout << "The sum of " << v1
		  << " and " << v2 
		  << " is " << v1 + v2 << std::endl;
```