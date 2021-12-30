# Route Planning Project  - a module examination assignment for the NanoDegree C++ program
![route-planning-screen-gif](./map.png)

## Introduction

This repo contains the Route Planning Project developed as the first examination project of the Udacity Nano Degree C++ Developer program/course.

It allows to plan a route from the assigned starting point to the assigned end point on any Open Street Map map file (.osm extension). The functionality can be tested without providing custom osm map.
In such case the starter / example map is provided among all the files contained in the repo (map shown on the picture below).

After starting the program in terminal, the user is prompted to provide the starting and end coordinates for the route plan, contained in the percentage range (0 - 100). 



## Cloning

When cloning this project, be sure to use the `--recurse-submodules` flag. Using HTTPS:
```
git clone https://github.com/mBialczak/Route-Planning-Project.git --recurse-submodules
```
or with SSH:
```
git clone git@github.com:mBialczak/Route-Planning-Project.git --recurse-submodules
```

## Dependencies for Running Locally
* cmake >= 3.11.3
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.4.0
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same instructions as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* IO2D
  * Installation instructions for all operating systems can be found [here](https://github.com/cpp-io2d/P0267_RefImpl/blob/master/BUILDING.md)
  * This library must be built in a place where CMake `find_package` will be able to find it

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Running
The executable will be placed in the `build` directory. From within `build`, you can run the project as follows:
```
./OSM_A_star_search
```
Or to specify a map file:
```
./OSM_A_star_search -f ../<your_osm_file.osm>
```

## Testing

The testing executable is also placed in the `build` directory. From within `build`, you can run the unit tests as follows:
```
./test
```

## Disclaimer

Some starter code was provided for the student (me). My task was to develop the program in order to incorporate A-star-search algorithm and combine everything together. 
