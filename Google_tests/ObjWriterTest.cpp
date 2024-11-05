#include "gtest/gtest.h"
#include "../ObjWriter.h"
#include <fstream>
#include "../Model.h"
#include "../Polygon.h"

const std::string temp_filename = "test.obj";

TEST(ObjWriterTest, ConstructorOpensFileSuccessfully)
{
    ObjWriter writer(temp_filename);
    ASSERT_NO_THROW(writer);
}

TEST(ObjWriterTest, ConstructorThrowsExceptionWhenFileCannotBeOpened)
{
    ASSERT_THROW(ObjWriter writer("/invalid/path/test.obj"), std::runtime_error);
}

TEST(ObjWriterTest, WriteWritesVerticesToFile)
{
    Model model;
    model.vertices.emplace_back(1.0f, 2.0f, 3.0f);
    model.vertices.emplace_back(4.0f, 5.0f, 6.0f);

    ObjWriter writer(temp_filename);
    writer.write(model);

    std::ifstream file(temp_filename);
    std::string line;
    std::getline(file, line);
    ASSERT_EQ(line, "v 1 2 3");
    std::getline(file, line);
    ASSERT_EQ(line, "v 4 5 6");
}

TEST(ObjWriterTest, WriteWritesTextureVerticesToFile)
{
    Model model;
    model.textureVertices.emplace_back(0.1f, 0.2f);
    model.textureVertices.emplace_back(0.3f, 0.4f);

    ObjWriter writer(temp_filename);
    writer.write(model);

    std::ifstream file(temp_filename);
    std::string line;
    std::getline(file, line);
    std::getline(file, line);
    ASSERT_EQ(line, "vt 0.1 0.2");
    std::getline(file, line);
    ASSERT_EQ(line, "vt 0.3 0.4");
}

TEST(ObjWriterTest, WriteWritesNormalsToFile)
{
    Model model;
    model.normals.emplace_back(0.0f, 0.0f, 1.0f);
    model.normals.emplace_back(0.0f, 1.0f, 0.0f);

    ObjWriter writer(temp_filename);
    writer.write(model);

    std::ifstream file(temp_filename);
    std::string line;
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    ASSERT_EQ(line, "vn 0 0 1");
    std::getline(file, line);
    ASSERT_EQ(line, "vn 0 1 0");
}

TEST(ObjWriterTest, WriteWritesPolygonsToFile) {
    Model model;

    Polygon p1;
    Polygon p2;

    p1.set_vertex_indices({1, 2});
    p1.set_vertex_indices({3, 4});

    model.polygons.push_back(p1);
    model.polygons.push_back(p2);

    ObjWriter writer(temp_filename);
    writer.write(model);

    std::ifstream file(temp_filename);
    std::string line;
    std::getline(file, line);
    std::getline(file, line);
    std::getline(file, line);
    ASSERT_EQ(line, "f 1/1/1 2/2/2 ");
}

TEST(ObjWriterTest, DestructorClosesFile) {
    {
        ObjWriter writer(temp_filename);
    }
    std::ifstream file(temp_filename);
    ASSERT_TRUE(file.is_open());
}


