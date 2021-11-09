#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <matelib.h>
#include <commons/log.h>

char* LOG_PATH = "./secuencia.log";
char* PROGRAM_NAME = "secuencia";
uint32_t seed;
pthread_mutex_t seed_mutex;
t_log* logger;
pthread_mutex_t logger_mutex;

void print_thread_info(char* thread_name, int value)
{
  pthread_mutex_lock(&logger_mutex);
  log_info(logger, "thread name: %s", thread_name);
  log_info(logger, "value: %d", value);
  pthread_mutex_unlock(&logger_mutex);
}

void increment_seed()
{
  pthread_mutex_lock(&seed_mutex);
  seed++;
  pthread_mutex_unlock(&seed_mutex);
}

void calculate_value_and_increment_seed(uint32_t* current_value)
{
  pthread_mutex_lock(&seed_mutex);
  (*current_value) += seed;
  seed++;
  pthread_mutex_unlock(&seed_mutex);
}

void *thread(void *config_path)
{
  mate_instance mate_ref;
  mate_init(&mate_ref, (char *)config_path);
  mate_pointer key = mate_memalloc(mate_ref, sizeof(char) * 6);
  mate_memwrite(mate_ref, "CHILD", key, sizeof(char) * 6);

  mate_pointer value = mate_memalloc(mate_ref, sizeof(uint32_t));
  mate_memwrite(mate_ref, seed, value, sizeof(uint32_t));

  print_thread_info("CHILD", seed);

  increment_seed();

  while (1)
  {
    char *thread_name = malloc(sizeof(char) * 6);
    uint32_t current_value;

    mate_memread(mate_ref, key, thread_name, sizeof(char) * 6);
    mate_memread(mate_ref, value, &current_value, sizeof(uint32_t));
    
    calculate_value_and_increment_seed(&current_value);
    print_thread_info(thread_name, current_value);

    mate_memwrite(mate_ref, current_value, value, sizeof(uint32_t));
  }

  mate_close(&mate_ref);
  return 0;
}

int main(int argc, char *argv[])
{
  if(argc != 2) {
    printf("Debe ingresar el path del archivo de config")
  }

  char* config_path = argv[1];
  seed = 1;
  pthread_mutex_init(&seed_mutex, NULL);
  pthread_mutex_init(&logger_mutex, NULL);
  logger = log_create(LOG_PATH, PROGRAM_NAME, true, 3)

  //Instancio la biblioteca
  mate_instance mate_ref;
  mate_init(&mate_ref, config_path);

  //Pido memoria
  mate_pointer key = mate_memalloc(mate_ref, sizeof(char) * 5);
  mate_memwrite(mate_ref, "MAIN", key, sizeof(char) * 5);

  mate_pointer value = mate_memalloc(mate_ref, sizeof(uint32_t));
  mate_memwrite(mate_ref, seed, value, sizeof(uint32_t));

  print_thread_info("MAIN", seed);

  increment_seed();

  pthread_t thread_id;
  pthread_create(&thread_id, NULL, &thread, (void)* config_path);
  pthread_detach(thread_id);

  while (1)
  {
    char *thread_name = malloc(sizeof(char) * 5);
    uint32_t current_value;

    mate_memread(mate_ref, key, thread_name, sizeof(char) * 5);
    mate_memread(mate_ref, value, &current_value, sizeof(uint32_t));

    calculate_value_and_increment_seed(&current_value);
    print_thread_info(thread_name, current_value);
    
    mate_memwrite(mate_ref, current_value, value, sizeof(uint32_t));
  }

  mate_close(&mate_ref);
  return 0;
}