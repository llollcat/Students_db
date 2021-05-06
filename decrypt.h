#ifndef UNTITLED_DECRYPT_H
#define UNTITLED_DECRYPT_H
#include "cryptopp/cryptlib.h"
#include "cryptopp/default.h"
#include "cryptopp/hex.h"
// принимает зашифрованную строку и кодовое слово для расшифровки.
std::string decrypt(std::string info, std::string passwd) {
    std::string output;

    CryptoPP::StringSource ss1(info, true, new CryptoPP::HexDecoder(
            new CryptoPP::DefaultDecryptorWithMAC((CryptoPP::byte *) passwd.data(), passwd.size(),
                                                  new CryptoPP::StringSink(output))));

    return output;
}


#endif
