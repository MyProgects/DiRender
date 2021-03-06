#pragma once
#include <cameras/camera.h>
#include <cores/primitive.h>
#include <map>
#include <unordered_map>
#include <vector>

NAMESPACE_BEGIN(DR)
struct Scene {
  Scene() {}
  Scene(const Scene &other) = delete;
  Scene &operator=(const Scene &other) = delete;

  void add(std::shared_ptr<Camera> cam) { cams_.push_back(cam); }
  void add(std::shared_ptr<Primitive> prim) { prims_.push_back(prim); }
  std::vector<std::shared_ptr<Camera>> cams_;
  std::vector<std::shared_ptr<Primitive>> prims_;
  std::vector<std::shared_ptr<Primitive>> light_shapes_;
};
NAMESPACE_END(DR)
