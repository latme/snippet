#ifndef __LATBOX_INIT_H__
#define __LATBOX_INIT_H__


#include <lattypes.h>
#include <latmacros.h>



typedef int (*main_appinit_t)(void);
typedef int (*main_appmain_t)(int argc, char *argv[]);

struct main_appcmd {
    const char      *name;
    const char      *brief;
    main_appmain_t   main_func;
    main_appinit_t   init_func;
};


int main_register_appcmd(const char *name, const char *brief,
                         main_appinit_t init_func,
                         main_appmain_t main_func);










#endif   ///< __LATBOX_INIT_H__
