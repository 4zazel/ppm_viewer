#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "ppm.h"

FILE *file;
ppm image;
char *filepath;

int main(int argc, char* argv[]){

  if((filepath = argv[1]) == NULL){
    printf("Please enter a valid file path!\n");
    return 1;
  }

  open_file(&file, filepath);
  read_type(&file, &image);
  read_size(&file, &image);

  image.data = (pixel**)malloc(image.height * sizeof(pixel*));
  for(int i = 0; i<image.height; i++)
    image.data[i] = (pixel*)malloc(image.width * sizeof(pixel));

  read_color_value(&file, &image);
  read_pixel_data(&file, &image);

  display_image(&image);
  //display_data(&image);

  return 0;
}
