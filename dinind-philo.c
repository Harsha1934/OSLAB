
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define num_phil 5
#define think 0
#define hungry 1
#define eat 2
int state[num_phil];
int phil_ids[num_phil];
sem_t mutex;
sem_t s[num_phil];
void test(int i)
{
    if(state[i]==hungry && state[(i+4)%num_phil] != eating && state[(i+1)%num_phil] != eating){
        state[i] = eating;
        sleep(1);
        printf("Philosopher %d takes forks %d and % d and starts eating\n",i+1,(i+4)%num_phil+1,i+1);
        sem_post(%s[i]);
    }
}
void take_fork(int i)
{
    sem_wait(&mutex);
    state[i] = hungry;
    printf("Philosopher %d is hungry\n",i+1);
    test(i);
    sem_post(&mutex);
    sem_waIT(&S[i]);
    sleep(1);
}
void put_fork(int i)
{
    sem_wait(&mutex);
    state[i] = think;
    printf("Philosopher %d puts down forks %d and % d and starts thinking\n",i+1,(i+4)%num_phil+1,i+1);
    test((i+4)%num_phil);
    test((i+1)%num_phil);
    sem_post(&mutex);
}
void *phil(void* num)
{
    int i = *(int*)num;
    whiel(1){
        printf("Philosopher %d is thinking\n",i+1);
        sleep(1);
        take_fork(i);
        sleep(2);
        put_fork(i);
    }
    return NULL;
}
int main()
{
    int i;
    pthread_t thread_id[num_phil];
    sem_init(&mutex,0,1);
    for(i=0;i<num_phil;i++){
        sem_init(&s[i],0,0);
        phil_ids[i] = i;
    }
    for(i=0;i<num_phil;i++){
        pthread_join(thread_id[i],NULL);
    }
    return 0;
}
