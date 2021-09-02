# Function-Hooking-

Basicly in these two script what we are doing is something called function hooking. With the file malicious.c basicly we are going to affect the LD_PRELOAD in to affect the write function so that instead of lets say every time you try loading "hello world" it will load "hacked 12743" and with hide.c what is goign to happen is that you can hide the malicious file from the ls command basicly we simply break from the loop and return the value as obtained from the original function. However, if we have a match, we iterate one more time, thereby effectively skipping over our file a return pointer to the dirent structure pertaining to the next file in the directory.

Here is how to compile each one 

#Malicious.c
gcc -ldl malicious.c -fPIC -shared -D_GNU_SOURCE -o malicious.so 
gcc malicious.c -fPIC -shared -D_GNU_SOURCE -o malicious.so -ldl

#hide.c
gcc hide.c -fPIC -shared -D_GNU_SOURCE -o hidefile.so -ldl
