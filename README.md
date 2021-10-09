# SpinningCube
C app using OpenGL that draws a cube with different-colored sides. The cube is constantly spinning, while it is constantly being scaled until it reaches a size 3 times its 
original, and vice versa.
The cube is drawn using a "display list", which includes the commands needed to draw a rectangle with sides equal to 2 on top of z=1. Each side of the cube is drawn using the
appropirate translations and rotations.
There are two menu options: 
The first and default one is that the cube is rotating around its center at (0, 0, -β) and a vector (x, y, z).
The second one spins the cube around (0, 0, -8*β/10).
The third one shuts down the application.
The app uses double buffering, and depth buffering to hide hidden surfaces.

NOTE: If using Microsoft Visual Studio make sure that the Active solution platform is x86 (Build -> Configuration Manager).
