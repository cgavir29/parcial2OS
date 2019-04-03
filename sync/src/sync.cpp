#include "sync.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <cerrno>


Sync::Sync(const char *name, bool open) :  ISync(), name(name) {

}

Sync::~Sync() {
}

ISync* Sync::create(const char *name) {
  return new Sync(name, true);
}

ISync* Sync::open(const char *name) {
}

void Sync::destroy(const char *name) {
}

void Sync::wait() {

}

void Sync::signal() {
}

void Sync::close() {
}
