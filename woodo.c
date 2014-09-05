#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "woodo.h"

#define COLOR "--color"
#define IMAGE "--image"
#define LONG  "--long"
#define SMALL "--small"
#define HELP "--help"

#define OPT_COLOR 1
#define OPT_IMAGE 2
#define OPT_LONG 3
#define OPT_SMALL 4

int main(int argc, char* argv[]) {

  uid_t uid = getuid();
  uid_t euid = geteuid();
  if (uid != 0 || euid != 0) {
    printf("You do not have permissions to continue operation. "
	   "Try with sudo.\n");
    return 1;
  }

  int option = get_option(argc, argv);

  print_woodo(option);
}

int get_option(int argc, char* argv[]) {
  int option = 0;
  int i;
  for (i = 0; i < argc; i++) {
    if (!strcmp(COLOR, argv[i])) {
      option = OPT_COLOR;
    }
    else if (!strcmp(IMAGE, argv[i])) {
      option = OPT_IMAGE;
    }
    else if (!strcmp(LONG, argv[i])) {
      option = OPT_LONG;
    }
    else if (!strcmp(SMALL, argv[i])) {
      option = OPT_SMALL;
    }
    else if (!strcmp(HELP, argv[i]) || !strcmp("-h", argv[i])) {
      print_help();
      exit(0);
    }
  }
  return option;
}

void print_woodo(int option) {
  switch (option) {
  case OPT_COLOR:
    printf(COLOR_WOODO_STRING);
    break;
  case OPT_IMAGE:
    printf(SUPER_SUDO_WOODO);
    break;
  case OPT_LONG:
    printf(SUPER_SUDO_WOODO_LONG);
    break;
  case OPT_SMALL:
    printf(SMALL_WOODO);
    break;
  default:
    printf(WOODO_STRING);
    break;
  }
}

void print_help() {
  printf("Usage: sudo woodo <option>\n"
	 "\t\t(no option)\tNormal ASCII sudowoodo\n"
	 "\t\t-h, --help\tView usage\n"
	 "\t\t--color\t\tPrints ASCII image in color\n"
	 "\t\t--image\t\tPrints image of background colors, compressed\n"
	 "\t\t--small\t\tPrints small image, like --image\n"
	 "\t\t--long\t\tPrints long, stretched image like --image\n");
}
