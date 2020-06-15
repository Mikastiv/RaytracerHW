# RaytracerHW
Raytracer for homework on edX

Example: ![Alt](/output.png "Example output")

## Usage
This raytracer reads a text file with commands to generate the scene

RaytracerHW.exe commandFile.txt

## Unfinished features
- Tranformations are buggy.
- Triangle with interpolated normals are not implemented yet (they acts as normal triangles).

## Commands
The input file consists of a sequence of lines, each of which has a command. For examples and clarifications, 
see the example input files (scene1.test). The lines have the following form.

- #comments This is a line of comments.
- command parameter1 parameter2 ... The first part of the line is always the command.

- size width height: The size command must be the first command of the file, which controls the image size.
- maxdepth depth: The maximum depth (number of bounces) for a ray (default is 5).
- output filename: The output file to which the image should be written.

Camera

In general, there should be only one camera specification in the input file; what happens if there is more than one specification 
is undefined. 

- camera lookfromx lookfromy lookfromz lookatx lookaty lookatz upx upy upz fov Note that fov stands for the field of view in the y direction. The field of view in the x direction will be determined by the image size. The world aspect ratio (distinct from the width and height that determine image aspect ratio) is always 1; a sphere at the center of a screen will look like a circle, not an ellipse, independent of the image aspect ratio. This is a common convention but different from some previous specifications like the raytracing journal handout.

Geometry

- sphere x y z radius Defines a sphere with a given position and radius.
- maxverts number Defines a maximum number of vertices for later triangle specifications. It must be set before vertices are defined. 
  Can be ignored.
- maxvertnorms number Defines a maximum number of vertices with normals for later specifications. It must be set before vertices with normals
  are defined. Can be ignored.
- vertex x y z Defines a vertex at the given location. The vertex is put into a pile, starting to be numbered at 0.
- vertexnormal x y z nx ny nz Similar to the above, but define a surface normal with each vertex. The vertex and vertexnormal set of 
  vertices are completely independent (as are maxverts and maxvertnorms).
- tri v1 v2 v3 Create a triangle out of the vertices involved (which have previously been specified with the vertex command). 
  The vertices are assumed to be specified in counter-clockwise order.
- trinormal v1 v2 v3 Same as above but for vertices specified with normals. In this case, each vertex has an associated normal, 
  and when doing shading, the normals are interpolated for intermediate points on the triangle.

Transformations

- translate x y z A translation 3-vector.
- rotate x y z angle Rotate by angle (in degrees).
- scale x y z Scale by the corresponding amount in each axis (a non-uniform scaling).
- pushTransform Push the current modeling transform on the stack as in OpenGL.
- popTransform Pop the current transform from the stack as in OpenGL. 
  The sequence of popTransform and pushTransform can be used if desired before every primitive to reset the transformation. Initial matrix
  is identity matrix.

Lights

- directional x y z r g b The direction to the light source, and the color, as in OpenGL.
- point x y z r g b The location of a point source and the color, as in OpenGL.
- attenuation const linear quadratic Sets the constant, linear and quadratic attenuations (default 1,0,0) as in OpenGL.
- ambient r g b The global ambient color to be added for each object (default is .2,.2,.2).

Materials

- diffuse r g b specifies the diffuse color of the surface.
- specular r g b specifies the specular color of the surface.
- shininess s specifies the shininess of the surface.
- emission r g b gives the emissive color of the surface.
