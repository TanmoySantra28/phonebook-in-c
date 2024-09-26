# Phonebook Application in C based on File Handling

This is a simple console-based phonebook application implemented in C. The program allows you to perform basic operations such as adding, listing, searching, updating, and removing contact information. It uses a binary file (`phonebook_db`) to store the contact details.

## Features

- **Add a new contact**: Add a person's name, country code, phone number, gender, and email to the phonebook.
- **List all contacts**: Display all saved contacts in a tabular format.
- **Search for a contact**: Search for a person by their phone number.
- **Update contact information**: Modify the details of an existing contact.
- **Delete a contact**: Remove a contact by their phone number.
- **Delete all contacts**: Remove all contacts from the phonebook.
- **Persistent storage**: All contacts are saved in a binary file (`phonebook_db`), ensuring data persistence across sessions.

## Requirements

- C compiler (GCC or any other standard C compiler)
- A terminal or command prompt for running the application

## Compilation

You can compile the program using GCC with the following command:

```bash
gcc phonebook-in-c.c -o phonebook
```

## Usage

### After compiling, run the executable:

```bash
./phonebook
```

### A menu will appear with the following options:7

```bash
1) Show records
2) Add person
3) Search person details
4) Remove person
5) Update person
6) Delete all contacts
7) Exit Phonebook
```

## Example of Adding a Contact

![image](https://github.com/user-attachments/assets/e605ee34-4060-4e08-a5c3-5a66fc3497c2)

## Example of Showing the Contacts

![image](https://github.com/user-attachments/assets/6b15abb8-4ce3-4664-8f18-67c66b6986c1)

## Example of Searching for a Contact

![image](https://github.com/user-attachments/assets/9c9fbbca-5874-4da5-8159-b3a6b3d3e4dc)

## File Storage

The program stores all the contacts in a binary file called phonebook_db. Make sure this file is present in the same directory as the executable. The program will create the file if it does not exist.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contributing

Feel free to fork this repository and submit pull requests if you want to improve the code or add new features.

