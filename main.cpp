#include "Model.h"
#include "ObjWriter.h"
#include "Polygon.h"

int main()
{
    Polygon polygon;
    polygon.set_vertex_indices({ 4, 3, 4});
    polygon.set_normal_indices({1, 2, 3 });

    Model model;
    model.vertices.push_back(Vector3D(0.21f, 0, 0));
    model.vertices.push_back(Vector3D(1, 0.14f, 0));
    model.vertices.push_back(Vector3D(1, 1, 0.0f));
    model.textureVertices.push_back(Vector2D(0, 0));
    model.textureVertices.push_back(Vector2D(1, 0));
    model.textureVertices.push_back(Vector2D(1, 1));
    model.normals.push_back(Vector3D(0, 0, 1));
    model.normals.push_back(Vector3D(0, 0, 1));
    model.normals.push_back(Vector3D(0, 0, 1));
    model.polygons.push_back(polygon);

    ObjWriter writer("model.obj");

    writer.write(model);

    return 0;
}