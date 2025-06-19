# 📄 get_next_line – Reading One Line at a Time in C

This project is part of the 42 school curriculum. It challenges you to implement `get_next_line()`, a function that reads a line from a file descriptor one call at a time. It emphasizes understanding static variables, memory handling, and buffer management in C.

---

## 🎯 Project Goal

Implement a function:
```c
char *get_next_line(int fd);
```
that reads and returns one line from a given file descriptor each time it is called. The returned line includes the newline character \n if one is present before EOF.

## ⚙️ Features
- Read a file or standard input line-by-line.

- Maintain reading state between calls using static variables.

- Efficient buffer handling using a user-defined BUFFER_SIZE.

### Returns:

- The next line (including \n)

- NULL on EOF or error

## 🛠 Compilation
You can compile with a custom buffer size using:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```
Replace 42 with any size to test different buffer behaviors.

## 📁 Required files:

- get_next_line.c

- get_next_line_utils.c

- get_next_line.h

Allowed functions: read, malloc, free

Must work with both files and standard input

Must work for BUFFER_SIZE values like 1, 32, 9999, etc.

Must be Norm-compliant and memory-leak free

## 🔒 Forbidden
❌ lseek()

❌ Global variables

❌ External libraries (including libft)

❌ Reading entire file before returning first line

## 📁 Example Usage
```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```
Thanks for checking out this project! 🧠💻
