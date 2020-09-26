
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
    
    mut= sem_open("mutex", O_CREAT, 0666, VALUE);
    printf("person1 enters.\n");
    //wait on semaphore "mutex" and decrease it by 1
    sem_wait(mut);
    printf("person1 checks the refrigertor.\n");
    
    fridge=open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
    //"fridge" is empty
    if(lseek(fd,0,SEEK_END)==0){
        printf("person1  goes to market to buy milk\n");
        sleep(2);
             write(fridge,"milk ",5);
        printf("person1 puts milk in fridge and leaves.\n");
        //now there is milk in the refrigertaor 
        if(lseek(fridge,0,SEEK_END)>5)
            printf(" The refrigerator can not hold so much milk!\n");
    }else{
        printf("person 1 closes the fridge and leaves.\n");
    }
    //close file "fridge"
    close(fridge);
    //add semaphore "mutex" by 1
    sem_post(mut);
   
    sem_close(mut);
    sem_unlink("mutex");
    return 0;
}
