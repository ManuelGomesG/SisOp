#include "listing.h"



#define SEPARATOR "/"


 void list(const char* path, dQhead* q){
    DIR *directory;
    struct dirent *filei;
    struct stat stats;
    directory = opendir(path);
    int size = 0;
    if (directory != NULL)  
    {
        while ((filei=readdir(directory))!=NULL){
            stat(filei->d_name, &stats);  
            //printf("SIZE : %d\n",  size);
            if (S_ISDIR(stats.st_mode)) {
                char *buf = malloc(strlen(path)+strlen(filei->d_name)+2);
                strcpy(buf,path);
                strcat(buf,"/");
                strcat(buf,filei->d_name);
                stat(buf, &stats);
                if (S_ISDIR(stats.st_mode)) {
                    if (strcmp(filei->d_name,".")!=0 && (strcmp(filei->d_name,"..")!=0)) {
                        addToQ(q,createD(buf));
                    }
                free(buf);
                }  
            }
            else
                size = size + stats.st_blocks;
        }
        closedir(directory);
    }
    else {
        perror(NULL);    
    }
}

void list1(const char* path){

    DIR *directory;
    struct dirent *filei;
    struct stat stats;
    directory = opendir(path);
    int size = 0;
    //int i;
    if (directory != NULL)  
    {
        while ((filei=readdir(directory))!=NULL){
            stat(filei->d_name, &stats);
            //i = stats.st_blocks;   
            //printf(" %s   ,   %d \n", filei->d_name, i); 
            //printf("SIZE : %d\n",  size);
            if (S_ISDIR(stats.st_mode)){
                char *buf = malloc(strlen(path)+strlen(filei->d_name)+2);
                strcpy(buf,path);
                strcat(buf,"/");
                strcat(buf,filei->d_name);
                stat(buf, &stats);
                if (S_ISDIR(stats.st_mode)) {
                    if (strcmp(filei->d_name,".")!=0 && (strcmp(filei->d_name,"..")!=0)) {
                        list1(buf);
                    }
                free(buf);
                }
            }
            else
                size = size + stats.st_blocks;
        }
        printf(" %d       %s\n ", size, path);
        closedir(directory);
    }
    else{
        perror(NULL);    
    }
}