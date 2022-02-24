#include <latbox/init.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>


static unsigned int         g_appcmd_num = 0;
static struct main_appcmd   g_appcmd_array[12];



void mem_mr_register(void);
void mem_mw_register(void);
void mem_ior_register(void);
void mem_iow_register(void);

static void main_appcmd_register(void)
{
    mem_mr_register();
    mem_mw_register();
    mem_ior_register();
    mem_iow_register();
}


static struct main_appcmd *main_find_appcmd(const char *name)
{
    int i;

    for (i = 0; i < g_appcmd_num; i++) {
        if (strcmp(g_appcmd_array[i].name, name) == 0) {
            return &g_appcmd_array[i];
        }
    }

    return NULL;
}


int main_register_appcmd(const char *name, const char *brief,
                         main_appinit_t init_func,
                         main_appmain_t main_func)

{
    if (g_appcmd_num >= ARRAY_ELEMENTS(g_appcmd_array)) {
        return -1;
    }

    if (main_find_appcmd(name) != NULL) {
        return -2;
    }

    g_appcmd_array[g_appcmd_num].name      = name;
    g_appcmd_array[g_appcmd_num].brief     = brief;
    g_appcmd_array[g_appcmd_num].init_func = init_func;
    g_appcmd_array[g_appcmd_num].main_func = main_func;
    g_appcmd_num++;

    return 0;
}


void main_print_help(void)
{
    int i;

    printf("available command list:\n");
    for (i = 0; i < g_appcmd_num; i++) {
        printf("  %s\t- %s\n", g_appcmd_array[i].name, g_appcmd_array[i].brief);
    }
}


int main(int argc, char **argv)
{
    int i;
    char                *bin_name;
    struct main_appcmd  *appcmd;

    // for (i = 0; i < argc; i++) {
    //     printf("[%u/%u] %s\n", i, argc, argv[i]);
    // }

    main_appcmd_register();


    bin_name = basename(argv[0]);
    if (strcmp(bin_name, "latbox") == 0) {
        argc--;
        argv++;
        bin_name = argv[0];
    }

    if (argc == 0) {
        main_print_help();
        return -1;
    }

    appcmd = main_find_appcmd(bin_name);
    if (appcmd == NULL) {
        printf("%s: command not found\n", argv[0]);
        return -2;
    }

    if (appcmd->init_func != NULL && appcmd->init_func() != 0) {
        printf("%s: command initialise failed\n", argv[0]);
        return -3;
    }

    return appcmd->main_func(argc, argv);
}

