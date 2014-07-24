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

int main(int argc, char* argv[]) {

  uid_t uid = getuid();
  uid_t euid = geteuid();
  if (uid != 0 || euid != 0) {
    printf("You do not have permissions to continue operation. "
	   "Try with sudo.\n");
    return 1;
  }

  int i = 0;
  int color = 0;
  int image = 0;
  int _long = 0;
  int small = 0;
  for (i = 0; i < argc; i++) {
    if (!strcmp(COLOR, argv[i])) {
      color = 1;
    }
    else if (!strcmp(IMAGE, argv[i])) {
      image = 1;
    }
    else if (!strcmp(LONG, argv[i])) {
      _long = 1;
    }
    else if (!strcmp(SMALL, argv[i])) {
      small = 1;
    }
    else if (!strcmp(HELP, argv[i])) {
      printf("Usage: sudo woodo <option>\n"
	     "\t\t(no option)\tNormal ASCII sudowoodo\n"
	     "\t\t--help\t\tView usage\n"
	     "\t\t--color\t\tPrints ASCII image in color\n"
	     "\t\t--image\t\tPrints image of background colors, compressed\n"
	     "\t\t--small\t\tPrints small image, like --image\n"
	     "\t\t--long\t\tPrints long, stretched image like --image\n");
      return 0;
    }
  }

  if (image) {
    printf(SUPER_SUDO_WOODO);
  }
  else if (_long) {
    printf(SUPER_SUDO_WOODO_LONG);
  }
  else if (small) {
    printf(SMALL_WOODO);
  }
  else if (color) {
    printf(COLOR_WOODO_STRING);
  }
  else {
    printf(WOODO_STRING);
  }
  return 0;
}
