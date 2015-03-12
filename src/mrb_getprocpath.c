/*
** mrb_getprocpath.c - Getprocpath class
**
** Copyright (c) Junichi Kajiwara 2015
**
** See Copyright Notice in LICENSE
*/

#include "mruby.h"
#include "mruby/data.h"
#include "mrb_getprocpath.h"

#include <unistd.h>
#ifdef __APPLE__
#include <libproc.h>
#endif

#define DONE mrb_gc_arena_restore(mrb, 0);

typedef struct {
  char *str;
  int len;
} mrb_getprocpath_data;

static const struct mrb_data_type mrb_getprocpath_data_type = {
  "mrb_getprocpath_data", mrb_free,
};

static mrb_value mrb_getprocpath_init(mrb_state *mrb, mrb_value self)
{
  mrb_getprocpath_data *data;
  char *str;
  int len;

  data = (mrb_getprocpath_data *)DATA_PTR(self);
  if (data) {
    mrb_free(mrb, data);
  }
  DATA_TYPE(self) = &mrb_getprocpath_data_type;
  DATA_PTR(self) = NULL;

  mrb_get_args(mrb, "s", &str, &len);
  data = (mrb_getprocpath_data *)mrb_malloc(mrb, sizeof(mrb_getprocpath_data));
  data->str = str;
  data->len = len;
  DATA_PTR(self) = data;

  return self;
}


static  mrb_value mrb_getprocpath_get(mrb_state *mrb, mrb_value self)
{
#ifdef __APPLE__
	pid_t pid;
	char path[PROC_PIDPATHINFO_MAXSIZE];

	pid = getpid();
	proc_pidpath(pid, path, sizeof(path));
	//TODO error handling
#endif
#ifdef __linux
	char path[2048];
        ssize_t len;
	len = readlink("/proc/self/exe", path, sizeof(path));
        path[len]='\0';
        //TODO error handling
#endif

  return mrb_str_new_cstr(mrb, path);
}

static mrb_value mrb_getprocpath_hi(mrb_state *mrb, mrb_value self)
{
  return mrb_str_new_cstr(mrb, "hi!!");
}

void mrb_mruby_getprocpath_gem_init(mrb_state *mrb)
{
    struct RClass *getprocpath;
    getprocpath = mrb_define_class(mrb, "Getprocpath", mrb->object_class);
    mrb_define_method(mrb, getprocpath, "initialize", mrb_getprocpath_init, MRB_ARGS_REQ(1));
    mrb_define_class_method(mrb, getprocpath, "get", mrb_getprocpath_get, MRB_ARGS_NONE());
    DONE;
}

void mrb_mruby_getprocpath_gem_final(mrb_state *mrb)
{
}

