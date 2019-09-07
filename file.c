#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
//creat by abdessalam King 

void usage(char *prog_name, char *filename){
printf("Usage: %s <data to add to %s>\n", prog_name, filename);
exit(0);
}
void fatal(char *);
void *ec_malloc(unsigned int);
int main(int argc, char *argv[]){
    int fb;
    char *buffer, *datafile;
    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(80);
    strcpy(datafile, "/home/abdessalam/Desktop/learn_C/file/fill");
    if(argc < 2)
	usage(argv[0], datafile);
    strcpy(buffer, argv[1]);
    printf("[DEBUG] buffer @ %p:\'%s\'\n",buffer,buffer);
    printf("[DEBUG] datafile @ %p : \'%s\'\n", datafile,datafile);
    strncat(buffer,"\n",1);
    fb = open(datafile, O_WRONLY | O_CREAT | O_APPEND | S_IRUSR |S_IWUSR );
    if(fb == -1)
       fatal("in main() whilr opening file");
    printf("[DRBUG] file descriptor is %d\n", fb);
    if(write(fb, buffer , strlen(buffer)) == -1)
        fatal("in main() while writing buffer to file");
    if(close(fb) == -1)
       fatal("in main () closeing file");
    printf("Note has been saved.\n");
    free(buffer);
    free(datafile);
}

void fatal(char *message){
      char error_message[100];
      strcpy(error_message, "[!!] Fatal Error");
      strncat(error_message, message , 83);
      perror(error_message);
      exit(-1);
}
void *ec_malloc(unsigned int size){

     void *ptr;
     ptr = malloc(size);
     if(ptr == NULL)
        fatal("in ec_malloc on memory allocation");

     return ptr;
}





