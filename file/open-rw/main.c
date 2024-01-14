#include<stdio.h> 
#include<string.h> 
#include<unistd.h> 
#include<fcntl.h> 
  
int main (void) 
{
    int fd;
    int numb_read, numb_write;
    char buf1[12] = "hello world\n"; 
  
    // assume foobar.txt is already created 
    fd = open("hello.txt", O_RDWR | O_CREAT , 0667);         
    if (-1 == fd) { 
	    printf("open() hello.txt failed\n");
    }      

    numb_write = write(fd, buf1, strlen(buf1));
    printf("Write %d bytes to hello.txt\n", numb_write);
  
    lseek(fd, 0, SEEK_SET);
    write(fd, "ABC", strlen("ABC")); 
    
    close(fd); 
  
    return 0; 
} 
