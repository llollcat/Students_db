#ifndef UNTITLED_ENCRYPT_H
#define UNTITLED_ENCRYPT_H
#include "cryptopp/cryptlib.h"
#include "cryptopp/default.h"
#include "cryptopp/hex.h"
// принимает строку для шифрования и кодовое слово для шифровки.
std::string encrypt(std::string info, std::string passwd) {
    std::string output;

    CryptoPP::StringSource ss1(info, true,
                               new CryptoPP::DefaultEncryptorWithMAC((CryptoPP::byte *) passwd.data(), passwd.size(),
                                                                     new CryptoPP::HexEncoder(
                                                                             new CryptoPP::StringSink(output))));

    return output;
}


#endif
