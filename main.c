#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm.h"

FILE *file;
ppm image;
char *filepath;

int main(int argc, char* argv[]){

  //Check for filepath argument
  if((filepath = argv[1]) == NULL){
    printf("Please enter a valid file path!\n");
    return 1;
  }

  //Open the file
  open_file(&file, filepath);
  if(!file) return 1;

  //Read data
  read_type(&file, &image);
  read_size(&file, &image);

  //Allocate memory for the image data array
  image.data = (pixel**)malloc(image.height * sizeof(pixel*));
  for(int i = 0; i<image.height; i++)
    image.data[i] = (pixel*)malloc(image.width * sizeof(pixel));

  //Read color value (unused for now)
  read_color_value(&file, &image);
  read_pixel_data(&file, &image);
 
  //Check for command flags
  for(int i = 0; i<argc; i++){
    if(!strcmp(argv[i], "-h")){
      print_help();
      return 0;
    }
    if(!strcmp(argv[i], "-g")) convert_to_grayscale(&image);
    if(!strcmp(argv[i], "-d")){
      display_data(&image);
      return 0;
    }
  }

  display_image(&image);
  //display_data(&image);

  return 0;
}
