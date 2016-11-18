#include "listing.h"



#define SEPARATOR "/"


 childAnswer* list(char* path){
    DIR *directory;
    struct dirent *filei;
    struct stat stats;
    directory = opendir(path);
    int size = 0;
    dQhead* q = createDQ();
    if (directory != NULL)  
    {
        while ((filei=readdir(directory))!=NULL){ 
            //printf("SIZE : %d\n",  size);
            char *buf = malloc(strlen(path)+strlen(filei->d_name)+2);
            strcpy(buf,path);
            strcat(buf,"/");
            strcat(buf,filei->d_name);
            stat(buf, &stats);
            if (S_ISDIR(stats.st_mode)) {
                if (S_ISDIR(stats.st_mode)) {
                    if (strcmp(filei->d_name,".")!=0 && (strcmp(filei->d_name,"..")!=0)) {
                        addToQ(q,createD(buf));
                        //printf(" Directory : %s\n",buf);

                    }
                }  
            }
            else{
                //printf(" Non directory : %s SIZE: %d\n",buf, stats.st_blocks);
                size = size + stats.st_blocks;
            }
            
            free(buf);
        }
        childAnswer* answer = createCA(path, size, q);
 
        closedir(directory);
        return answer;
    }
    else {
        perror(NULL);    
    }
    return NULL;
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

