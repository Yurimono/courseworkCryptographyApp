#include "cipherfunctions.h"
#include <QString>

QString caesarEncrypt(const QString& text, int key, const QString& alphabet) {
    QString result = "";
    int n = alphabet.length();
    for (QChar c : text) {
        int index = alphabet.indexOf(c);
        if (index != -1) {
            int shiftedIndex = (index + key) % n;
            result += alphabet[shiftedIndex];
        } else {
            result += c;
        }
    }
    return result;
}

QString caesarDecrypt(const QString& text, int key, const QString& alphabet) {
    return caesarEncrypt(text, alphabet.length() - (key % alphabet.length()), alphabet);
}