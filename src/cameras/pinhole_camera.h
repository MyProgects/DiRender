#pragma once
#include <cameras/camera.h>
NAMESPACE_BEGIN(DR)
class PinholeCamera : public Camera {
public:
  Ray get_ray(float u, float v) const override {
    Point3f origin{0.0f};
    Vector3f d{left_bottom_corner_ + u * horizontal_ + v * vertical_};
    Ray r(origin, d);
    return (*view_trans_inverse_)(r);
  }

  PinholeCamera(Point3f origin, Vector3f WorldUp, Vector3f target, float fov,
                uint height, uint width)
      : Camera(origin, WorldUp, target, fov, height, width) {
    float theta = deg2rad(fov);
    float h = std::tan(theta / 2.0f);
    h = 2 * h;
    float w = (width / float(height)) * h;
    horizontal_ = h * Vector3f{1.0, 0.0, 0.0};
    vertical_ = w * Vector3f{0.0, 1.0, 0.0};
    left_bottom_corner_ = Vector3f{0.0f} - horizontal_ * 0.5f -
                          vertical_ * 0.5f - Vector3f{0.0f, 0.0f, 1.0f};
  }

private:
  Vector3f left_bottom_corner_;
  Vector3f horizontal_;
  Vector3f vertical_;
};
NAMESPACE_END(DR)
