# PPM Viewer

### Building
`gcc main.c ppm.c -o main`

### Usage
`./main [filename]`

### Example usage
If image is in the same directory as program you can either specify the full path or just the image name:

  `./main image.ppm [flags]`

If image is in another directory specify the full path instead:

  `./main /home/user/some_dir/image.ppm [flags]`

### Flags
**-h** Show the help screen.

**-g** Convert image to grayscale.

**-d** Display raw image data.

> [!WARNING]
> Currently only supports P3 PPM format!

##To Do:
- [ ] Implement P2 and P1 PPM formats.
- [ ] Add effects / color filters as flags.
