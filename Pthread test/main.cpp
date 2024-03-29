#include <pthread.h>
#include <ncurses.h>
#include <stdlib.h> /* rand */
#include <unistd.h> /* sleep */
#include <iostream>

int THREAD_NUM;

void *FindAvg(void *threadNumber)
{
	std::cout<< "Wątek "<<(long)threadNumber<<" zaczyna pracę"<<std::endl;
	int array[10];
	for(auto i = 0; i<10; i++)
	{
		array[i] = rand() % 50 + 1;
	}

	int sum = 0;
	for(auto i=0; i<10; i++)
	{
		sleep(rand() % 4);
		std::cout<<"Wątek "<<(long)threadNumber<<": arr["<<i<<"] = "<<array[i]<<std::endl;
		sum += array[i];
	}

	std::cout<<"Wątek "<<(long)threadNumber<<" wynik: "<<(double)sum / 10<<std::endl;
	pthread_exit(NULL);
}

int main(int args, char *argv[])
{
	int threadCallback;;

	/* Sprawdzenie poprawności uruchomienia */
	if(args > 2)
	{
		std::cout<<"Należy podać tylko jeden parametr!"<<std::endl;
		return -1;	
	}

	THREAD_NUM = (int)(*argv[1]) - 48; /* wyłuskujemy wartość spod wskaźnika */
	pthread_t Threads[THREAD_NUM]; 
	
	for(auto i = 0; i<THREAD_NUM; i++)
	{
		threadCallback = pthread_create(&Threads[i], NULL, FindAvg, (void*)i);
		if(threadCallback)
		{
			std::cout<<"Błąd podczas tworzenia wątku"<<std::endl;
			return -1;
		}
	}

	for(auto i = 0; i<THREAD_NUM; i++)
	{
		threadCallback = pthread_join(Threads[i], NULL); /* czekamy na ukończenie wątków */
		if(threadCallback)
		{
			std::cout<<"Błąd podczas joinowania wątku"<<std::endl;
			return -1;
		}
		std::cout<<"Poprawnie ukończony watek "<<i<<std::endl;
	}

	std::cout<<"Koniec programu..."<<std::endl;
    pthread_exit(NULL);
}