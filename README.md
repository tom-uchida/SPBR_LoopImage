# SPBR_Series_of_Images

## Overview
Generate series of images.

## Usage
```bash
./spbr [input_file]
```

## Example
```bash
./spbr header.spbr input_file.spbr
./spbr input_file.ply
```
## How to make video
```
./ffmpeg -i IMAGE_DATA/image%03d.bmp -vcodec rawvideo VIDEO_DATA/out.mov
```