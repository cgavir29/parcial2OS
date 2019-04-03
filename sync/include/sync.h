#pragma once
#include "isync.h"
#include <semaphore.h>

class Sync : public ISync{
    public:
        Sync(const char *name, bool open) ;
        ~Sync();
        ISync* create(const char *name);
        ISync* open(const char *name);
        void destroy(const char *name);
        void wait();
        void signal();
        void close();
    private:
        const char *name;
        // bool open;
};