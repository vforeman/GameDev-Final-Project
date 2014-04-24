#ifndef Camera_H
#define Camera_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include "Overlay.h"
#include "Vmath.h"

class Camera
{
    Vector3f _up;
    Vector3f _right;
	Vector3f _forward;
    float camYaw;
	float camPitch;
	float speed;
	float mousespeed;
	bool mi;
	void lockCamera();
	void moveCamera(const float& dir);
	void moveCameraUp(const float& dir);

	public:
	Vector3f _multX;
	Vector3f loc;
	Camera();
	Camera(const Vector3f & loc);
	Camera(const Vector3f & loc,const float& yaw,const float& pitch);
	Camera(const Vector3f & loc,const float& yaw,const float& pitch,const float& sp,const float& ms);
	void control();
	void update();
	Vector3f getVector();
	Vector3f getLocation();
    Vector3f getEye();
    Vector3f getForward();
    Vector3f getRight();
    Vector3f getUp();
	float getYaw();
	float getPitch();
	void setLocation(const Vector3<float>& newcoord);
	void lookAt(const float& y, const float& p);
	void mouseIn();
	void mouseOut();
	bool IsMouseIn();
	void setSpeed(float sp,float ms);
};

class HUD{
public:
	HUD();
	~HUD();

protected:
	void update();
	void draw();

private:


};

#endif
