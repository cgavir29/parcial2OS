#pragma once
#include "isync.h"
#include <semaphore.h>

class Sync : public ISync{
    public:
        Sync(const char *name, bool open) ;
        ~Sync();
        static ISync* create(const char *name);
        static ISync* open(const char *name);
        static void destroy(const char *name);
        void wait();
        void signal();
        void close();
    private:
        const char *name;
        bool opencito;
        sem_t *semaph = nullptr;
};