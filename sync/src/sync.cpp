#include "sync.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <cerrno>


Sync::Sync(const char *name, bool open) :  ISync(), name(name) {

}

Sync::~Sync() {
}

ISync* Sync::create(const char *name) {
  return new Sync(name, false);
}

ISync* Sync::open(const char *name) {
  // obtener el objeto ISync que se creo en en Sync::create
  // por medio del 'name', retornar este objeto cambiando open a true
}

void Sync::destroy(const char *name) {
  // determinar la instancia de ISync que tiene nombre 'name'
  // e invocar el destructor en este
}

void Sync::wait() {

}

void Sync::signal() {
}

void Sync::close() {
}
