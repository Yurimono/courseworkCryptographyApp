#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>

#include "cipherfunctions.h"

class MainWindow : public QWidget {
public:
    MainWindow() {
        setWindowTitle("Шифрування та дешифрування");

        // Елементи інтерфейсу
        languageLabel = new QLabel("Мова:");
        languageComboBox = new QComboBox();
        languageComboBox->addItem("Українська");
        languageComboBox->addItem("Англійська");

        methodLabel = new QLabel("Метод:");
        methodComboBox = new QComboBox();
        methodComboBox->addItem("Шифр Цезаря");
        methodComboBox->addItem("Шифр Віженера");

        operationLabel = new QLabel("Операція:");
        operationComboBox = new QComboBox();
        operationComboBox->addItem("Шифрувати");
        operationComboBox->addItem("Дешифрувати");

        keyLabel = new QLabel("Ключ (число для Цезаря, слово для Віженера):");
        keyLineEdit = new QLineEdit();

        inputTextLabel = new QLabel("Вхідний текст:");
        inputTextEdit = new QTextEdit();

        outputTextLabel = new QLabel("Вихідний текст:");
        outputTextEdit = new QTextEdit();
        outputTextEdit->setReadOnly(true);

        processButton = new QPushButton("Виконати");

        // Розташування елементів
        QHBoxLayout* languageLayout = new QHBoxLayout();
        languageLayout->addWidget(languageLabel);
        languageLayout->addWidget(languageComboBox);

        QHBoxLayout* methodLayout = new QHBoxLayout();
        methodLayout->addWidget(methodLabel);
        methodLayout->addWidget(methodComboBox);

        QHBoxLayout* operationLayout = new QHBoxLayout();
        operationLayout->addWidget(operationLabel);
        operationLayout->addWidget(operationComboBox);

        QVBoxLayout* mainLayout = new QVBoxLayout();
        mainLayout->addLayout(languageLayout);
        mainLayout->addLayout(methodLayout);
        mainLayout->addLayout(operationLayout);
        mainLayout->addWidget(keyLabel);
        mainLayout->addWidget(keyLineEdit);
        mainLayout->addWidget(inputTextLabel);
        mainLayout->addWidget(inputTextEdit);
        mainLayout->addWidget(outputTextLabel);
        mainLayout->addWidget(outputTextEdit);
        mainLayout->addWidget(processButton);

        setLayout(mainLayout);

        // Підключення сигналу кнопки
        connect(processButton, &QPushButton::clicked, this, &MainWindow::processText);
        connect(methodComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::updateKeyLabel);
    }

private slots:
    void processText() {
        QString text = inputTextEdit->toPlainText();
        QString keyText = keyLineEdit->text();
        int methodIndex = methodComboBox->currentIndex();
        int operationIndex = operationComboBox->currentIndex();
        int caesarKey = keyText.toInt();
        QString alphabet;

        if (languageComboBox->currentIndex() == 0) {
            alphabet = "абвгґдеєжзиіїйклмнопрстуфхцчшщьюяАБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
        } else {
            alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        }

        QString result = "";
        if (methodIndex == 0) { // Шифр Цезаря
            if (operationIndex == 0) { // Шифрувати
                result = caesarEncrypt(text, caesarKey, alphabet);
            } else { // Дешифрувати
                result = caesarDecrypt(text, caesarKey, alphabet);
            }
        } else { // Шифр Віженера
            if (operationIndex == 0) { // Шифрувати
                result = vigenereEncrypt(text, keyText, alphabet);
            } else { // Дешифрувати
                result = vigenereDecrypt(text, keyText, alphabet);
            }
        }
        outputTextEdit->setText(result);
    }

    void updateKeyLabel(int index) {
        if (index == 0) {
            keyLabel->setText("Ключ (число):");
        } else {
            keyLabel->setText("Ключ (слово):");
        }
    }

private:
    QLabel* languageLabel;
    QComboBox* languageComboBox;
    QLabel* methodLabel;
    QComboBox* methodComboBox;
    QLabel* operationLabel;
    QComboBox* operationComboBox;
    QLabel* keyLabel;
    QLineEdit* keyLineEdit;
    QLabel* inputTextLabel;
    QTextEdit* inputTextEdit;
    QLabel* outputTextLabel;
    QTextEdit* outputTextEdit;
    QPushButton* processButton;
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}