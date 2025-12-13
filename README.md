# Contact-Book

**Contact-Book** is a simple Command-Line Interface (CLI) application to manage your contacts. It allows you to add, view, search, update, and delete contacts in a structured and easy-to-use way. This project is built in C and uses file handling to store contact data persistently.

---

## Features

- Add new contacts
- View all contacts
- Search contacts by name or phone number
- Update existing contacts
- Delete contacts
- Persistent storage using a file

---

## Technologies Used

- **Language:** C
- **File Handling:** Binary files for storing contacts
- **CLI:** Command-Line Interface for interaction

---

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/contact-book.git
    ```
2. Navigate to the project directory:
    ```bash
    cd contact-book
    ```
3. Compile the project:
    ```bash
    gcc -o contact-book main.c fileio.c contacts.c utils.c color.c
    ```
4. Run the program:
    ```bash
    ./contact-book
    ```

---

## Usage

1. Run the program.
2. You will see a menu with options like:
    - Add Contact
    - View Contacts
    - Search Contact
    - Update Contact
    - Delete Contact
    - Exit
3. Choose the desired option by entering the corresponding number.
4. Follow the prompts to manage your contacts.

---

## File Structure

Contact-Book/
├── src/
│ ├── main.c
│ ├── contacts.c
│ ├── fileio.c
│ ├── utils.c
│ └── color.c
├── include/
│ ├── contacts.h
│ ├── fileio.h
│ └── utils.h
├── data/
│ └── contacts.db
├── Makefile
└── README.md


---

## Contribution

Contributions are welcome! You can:

- Report bugs
- Suggest features
- Submit pull requests

Please follow standard GitHub workflow for contributing.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Author

**Sazzadur Rahman Saad**  
- Email: sazzad2saad@gmail.com  
- GitHub: [https://github.com/sazzad2saad](https://github.com/sazzad2saad)
