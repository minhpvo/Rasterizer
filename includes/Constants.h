#pragma once
#include <string>

#include "POINT3D.H"
#include "VECTOR3D.H"
#include "Material.h"
#include "RGBCOLOR.H"

const Point3D   CAMERA_POS = Point3D(.0f, .0f, -1.0f);
const Vector3D  CAMERA_FWD = Vector3D(.0f, .0f, 1.0f); // Points into the screen
const Vector3D  CAMERA_UP = Vector3D(.0f, 1.0f, .0f);

const int IMAGE_WIDTH = 800;
const int IMAGE_HEIGHT = 600;
const std::string IMAGE_NAME = "output.bmp";


namespace Materials {
  const Material PLASTIC = Material(RGBColor(0.4), 0.4, 2);
  const Material WALL = Material(RGBColor(0.6), 0.2, 1);
}

namespace Colors {
  const RGBColor WHITE = RGBColor(1.0, 1.0, 1.0);
  const RGBColor BLACK = RGBColor(0.0, 0.0, 0.0);
  const RGBColor RED = RGBColor(1.0, 0.0, 0.0);
  const RGBColor GREEN = RGBColor(0.0, 1.0, 0.0);
  const RGBColor BLUE = RGBColor(0.0, 0.0, 1.0);
  const RGBColor GREY = RGBColor(0.5, 0.5, 0.5);
  const RGBColor YELLOW = RGBColor(1.0, 1.0, 0.0);
  const RGBColor PURPLE = RGBColor(1.0, 0.0, 1.0);
  const RGBColor CYAN = RGBColor(0.0, 1.0, 1.0);
}

namespace Objects {
  GeometryObject* box = new GeometryObject(Materials::PLASTIC,
    std::vector<Point3D> {
      // Vertices positions
      // Front face
      Point3D(500, -500, 5),
      Point3D(500, 500, 5),
      Point3D(1500, 500, 5),
      Point3D(1500, -500, 5),
      // Back face
      Point3D(500, -500, 10),
      Point3D(500, 500, 10),
      Point3D(1500, 500, 10),
      Point3D(1500, -500, 10),
      // Top face
      Point3D(500, 500, 5),
      Point3D(500, 500, 10),
      Point3D(1500, 500, 10),
      Point3D(1500, 500, 5),
      // Bottom face
      Point3D(500, -500, 5),
      Point3D(500, -500, 10),
      Point3D(1500, -500, 10),
      Point3D(1500, -500, 5),
      // Left face
      Point3D(500, -500, 5),
      Point3D(500, 500, 5),
      Point3D(500, 500, 10),
      Point3D(500, -500, 10),
      // Right face
      Point3D(1500, -500, 5),
      Point3D(1500, 500, 5),
      Point3D(1500, 500, 10),
      Point3D(1500, -500, 10),
    },
    std::vector<RGBColor> {
      // Vertices colors
    },
    std::vector<Vector2D> {
      // Texture coordinates
      // Front face
      Vector2D(0, 0),
      Vector2D(0, 1),
      Vector2D(1, 1),
      Vector2D(1, 0),
      // Back face
      Vector2D(1, 1),
      Vector2D(1, 0),
      Vector2D(0, 0),
      Vector2D(0, 1),
      // Top face
      Vector2D(0, 0),
      Vector2D(0, 1),
      Vector2D(1, 1),
      Vector2D(1, 0),
      // Bottom face
      Vector2D(0, 0),
      Vector2D(0, 1),
      Vector2D(1, 1),
      Vector2D(1, 0),
      // Left face
      Vector2D(1, 0),
      Vector2D(1, 1),
      Vector2D(0, 1),
      Vector2D(0, 0),
      // Right face
      Vector2D(0, 0),
      Vector2D(0, 1),
      Vector2D(1, 1),
      Vector2D(1, 0)
    },
    std::vector<uint32_t> {
      // Vertices indices
      // Front face
      0, 1, 2,
      2, 3, 0,

      // Back face
      4, 5, 6,
      6, 7, 4,

      // Top face
      8, 9, 10,
      10, 11, 8,

      // Bottom face
      12, 13, 14,
      14, 15, 12,

      // Left face
      16, 17, 18,
      18, 19, 16,

      // Right face
      20, 21, 22,
      22, 23, 20
    },
    // Texture image location
    "../assets/box.bmp");

  GeometryObject* ground = new GeometryObject(Materials::WALL,
    std::vector<Point3D> {
      // Vertices positions
      Point3D(-3000., -1000., 1.),
      Point3D(-3000., -1000., 50.),
      Point3D(3000., -1000., 1.),
      Point3D(3000., -1000., 50.)
    },
    std::vector<RGBColor> {
      // Vertices colors
    },
    std::vector<Vector2D> {
      // Texture coordinates
      Vector2D(0, 0),
      Vector2D(0, 5),
      Vector2D(5, 0),
      Vector2D(5, 5)
    },

    std::vector<uint32_t> {
      // Indices
      0, 1, 2,
      1, 3, 2
    },
    "../assets/brick_wall.bmp");

  GeometryObject* textured_rectangle = new GeometryObject(Materials::WALL,
    std::vector<Point3D> {
      // Vertices positions
      Point3D(-1500, -250, 15.),
      Point3D(-1500, 2348, 15.),
      Point3D(1500, -250, 15.),
      Point3D(1500, 2348, 15.),
    },
    std::vector<RGBColor> {
        // Vertices colors
    },
    std::vector<Vector2D> {
      // Texture coordinates
      Vector2D(0, 0),
      Vector2D(0, 1),
      Vector2D(1, 0),
      Vector2D(1, 1)
    },
    std::vector<uint32_t> {
        // Indices
      0, 1, 2,
      1, 3, 2
    },
    "../assets/brick_wall.bmp");

  GeometryObject* rainbow_triangle = new GeometryObject(Materials::WALL,
    std::vector<Point3D> {
      // Vertices positions
      Point3D(-1500, -250, 15.),
      Point3D(0, 2348, 15.),
      Point3D(1500, -250, 15.),
    },
    std::vector<RGBColor> {
      // Vertices colors
      Colors::GREEN,
      Colors::RED,
      Colors::BLUE,
    },
    std::vector<Vector2D> {
      // Texture coordinates
      Vector2D(0, 0),
      Vector2D(.5, 1),
      Vector2D(1, 0)
    },
    std::vector<uint32_t> {
      // Indices
      0, 1, 2,
    });
}



