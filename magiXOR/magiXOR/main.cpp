#include <iostream>
#include <Windows.h>
#include "magiXOR.hpp"

int main()
{
    // Compile-time encryption for std::string datatype
    std::string str = magiXOR("Test string abc").encrypt();
    std::cout << magiXOR("Encrypted string: ").decrypt() << str << std::endl;

    // Compile-time decryption for std::string datatype
    std::string str2 = magiXOR("L string").decrypt();
    std::cout << magiXOR("Decrypted string: ").decrypt() << str2 << std::endl;

    // Compile-time encryption for const char* datatype
    const char* str3 = magiXOR("World").encrypt();
    std::cout << magiXOR("Encrypted const char* : ").decrypt() << str3 << std::endl;

    // Compile-time encryption for const char* datatype
    const char* str99 = magiXOR("SkadoodleMan").encrypt();
    std::cout << magiXOR("Encrypted const char* : ").decrypt() << str99 << std::endl;

    // Compile-time decryption for const char* datatype
    const char* str4 = magiXOR("Earth").decrypt();
    std::cout << magiXOR("Decrypted const char*: ").decrypt() << str4 << std::endl;

    // Compile-time encryption for const char* array datatype
    const char* str5[] = {
        magiXOR("Test 1").encrypt(),
        magiXOR("Test 2").decrypt(),
        magiXOR("Boss").decrypt(),
        magiXOR("NPC").encrypt()
    };
    std::cout << magiXOR("Decrypted and encrypted const char* array: ").decrypt() << std::endl;

    for (const char* elem : str5)
    {
        std::cout << elem << std::endl;
    }

    // Compile-time encryption for LPCTSTR datatype
    LPCTSTR str6 = magiXOR("Other less abc").encrypt();
    std::cout << magiXOR("Encrypted LPCTSTR: ").decrypt() << str6 << std::endl;

    // Compile-time decryption for LPCTSTR datatype
    LPCTSTR str7 = magiXOR("Encrypted data").decrypt();
    std::cout << magiXOR("Decrypted LPCTSTR: ").decrypt() << str7 << std::endl;

    // Compile-time encryption for char datatype
    char c = magiXOR('A').encrypt();
    std::cout << magiXOR("Encrypted char: ").decrypt() << c << std::endl;

    // Compile-time encryption for char datatype
    char c1 = magiXOR('B').decrypt();
    std::cout << magiXOR("Decrypted char: ").decrypt() << c1 << std::endl;

    // Compile-time encryption for LPCWSTR datatype
    LPCWSTR str8 = magiXOR(L"New data type").encrypt();
    std::wcout << magiXOR("Encrypted LPCWSTR: ").decrypt() << str8 << std::endl;

    // Compile-time decryption for LPCWSTR datatype
    LPCWSTR str9 = magiXOR(L"Encrypted data test").decrypt();
    std::wcout << magiXOR("Decrypted LPCWSTR: ").decrypt() << str9 << std::endl;

    // Compile-time encryption for LPCSTR datatype
    LPCSTR str10 = magiXOR("Night night").encrypt();
    std::wcout << magiXOR("Encrypted LPCSTR: ").decrypt() << str10 << std::endl;

    // Compile-time encryption for LPCSTR datatype
    LPCSTR str11 = magiXOR("LPCSTR datatype").decrypt();
    std::wcout << magiXOR("Decrypted LPCSTR: ").decrypt() << str11 << std::endl;

    // Compile-time encryption for std::wstring datatype
    std::wstring str12 = magiXOR(L"Testing wstring").encrypt();
    std::wcout << magiXOR("Encrypted wstring: ").decrypt() << str12 << std::endl;

    // Compile-time decryption for std::wstring datatype
    std::wstring str13 = magiXOR(L"wstring").decrypt();
    std::wcout << magiXOR("Decrypted wstring: ").decrypt() << str13 << std::endl;

    // Compile-time encryption for std::string_view datatype
    std::string_view str14 = magiXOR("Testing std::string_view").encrypt();
    std::cout << magiXOR("Encrypted string_view: ").decrypt() << str14 << std::endl;

    // Compile-time decryption for std::string_view datatype
    std::string_view str15 = magiXOR("Decrypted data").decrypt();
    std::cout << magiXOR("Decrypted std::string_view: ").decrypt() << str15 << std::endl;
    
    char16_t c2 = magiXOR('X').encrypt();
    std::cout << "Encrypted char16_t: ";
    std::cout.write(reinterpret_cast<const char*>(&c2), sizeof(c2));
    std::cout << std::endl;

    char16_t c3 = magiXOR('Y').decrypt();
    std::cout << "Decrypted char16_t: ";
    std::cout.write(reinterpret_cast<const char*>(&c3), sizeof(c3));
    std::cout << std::endl;

    char32_t c4 = magiXOR('Z').encrypt();
    std::cout << "Encrypted char32_t: ";
    std::cout.write(reinterpret_cast<const char*>(&c4), sizeof(c4));
    std::cout << std::endl;

    char32_t c5 = magiXOR('$').decrypt();
    std::cout << "Decrypted char32_t: ";
    std::cout.write(reinterpret_cast<const char*>(&c5), sizeof(c5));
    std::cout << std::endl;

    // Working on support for u16string and u32string
    //std::u16string str16 = magiXOR(u"Mega zzZzzz").encrypt();
    //std::cout << "Encrypted u16string: ";
    //std::cout.write(reinterpret_cast<const char*>(&str16), sizeof(str16));
    //std::cout << std::endl;

    //std::u16string str17 = magiXOR(u"Lol").encrypt();
    //std::cout << "Decrypted u16string: ";
    //std::cout.write(reinterpret_cast<const char*>(&str17), sizeof(str17));
    //std::cout << std::endl;

    //std::u32string str18 = magiXOR(U"Mega mind").encrypt();
    //std::cout << "Encrypted u32string: ";
    //std::cout.write(reinterpret_cast<const char*>(&str18), sizeof(str18));
    //std::cout << std::endl;

    //std::u32string str19 = magiXOR(U"Sleepy Joe").decrypt();
    //std::cout << "Decrypted u32string: ";
    //std::cout.write(reinterpret_cast<const char*>(&str19), sizeof(str19));
    //std::cout << std::endl;

    std::basic_string str20 = magiXOR("Donald Duck").encrypt();
    std::cout << magiXOR("Encrypted basic_string: ").decrypt() << str20 << std::endl;

    std::basic_string str21 = magiXOR("bOb").decrypt();
    std::cout << magiXOR("Decrypted basic_string: ").decrypt() << str21 << std::endl;

    return 0;
}
