#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void do_ls(char[]);
void show_stat_info(char *, struct stat *);
void do_A(char[]);
int compareStr(const void *pa, const void *pb);
int compareStrReverse(const void *pa, const void *pb);
void do_s(char[]);
void do_r(char[]);


main(int ac, char *av[]){
    int inputs, parseA = 0, parseS = 0, parseR = 0;

    while((inputs = getopt(ac, av, "asr")) != -1)
    {
        switch(inputs)
        {
            case 'a':
                parseA = 1;
                if(ac==2)
                     do_A(".");
                 else if(ac>2){
                      while(--ac){
                        printf("%s:\t", *++av);
                         do_A(*av);        }
                break;
            case 'r':
                parseR = 1;
                break;
            case 's':
                parseS = 1;
                if(ac==2)
                     do_s(".");
                 else if(ac>2){
                      while(--ac){
                        printf("%s:\t", *++av);
                         do_s(*av);        }
                break;
        }
    }}}
    
    if(ac==1)
        do_ls(".");
    else if(ac==2 && parseA!= 1 && parseR != 1 && parseS != 1){
        while(--ac){

            printf("%s:\t", *++av);
            do_ls(*av);        }
    }
    
    
    
    
    
    }
    
    void do_ls(char dirname[]){
    int n = 0, i = 0;
    DIR *dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname))== NULL)
        fprintf(stderr, "ls1: cannot open %s\n", dirname);
    else{
        int x =100;
        char *filesList[x];
       
        while ((direntp = readdir(dir_ptr))!= NULL)
    {
        if ( !strcmp(direntp->d_name, ".") || !strcmp(direntp->d_name, "..") )
    {}
    else {
        printf("%s\t", direntp->d_name);
        filesList[i]= direntp->d_name;
        i++;
    }
    
    }
    printf("\n");
}

}
void do_A(char dirname[]){
    DIR *dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname))== NULL)
       {}
    else{
        int x =10;
        char *filesList[x];
        while ((direntp = readdir(dir_ptr))!= NULL)
    {
        if ( !strcmp(direntp->d_name, ".") || !strcmp(direntp->d_name, "..")){
            printf("%s\t", direntp->d_name);}
        else{}
    }
printf("\n");    
    }
}
void do_s(char dirname[]){
    int n = 0, i = 0;
    DIR *dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname))== NULL)
        fprintf(stderr, "ls1: cannot open %s\n", dirname);
    else{
        int x =10;
        char *filesList[x];
       
        while ((direntp = readdir(dir_ptr))!= NULL)
    {
        if ( !strcmp(direntp->d_name, ".") || !strcmp(direntp->d_name, "..") )
    {}
    else {
        filesList[i]= direntp->d_name;
        i++;
    }
    
    }
    int m = sizeof(filesList) /10;
    qsort(filesList, m, 10, compareStr);
    for(int i = 0; i <= m; i++)
        printf("%s\t", filesList[i]);
    }
    printf("\n");


}
void do_r(char dirname[]){
    int n = 0, i = 0;
    DIR *dir_ptr;
    struct dirent *direntp;
    if((dir_ptr = opendir(dirname))== NULL)
        fprintf(stderr, "ls1: cannot open %s\n", dirname);
    else{
        int x =10;
        char *filesList[x];
       
        while ((direntp = readdir(dir_ptr))!= NULL)
    {
        if ( !strcmp(direntp->d_name, ".") || !strcmp(direntp->d_name, "..") )
    {}
    else {
        filesList[i]= direntp->d_name;
        i++;
    }
    
    }
    int m = sizeof(filesList) /10;
    qsort(filesList, m, 10, compareStrReverse);
    for(int i = 0; i <= m; i++)
        printf("%s\t", filesList[i]);
    }
    printf("\n");


}
int compareStr(const void *pa, const void *pb){
    return strcmp(pa, pb);
}
int compareStrReverse(const void *pa, const void *pb){
    return strcmp(pb, pa);
}
