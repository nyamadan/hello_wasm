#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

int *s_memory = NULL;

int add(int a, int b);

void on_load(const char *filename) {
  printf("onload: %s\n", filename);
  void *handle = dlopen(filename, RTLD_NOW);
  if (handle == NULL) {
    fprintf(stderr, "failed to dlopen\n");
    return;
  }

  int (*add)(int, int);
  add = dlsym(handle, "add");

  if (add == NULL) {
    fprintf(stderr, "failed to dlsym\n");
    return;
  }

  printf("add(1, 2) = %d\n", add(1, 2));
}

void on_error(const char *error) { printf("onerror: %s\n", error); }

int main() {
  emscripten_async_wget("./build/side.wasm", "/side.wasm", on_load, on_error);
  return 0;
}
