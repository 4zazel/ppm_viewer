#include <stdio.h>

#include "ppm.h"

int open_file(FILE **file, char *filepath){
  *file = fopen(filepath, "r");
  if(*file == NULL){
    printf("Error opening file!\n");
    return 1;
  } else {
    return 0;
  }
}

void read_type(FILE **file, ppm *image){
  for(int i = 0; i<3; i++){
    image->type[i] = fgetc(*file);
  }
}

int read_size(FILE **file, ppm *image){
 if(!fscanf(*file, "%u %u", &image->width, &image->height)){
    printf("Failed to get width / height!\n");
    return 1;
  } else {
    fgetc(*file);
    return 0;
  }
}

int read_color_value(FILE **file, ppm *image){
  if(!fscanf(*file, "%hhu", &image->value)){
    printf("Failed to read color value!\n");
    return 1;
  }
  return 0;
}

int read_pixel_data(FILE **file, ppm *image){
  for(int i = 0; i < image->height; i++){
    for(int j = 0; j < image->width; j++){
      if(!fscanf(*file, "%hhu %hhu %hhu", &image->data[i][j].r, &image->data[i][j].g, &image->data[i][j].b)){
        printf("Failed to read color data at [%d][%d]!\n", i, j);
        return 1;
      }
    }
  }
  return 0;
}

void display_data(ppm *image){

  printf("DATA:\n");
  printf("Image type: %s\n", image->type);
  printf("Image size: %dx%d\n", image->width, image->height);
  printf("Color value: %d\n", image->value);
  printf("Pixel data: \n");

  for(int i = 0; i<image->height; i++){
    for(int j = 0; j<image->width; j++){
      printf("R:%d G:%d B:%d   ", image->data[i][j].r, image->data[i][j].g, image->data[i][j].b);
    }
    printf("\n");
  }
}

void display_image(ppm *image){
  for(int i = 0; i < image->height; i++){
    for(int j = 0; j < image->width; j++){
      printf("\x1b[38;2;%d;%d;%dm██", image->data[i][j].r, image->data[i][j].g, image->data[i][j].b);
    }
    printf("\n");
  }
}
