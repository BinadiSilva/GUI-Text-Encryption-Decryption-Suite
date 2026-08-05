#include <QApplication>
#include "AppWindow.cpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    app.setStyleSheet(R"(
        QWidget {
            background-color: #f5f7fa;
            font-family: 'Segoe UI', sans-serif;
            font-size: 14px;
            color: #2c3e50;
        }
        QLabel {
            font-size: 14px;
        }
        QLabel#titleLabel {
            font-size: 22px;
            font-weight: bold;
            color: #34495e;
            margin: 10px;
        }
        QGroupBox {
            font-weight: bold;
            border: 1px solid #dcdcdc;
            border-radius: 6px;
            margin-top: 10px;
            padding: 8px;
            background: #ffffff;
        }
        QLineEdit {
            background-color: #ffffff;
            border: 1px solid #bdc3c7;
            border-radius: 6px;
            padding: 6px;
        }
        QComboBox {
            background-color: #ffffff;
            border: 1px solid #bdc3c7;
            border-radius: 6px;
            padding: 6px;
        }
        QPushButton {
            background-color: #3498db;
            color: white;
            border: none;
            border-radius: 6px;
            padding: 8px 14px;
            font-size: 14px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #2980b9;
        }
        QPushButton:pressed {
            background-color: #1f6391;
        }
        QLabel#resultLabel {
            background-color: #ecf0f1;
            border: 1px solid #bdc3c7;
            border-radius: 6px;
            padding: 10px;
            font-size: 15px;
            min-height: 50px;
        }
    )");

    AppWindow window;
    window.setWindowTitle("Encryption Suite");
    window.resize(500, 600);
    window.show();

    return app.exec();
}
