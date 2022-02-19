
GIT_COMMIT   := $(shell git log --pretty=%h -1)
GIT_MODIFIED := $(shell [ -n "$$(git status -s)" ] && echo "-modified")
GIT_SRC_VER  := $(GIT_COMMIT)$(GIT_MODIFIED)
ifeq ($(GIT_SRC_VER),)
    GIT_SRC_VER = "unkown"
endif
export GIT_SRC_VER


CFLAGS += -D GIT_SRC_VER=\"$(GIT_SRC_VER)\"

#const char *get_src_version(void)
#{
#    return GIT_SRC_VER;
#}

