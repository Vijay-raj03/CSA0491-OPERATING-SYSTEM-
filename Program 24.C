#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    char *data = "Hi! This is Nithish";

    fd = open("example.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("Error writing to file");
        return 1;
    }

    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("Error seeking in file");
        return 1;
    }

    char buffer[strlen(data)];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Error reading from file");
        return 1;
    }
    printf("Read from file: %s\n", buffer);

    if (close(fd) == -1) {
        perror("Error closing file");
        return 1;
    }

    if (unlink("example.txt") == -1) {
        perror("Error removing file");
        return 1;
    }

    return 0;
}
