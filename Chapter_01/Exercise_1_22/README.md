# Important note about running the program on Windows

This program does not work properly when it is run on Windows. I suspect that the reason has something to do with the way exit command ```ctrl+c``` behaves on Windows. In more detail, the problem has something to do with the following piece of code:

```cpp
while (std::cin >> current) {
	// ...
}

std::cout << "Stored a transaction: " << previous << std::endl; // <-- This line is not outputted properly
```

Consequently, terminating the program using ```ctrl+c``` does not output the last stored transaction details to console properly; It may miss varying number of characters, such as the average price. For this reason, the recommended approach for running the program is the following:

1. Use command prompt or similar program to navigate to the folder of the .exe file, e.g. ```D:\...\CPlusPlusPrimer\Chapter_01\Exercise_1_22\bin\Win32\Debug```
2. Run the program using ```Exercise_1_22.exe <../../../infile >../../../outfile```
3. Check the program output by opening the generated ```outfile``` which is located at the root of the exercise folder
