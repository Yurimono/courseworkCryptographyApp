#ifndef CIPHERFUNCTIONS_H
#define CIPHERFUNCTIONS_H

#include <QString>

QString caesarEncrypt(const QString& text, int key, const QString& alphabet);
QString caesarDecrypt(const QString& text, int key, const QString& alphabet);
QString vigenereEncrypt(const QString& text, const QString& key, const QString& alphabet);
QString vigenereDecrypt(const QString& text, const QString& key, const QString& alphabet);

#endif // CIPHERFUNCTIONS_H