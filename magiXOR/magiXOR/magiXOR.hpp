// 
// magiXOR by REVRBE
// 
// Compile-time XOR string encryption using CBC
// Dynamic key generation using __TIME__ macro.
// Simple to use
//
#include <iostream>
#include <string>
#include <cstring>

namespace magiObfuscation {
    // Function pointer type for obfuscated key generation
    typedef wchar_t (*GenerateKeyFunc)();

    namespace {
        // Obfuscation for generating secret key
        constexpr wchar_t GenerateSecretKey()
        {
            constexpr char time[] = __TIME__;
            wchar_t secretKey = time[1] + time[3] + time[6]; 

            return secretKey;
        }

        constexpr wchar_t GenerateObfuscationKey()
        {
            constexpr char time[] = __TIME__;
            wchar_t obfuscationKey = time[4] + time[5] / time[2] / time[0]; 

            return obfuscationKey;
        }
    }

    constexpr wchar_t obfuscatedSecretKey()
    {
        return GenerateSecretKey();
    }

    constexpr wchar_t obfuscatedObfuscationKey()
    {
        return GenerateObfuscationKey();
    }
}

// Compile-time XOR encryption for a string literal
template <typename T, std::size_t N>
class magiXOR
{
public:
    constexpr magiXOR(const T(&str)[N])
        : secretKey(magiObfuscation::obfuscatedSecretKey()), obfuscationKey(magiObfuscation::obfuscatedObfuscationKey())
    {
        encryptString(str);
    }

    T* decrypt() const
    {
        T* decryptedStr = new T[N];
        T previousBlock = secretKey;

        for (std::size_t i = 0; i < N - 1; ++i)
        {
            decryptedStr[i] = decryptChar(encryptedStr[i]) ^ previousBlock;
            previousBlock = encryptedStr[i] ^ obfuscationKey;
        }

        decryptedStr[N - 1] = '\0';
        return decryptedStr;
    }

    const T* encrypt() const
    {
        return encryptedStr;
    }

    // Overload the << operator to handle printing of encrypted or decrypted strings
    friend std::ostream& operator<<(std::ostream& os, const magiXOR<T, N>& obj)
    {
        os << obj.decrypt();
        return os;
    }

private:
    const wchar_t secretKey;
    const wchar_t obfuscationKey;
    T encryptedStr[N];

    void encryptString(const T(&str)[N])
    {
        T previousBlock = secretKey;

        for (std::size_t i = 0; i < N - 1; ++i)
        {
            T encryptedChar = encryptChar(str[i] ^ previousBlock);
            encryptedStr[i] = encryptedChar;
            previousBlock = encryptedChar ^ obfuscationKey;
        }

        encryptedStr[N - 1] = '\0';
    }

    constexpr T encryptChar(const T ch) const
    {
        return ch ^ obfuscationKey;
    }

    constexpr T decryptChar(const T ch) const
    {
        return ch ^ obfuscationKey;
    }
};

// Specialization for char
template <>
class magiXOR<char, 2>
{
public:
    constexpr magiXOR(const char ch)
        : secretKey(magiObfuscation::obfuscatedSecretKey()), obfuscationKey(magiObfuscation::obfuscatedObfuscationKey()), encryptedChar(encryptChar(ch))
    {}

    char decrypt() const
    {
        return decryptChar(encryptedChar);
    }

    const char encrypt() const
    {
        return encryptedChar;
    }

    // Overload the << operator to handle printing of encrypted or decrypted characters
    friend std::ostream& operator<<(std::ostream& os, const magiXOR<char, 2>& obj)
    {
        os << obj.decrypt();
        return os;
    }

private:
    const wchar_t secretKey;
    const wchar_t obfuscationKey;
    const char encryptedChar;

    constexpr char encryptChar(const char ch) const
    {
        return ch ^ obfuscationKey;
    }

    constexpr char decryptChar(const char ch) const
    {
        return ch ^ obfuscationKey;
    }
};

// Specialization for wchar_t
template <>
class magiXOR<wchar_t, 2>
{
public:
    constexpr magiXOR(const wchar_t ch)
        : secretKey(magiObfuscation::obfuscatedSecretKey()), obfuscationKey(magiObfuscation::obfuscatedObfuscationKey()), encryptedChar(encryptChar(ch))
    {}

    wchar_t decrypt() const
    {
        return decryptChar(encryptedChar);
    }

    const wchar_t encrypt() const
    {
        return encryptedChar;
    }

    // Overload the << operator to handle printing of encrypted or decrypted wide characters
    friend std::wostream& operator<<(std::wostream& os, const magiXOR<wchar_t, 2>& obj)
    {
        os << obj.decrypt();
        return os;
    }

private:
    const wchar_t secretKey;
    const wchar_t obfuscationKey;
    const wchar_t encryptedChar;

    constexpr wchar_t encryptChar(const wchar_t ch) const
    {
        return ch ^ obfuscationKey;
    }

    constexpr wchar_t decryptChar(const wchar_t ch) const
    {
        return ch ^ obfuscationKey;
    }
};

// Overload for const char* to support string literals
template <typename T, std::size_t N>
magiXOR(const T(&)[N]) -> magiXOR<T, N>;

// Overload for const wchar_t to support wide char literals
magiXOR(const wchar_t)->magiXOR<wchar_t, 2>;

// Overload for const char to support char literals
magiXOR(const char)->magiXOR<char, 2>;

// MagiXOR macro for simplified encryption
#define magiXOR(str) magiXOR(str)

// Decrypt an array of encrypted strings
template <std::size_t N>
const char** decryptArray(const char* (&arr)[N])
{
    const char** decryptedArray = new const char* [N];
    const wchar_t* previousBlock = magiObfuscation::obfuscatedSecretKey();

    for (std::size_t i = 0; i < N; ++i)
    {
        magiXOR<char, 2> magiObj(arr[i]);
        const char* encryptedStr = magiObj.encrypt();
        std::size_t strLength = std::strlen(encryptedStr);
        char* decryptedStr = new char[strLength + 1];
        decryptedStr[strLength] = '\0';

        for (std::size_t j = 0; j < strLength; ++j)
        {
            decryptedStr[j] = magiObj.decrypt() ^ previousBlock[j % 2];
            previousBlock[j % 2] = encryptedStr[j];
        }

        decryptedArray[i] = decryptedStr;
    }

    return decryptedArray;
}

// MIT License
// 
// Copyright (c) 2023 REVRBE
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
