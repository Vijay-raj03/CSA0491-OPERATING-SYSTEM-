#include <stdio.h>
#include <unistd.h>
int main(void) {
  pid_t child_pid;
  pid_t my_pid;
  pid_t parent_pid;
  child_pid = fork();
  if (child_pid == 0) {
    my_pid = getpid();
    parent_pid = getppid();
    printf("I am the child process.\n");
    printf("My PID is %d.\n", my_pid);
    printf("My parent's PID is %d.\n", parent_pid);
  } else {
    my_pid = getpid();
    printf("I am the parent process.\n");
    printf("My PID is %d.\n", my_pid);
    printf("My child's PID is %d.\n", child_pid);
  }
  return 0;
}
