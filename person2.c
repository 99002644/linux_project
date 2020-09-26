#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
int main(int argc, char * argv[]) {
    int fridge;
    int VALUE=1;
    sem_t * mut;
    mut = sem_open("mutex", O_CREAT, 0666, VALUE);
    printf("person2 enters.\n");
    sleep(rand()%2+1);
    sem_wait(mut);
    printf("person2 checks the fridge.\n");
    fridge=open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fridge,0,SEEK_END)==0){
        printf("person2 goes to market to buy milk\n");
        sleep(rand()%2+1);
             write(fridge,"milk ",5);
        printf("person2 puts milk in refrigerator and leaves.\n");
        if(lseek(fridge,0,SEEK_END)>5)
            printf("The fridge can not hold so much milk!\n");
    }else{
        printf("person2 closes the fridge and leaves.\n");
    }
    close(fridge);
    sem_post(mut);
    sem_close(mut);
    sem_unlink("mutex");
    return 0;
}
