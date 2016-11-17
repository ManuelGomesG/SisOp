#include "queues.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


void list(const char *path, dQhead*);
void list1(const char* path);