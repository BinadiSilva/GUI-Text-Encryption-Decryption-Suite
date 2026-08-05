# 🔐 GUI-based Text Encryption & Decryption Suite
![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=c%2B%2B)
![Qt](https://img.shields.io/badge/Qt-Framework-green?logo=qt)
![CMake](https://img.shields.io/badge/CMake-Build%20System-blue?logo=cmake)
![License](https://img.shields.io/badge/License-Educational-lightgrey)

A desktop application developed in **C++** using the **Qt Framework** that enables users to securely encrypt and decrypt text using six classical cryptographic algorithms through an intuitive graphical user interface (GUI).

This project was developed as part of a university mini project to demonstrate **Object-Oriented Programming (OOP)** principles, software design, file handling, and classical cryptography.


## 📅 Project Duration

**July 2025 – August 2025**


## ✨ Features

- Encrypt and decrypt text messages
- Interactive desktop GUI built with Qt
- Save and load text files
- Input validation with user-friendly error messages
- Modular and reusable object-oriented design
- Support for six classical cryptographic algorithms


## 🔐 Supported Ciphers

| Cipher | Description |
|---------|-------------|
| Caesar Cipher | Encrypts text using a configurable shift value |
| Atbash Cipher | Performs letter substitution using the reversed alphabet |
| Vigenère Cipher | Uses a keyword to perform polyalphabetic encryption |
| Simple Substitution Cipher | Encrypts text using a custom 26-letter substitution key |
| Columnar Transposition Cipher | Rearranges characters into columns based on a user-provided key |
| XOR Cipher | Applies bitwise XOR encryption using a numeric or character key |


## 🛠️ Technologies Used

- **Programming Language:** C++
- **Framework:** Qt
- **Build System:** CMake
- **Version Control:** Git & GitHub


## 🧩 Object-Oriented Programming Concepts

This project demonstrates several fundamental OOP concepts:

- Encapsulation
- Inheritance
- Polymorphism
- Abstraction
- Composition

A common abstract `Cipher` base class was used, with each encryption algorithm implemented as a derived class, providing a clean and extensible architecture.


## 📂 Project Structure

```text
GUI-Text-Encryption-Decryption-Suite
│
├── include/          # Header files
├── src/              # Source files
├── CMakeLists.txt    # CMake configuration
├── README.md
└── .gitignore
```


## 🚀 Getting Started

### Prerequisites

- Qt Creator
- CMake
- C++ Compiler (GCC, Clang, or MSVC)

### Installation

Clone the repository:

```bash
git clone https://github.com/BinadiSilva/GUI-Text-Encryption-Decryption-Suite.git
```

Navigate to the project:

```bash
cd GUI-Text-Encryption-Decryption-Suite
```

Open the project in **Qt Creator**, configure the build kit, and build and run the application.


## 🎯 Learning Outcomes

This project helped strengthen my knowledge in:

- Object-Oriented Programming using C++
- Desktop application development with Qt
- Classical cryptographic algorithms
- File handling in C++
- GUI design and event-driven programming
- Software architecture and modular design
- Version control using Git and GitHub


## 🔮 Future Improvements

- Support modern encryption algorithms (AES, RSA)
- Improve user interface and user experience
- Add drag-and-drop file encryption
- Export encrypted files in multiple formats
- Dark mode support
- Multi-language interface


## 👩‍💻 Author

**Binadi Silva**

- GitHub: https://github.com/BinadiSilva
- LinkedIn: https://www.linkedin.com/in/binadi-silva-2916a82b5/


## 📄 License

This project is shared for educational and portfolio purposes.
