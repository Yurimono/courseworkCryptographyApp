#include "cipherfunctions.h"
#include <QString>

QString vigenereEncrypt(const QString& text, const QString& key, const QString& alphabet) {
    QString result = "";
    int keyIndex = 0;
    int n = alphabet.length();
    for (QChar c : text) {
        int textIndex = alphabet.indexOf(c);
        if (textIndex != -1) {
            int keyCharIndex = alphabet.indexOf(key[keyIndex % key.length()]);
            int encryptedIndex = (textIndex + keyCharIndex) % n;
            result += alphabet[encryptedIndex];
            keyIndex++;
        } else {
            result += c;
        }
    }
    return result;
}

QString vigenereDecrypt(const QString& text, const QString& key, const QString& alphabet) {
    QString result = "";
    int keyIndex = 0;
    int n = alphabet.length();
    for (QChar c : text) {
        int textIndex = alphabet.indexOf(c);
        if (textIndex != -1) {
            int keyCharIndex = alphabet.indexOf(key[keyIndex % key.length()]);
            int decryptedIndex = (textIndex - keyCharIndex + n) % n;
            result += alphabet[decryptedIndex];
            keyIndex++;
        } else {
            result += c;
        }
    }
    return result;
}