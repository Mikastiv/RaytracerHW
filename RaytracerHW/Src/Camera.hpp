#pragma once

class Camera
{
public:
    Camera() = default;
    Camera(float fovy, float aspect);

private:
    float mFovy = 60.0f;
    float mAspect = 4.0f / 3.0f;
};