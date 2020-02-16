# SPBR_Series_of_Images

## Overview
Generate series of images using SPBR.

## Usage
```bash
$ cd SPBR_LoopImage
$ ./spbr [input_file]
```

## Example
#### SPBR file
```bash
$ ./spbr header.spbr input_file.spbr
```

#### PLY file
```
$ ls -a
.param.spbr

$./spbr input_file.ply
```

## How to make video
```
$ ./ffmpeg -i IMAGE_DATA/image%03d.bmp -vcodec rawvideo VIDEO_DATA/out.mov
```