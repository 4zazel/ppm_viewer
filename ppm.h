#ifndef PPM_H
#define PPM_H

#include <stdint.h>
#include <stdio.h>

typedef struct{
  uint8_t r, g, b;
  char *symbol;
}pixel;

typedef struct{
  char type[3];
  unsigned int width, height;
  uint8_t value;
  pixel **data;
  char *global_symbol;
}ppm;

int open_file(FILE **file, char *filepath);
void read_type(FILE **file, ppm *image);
int read_size(FILE **file, ppm *image);
int read_color_value(FILE **file, ppm *image);
int read_pixel_data(FILE **file, ppm *image);
void display_data(ppm *image);
void display_image(ppm *image);
void convert_to_grayscale(ppm *image);
void print_help();
void close(FILE **file, ppm *image);
void convert_to_ascii(ppm *image);

#endif // PPM_H
