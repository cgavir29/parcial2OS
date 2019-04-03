#include "sync.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <cerrno>


Sync::Sync(const char *name, bool open) :  ISync(), name(name), opencito(open) {

}

Sync::~Sync() {
}

ISync* Sync::create(const char *name) {
  // Creamos un objeto Sync con nombre 'name'
  Sync *sync = new Sync(name, false);
  // Asignamos a sync un nuevo semaforo
  sync->semaph = sem_open(name, O_CREAT | O_EXCL, 0660, 0);
  // retornamos el Sync solicitado
  return sync;
}

ISync* Sync::open(const char *name) {
  Sync *sync = new Sync(name, true);
  sync->semaph = sem_open(name, O_CREAT, 0660, 0);
  return sync;
}

void Sync::destroy(const char *name) {
  // Remuevo el semaforo correspondiente al 'name'
  sem_unlink(name);
  // Como eliminar el objeto Sync al que pertece el semaforo ???
}

void Sync::wait() {
  sem_wait(this->semaph);
}

void Sync::signal() {
  sem_post(this->semaph);
}

void Sync::close() {
  sem_close(this->semaph);
  this->opencito = false;
}
