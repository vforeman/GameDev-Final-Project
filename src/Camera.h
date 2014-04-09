#ifndef Camera_H
#define Camera_H
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <iostream>
#include "Vmath.h"

class Camera
{

	Vector3<float> loc;
	float camYaw;
	float camPitch;
	float speed;
	float mousespeed;
	bool mi;
	void lockCamera();
	void moveCamera(const float& dir);
	void moveCameraUp(const float& dir);
	public:
	Camera();

	Camera(const Vector3<float>& loc);
	Camera(const Vector3<float>& loc,const float& yaw,const float& pitch);
	Camera(const Vector3<float>& loc,const float& yaw,const float& pitch,const float& sp,const float& ms);
	void control();
	void update();
	Vector3<float> getVector();
	Vector3<float> getLocation();
	float getYaw();
	float getPitch();
	void setLocation(const Vector3<float>& newcoord);
	void lookAt(const float& y, const float& p);
	void mouseIn();
	void mouseOut();
	bool IsMouseIn();
	void setSpeed(float sp,float ms);
};


#endif
