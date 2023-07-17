# magiXOR

magiXOR - a simple to use string encryption header file. 

![magiXOR](https://github.com/REVRBE/magiXOR/assets/129604052/50f26b96-775a-4a0b-b8ca-d948d157eacd)
![IDA](https://github.com/REVRBE/magiXOR/assets/129604052/6782067e-6363-4832-be34-138d4c983dad)

## Features

* Compile-time XOR string encryption and decryption.
* Dynamic key-generation using __TIME__ macro to generate close-to unique secret keys based on minutes component.
* Simple to use with magiXOR macro.
* Multiple datatypes supported (works with ImGui projects).
* Using CBC (Cipher Block Chaining) to provide stronger encryption.
* Encrypted and decrypted data hidden in the binary/.rdata.
* Simple function obfuscation for key-generation functions.
  
## Usage

1. Be sure to include the header file in your project;

```#include "magiXOR.hpp"```

2. Use the magiXOR macro to encrypt and decrypt at compile-time for **std::string** datatype;

```
    std::string str = magiXOR("Test string").encrypt();
    std::cout << magiXOR("Compile-time encrypted string: ").decrypt() << str << std::endl;

    std::string str2 = magiXOR("L string").decrypt();
    std::cout << magiXOR("Compile-time decrypted string: ").decrypt() << str2 << std::endl;
```

3. Use the magiXOR macro to encrypt and decrypt at compile-time for **const char*** datatype;

```
    const char* str3 = magiXOR("World").encrypt();
    std::cout << magiXOR("Compile-time encrypted const char*: ").decrypt() << str3 << std::endl;

    const char* str4 = magiXOR("Earth").decrypt();
    std::cout << magiXOR("Compile-time decrypted const char*: ").decrypt() << str4 << std::endl;
```

4. Use the magiXOR macro to encrypt and decrypt at compile-time for specific members for **const char*** array datatype;

```
    const char* str5[] = { magiXOR("Test 1").decrypt(), magiXOR("Test 2").decrypt(), magiXOR("Test 3").encrypt(), magiXOR("Test 4").encrypt() };
    std::cout << magiXOR("Compile-time decrypted and encrypted const char* array: ").decrypt() << std::endl;
    for (const char* elem : str5)
    {
        std::cout << elem << std::endl;
    }
```

5. Use the magiXOR macro to encrypt and decrypt at compile-time for **LPCSTR** datatype;

```
    LPCSTR str10 = magiXOR("Night night").encrypt();
    std::wcout << magiXOR("Compile-time encrypted LPCSTR: ").decrypt() << str10 << std::endl;

    LPCSTR str11 = magiXOR("LPCSTR datatype").decrypt();
    std::wcout << magiXOR("Compile-time decrypted LPCSTR: ").decrypt() << str11 << std::endl;
```

6. Use the magiXOR macro to encrypt and decrypt at compile-time for **LPCWSTR** datatype;

```
    LPCWSTR str8 = magiXOR(L"New data type").encrypt();
    std::wcout << magiXOR("Compile-time encrypted LPCWSTR: ").decrypt() << str8 << std::endl;

    LPCWSTR str9 = magiXOR(L"Encrypted data").decrypt();
    std::wcout << magiXOR("Compile-time decrypted LPCWSTR: ").decrypt() << str9 << std::endl;
```

7. Use the magiXOR macro to encrypt and decrypt at compile-time for **LPCTSTR** datatype;

```
    LPCTSTR str6 = magiXOR("New data type").encrypt();
    std::cout << magiXOR("Compile-time encrypted LPCTSTR: ").decrypt() << str6 << std::endl;

    LPCTSTR str7 = magiXOR("Encrypted data").decrypt();
    std::cout << magiXOR("Compile-time decrypted LPCTSTR: ").decrypt() << str7 << std::endl;
```

8. Use the magiXOR macro to encrypt and decrypt at compile-time for **char** datatype;

```
    char c = magiXOR('A').encrypt();
    std::cout << magiXOR("Compile-time encrypted char: ").decrypt() << c << std::endl;

    char c1 = magiXOR('B').decrypt();
    std::cout << magiXOR("Compile-time decrypted char: ").decrypt() << c1 << std::endl;
```

9. Use the magiXOR macro to encrypt and decrypt at compile-time for **std::wstring** datatype;

```
    std::wstring str12 = magiXOR(L"Testing wstring").encrypt();
    std::wcout << magiXOR("Compile-time encrypted wstring: ").decrypt() << str12 << std::endl;

    std::wstring str13 = magiXOR(L"wstring").decrypt();
    std::wcout << magiXOR("Compile-time decrypted wstring: ").decrypt() << str13 << std::endl;
```

10. Use the magiXOR macro to encrypt and decrypt at compile-time for **std::string_view** datatype;

```
    std::string_view str14 = magiXOR("Testing std::string_view").encrypt();
    std::cout << magiXOR("Compile-time encrypted std::string_view: ").decrypt() << str14 << std::endl;

    std::string_view str15 = magiXOR("Decrypted data").decrypt();
    std::cout << magiXOR("Compile-time decrypted std::string_view: ").decrypt() << str15 << std::endl;
```

11. View 'main.cpp' for all supported datatypes.

## Requirements

magiXOR requires a C++ compiler that supports C++11 or later.

## To-do

- [ ] Adding kernel-mode support
- [x] Adding functionality for more data types (check 'main.cpp' to see supported datatypes)
- [ ] Adding functionality to allow for run-time encryption/decryption instead of compile-time - not a priority as I dont see any real usage for this
- [x] Increasing the complexity for the XOR encryption (changed from EBC to CBC to provide stronger encryption)

## Known errors/bugs

* std::wstring_view not supported anymore

* Encrypted values' output in a const char* array is the same as the last encrypted const char*

## Acknowledgments

magiXOR is inspired by the concept of XOR encryption and various online resources on compile-time string encryption.

If you have any suggestions, bug reports, or feature requests, please feel free to open an issue on the GitHub repository.

Enjoy using magiXOR!

## NB!

I updated the code, now it's able to decrypt/encrypt when using iostream specific operators and keep it hidden in the binary. Though it doesn't work for std::wstring_view anymore, but I'll work on that when I got some spare time. 
