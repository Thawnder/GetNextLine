# get_next_line (125/100)

**get_next_line** is a project that requires us to implement a function that reads a line from a file descriptor. This function is useful for parsing text files line by line.

## Features
- Custom implementation of the get_next_line function.
- Supports reading from multiple file descriptors simultaneously. (bonus)
- Handles dynamic memory allocation and buffer management efficiently.

## Usage

This project is included in my Libft, please refer to my Libft page (https://github.com/Thawnder/Libft) for proper implementation in your code.

## Example
<pre>
#include "get_next_line.h"
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;
    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
</pre>

## Notes
- The get_next_line function reads from a file descriptor until a newline character or EOF is encountered.
- It dynamically allocates memory for each line read, so remember to free the memory when done using it.
