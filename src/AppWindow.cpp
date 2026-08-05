#include <QWidget>          // Base class for all UI elements in Qt
#include <QVBoxLayout>      // Layout manager for vertical arrangement of widgets
#include <QLineEdit>        // Single-line text input field
#include <QComboBox>        // Drop-down selection box
#include <QPushButton>      // Clickable button
#include <QLabel>           // Display text labels
#include <QGroupBox>        // Group container with a title
#include <QMessageBox>      // Popup message dialogs (errors/info)
#include <QFileDialog>      // File open/save dialog
#include <QFile>            // File handling (read/write)
#include <QTextStream>      // Stream-based text input/output
#include "CipherFactory.h"  // Our custom class factory for ciphers


class AppWindow : public QWidget {
public:
    AppWindow(QWidget *parent = nullptr) : QWidget(parent) {
        auto *mainLayout = new QVBoxLayout(this);

        // Title
        auto *title = new QLabel("Encryption Suite", this);
        title->setObjectName("titleLabel");
        title->setAlignment(Qt::AlignCenter);
        mainLayout->addWidget(title);

        // ------- Input Section -------
        auto *inputGroup = new QGroupBox("Input Text", this);
        auto *inputLayout = new QVBoxLayout(inputGroup);
        input = new QLineEdit(this);
        inputLayout->addWidget(input);
        mainLayout->addWidget(inputGroup);

        // ------- Cipher Section -------
        auto *cipherGroup = new QGroupBox("Cipher Settings", this);
        auto *cipherLayout = new QVBoxLayout(cipherGroup);

        auto *cipherLabel = new QLabel("Select Cipher:", this);
        cipherSelect = new QComboBox(this);
        cipherSelect->addItem("Caesar");
        cipherSelect->addItem("Atbash");
        cipherSelect->addItem("Vigenere");
        cipherSelect->addItem("XOR");
        cipherSelect->addItem("ColumnarTransposition");
        cipherSelect->addItem("SimpleSubstitution");

        auto *keyLabel = new QLabel("Enter Key (if required):", this);
        keyInput = new QLineEdit(this);

        auto *encryptBtn = new QPushButton("Encrypt", this);
        auto *decryptBtn = new QPushButton("Decrypt", this);

        cipherLayout->addWidget(cipherLabel);
        cipherLayout->addWidget(cipherSelect);
        cipherLayout->addWidget(keyLabel);
        cipherLayout->addWidget(keyInput);
        cipherLayout->addWidget(encryptBtn);
        cipherLayout->addWidget(decryptBtn);

        mainLayout->addWidget(cipherGroup);

        // ------- Result Section -------
        auto *resultGroup = new QGroupBox("Result", this);
        auto *resultLayout = new QVBoxLayout(resultGroup);
        result = new QLabel("", this);
        result->setObjectName("resultLabel");
        result->setWordWrap(true);
        resultLayout->addWidget(result);
        mainLayout->addWidget(resultGroup);

        // ------- File I/O -------
        auto *saveBtn = new QPushButton("Save", this);
        auto *loadBtn = new QPushButton("Load", this);
        mainLayout->addWidget(saveBtn);
        mainLayout->addWidget(loadBtn);

        // Connect
        connect(encryptBtn, &QPushButton::clicked, this, &AppWindow::doEncrypt);
        connect(decryptBtn, &QPushButton::clicked, this, &AppWindow::doDecrypt);
        connect(saveBtn, &QPushButton::clicked, this, &AppWindow::saveResult);
        connect(loadBtn, &QPushButton::clicked, this, &AppWindow::loadInput);
    }

private:
    QLineEdit *input;
    QLineEdit *keyInput;
    QComboBox *cipherSelect;
    QLabel *result;

    void doEncrypt() { //member function
        try {
            auto cipher = CipherFactory::create(cipherSelect->currentText().toStdString(), //QT->C++
                                                keyInput->text().toStdString());
            std::string res = cipher->encrypt(input->text().toStdString(), "");
            result->setText(QString::fromStdString(res)); //Display the results
        } catch (std::exception &e) {
            QMessageBox::warning(this, "Error", e.what());
        }
    }

    void doDecrypt() {
        try {
            auto cipher = CipherFactory::create(cipherSelect->currentText().toStdString(),
                                                keyInput->text().toStdString());
            std::string res = cipher->decrypt(input->text().toStdString(), "");
            result->setText(QString::fromStdString(res));
        } catch (std::exception &e) {
            QMessageBox::warning(this, "Error", e.what());
        }
    }

    void saveResult() {
        QString fileName = QFileDialog::getSaveFileName(this, "Save Result", "", "Text Files (*.txt)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);  //text stream interface
                out << result->text();
                QMessageBox::information(this, "Saved", "Result saved successfully!");
            }
        }
    }

    void loadInput() {
        QString fileName = QFileDialog::getOpenFileName(this, "Load Text", "", "Text Files (*.txt)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                input->setText(in.readAll());
                QMessageBox::information(this, "Loaded", "Text loaded successfully!");
            }
        }
    }
};
