#include "src/Camera.h"

Camera::Camera() : _up(Vector3f(0.0f, 1.0f, 0.0f)), _right(Vector3f(1.0f, 0.0f, 0.0f)), _forward(Vector3f(0.0f, 0.0f, 1.0f))
{
	loc.x=0.0;
	loc.y=0.0;
	loc.z=0.0;
	camYaw=0.0;
	camPitch=0.0;
	speed=0.2;
	mousespeed=0.2;
	mi=false;
}

Camera::Camera(const Vector3f& l)
{
	loc=l;
	camYaw=0.0;
	camPitch=0.0;
	speed=0.3;
	mousespeed=0.3;
	mi=false;
}

Camera::Camera(const Vector3f& l,const float& yaw,const float& pitch)
{
	loc=l;
	 camYaw=yaw;
	 camPitch=pitch;
	 speed=0.3;
	 mousespeed=0.3;
	 mi=false;
}

Camera::Camera(const Vector3f& l,const float& yaw,const float& pitch,const float& sp,const float& ms)
{
	loc=l;
	 camYaw=yaw;
	 camPitch=pitch;
	 speed=sp;
	 mousespeed=ms;
	 mi=false;
}

void Camera::lockCamera()
{
	if(camPitch>90)
		camPitch=90;
	if(camPitch<-90)
		camPitch=-90;
	if(camYaw<0.0)
		camYaw+=360.0;
	if(camYaw>360.0)
		camYaw-=360;
}

void Camera::moveCamera(const float &dir)
{
	float rad=(camYaw+dir)*M_PI/180.0;
	float x = loc.x;
    float z = loc.z;
    float degrees2Radians = M_PI/180.0f;
    //float degrees2Radians = 1.0f;
    float yaw = camYaw + dir;
    loc.x-=sin(rad)*speed;
	loc.z-=cos(rad)*speed;
  
  /*  
    //Recalculate forward vector based off new yaw and pitch
    _forward.x =  sin(camYaw*degrees2Radians) * cos(camPitch*degrees2Radians);
    _forward.y =  sin(camPitch * degrees2Radians);
    _forward.z = -cos(camYaw * degrees2Radians) * cos(camPitch * degrees2Radians);
    _forward.normalize();

    //Recalculate up vector based off new yaw and pitch
    _up.x = sin(camYaw * degrees2Radians) * cos((camPitch+90.0f) * degrees2Radians);
    _up.y = sin((camPitch+90.0f) * degrees2Radians);
    _up.z = -cos(camYaw*degrees2Radians) * cos((camPitch+90.0f)*degrees2Radians);
    _up.normalize();

    //Recalculate right vector based off new 
    _right.x = sin((camYaw+90.0f) * degrees2Radians);
    _right.y = 0.0f;
    _right.z = -cos((camYaw+90.0f)*degrees2Radians);
    _right.normalize();
  */
  
    if(Overlay::isObstacle(loc.x, loc.z)) 
    {
        loc.x = x;
        loc.z = z;
    }
}

void Camera::moveCameraUp(const float& dir)
{
	float rad=(camPitch+dir)*M_PI/180.0;
	loc.y+=sin(rad)*speed;
}

void Camera::control()
{
    float degrees2Radians = M_PI/180.0f;
	if(mi)
	{
		// midX=320
		//MidY=240
		int MidX=640;
		int MidY=480;
		SDL_ShowCursor(SDL_DISABLE);
		int tmpx,tmpy;
		SDL_GetMouseState(&tmpx,&tmpy);
		camYaw+=mousespeed*(MidX-tmpx);
		camPitch+=mousespeed*(MidY-tmpy);


    //Recalculate forward vector based off new yaw and pitch
    //_forward.x =  sin(camYaw*degrees2Radians) * cos(camPitch*degrees2Radians);
    _forward.x =  -sin(camYaw*degrees2Radians) * cos(camPitch*degrees2Radians);
    _forward.y =  sin(camPitch * degrees2Radians);
    _forward.z = -cos(camYaw * degrees2Radians) * cos(camPitch * degrees2Radians);
    _forward.normalize();

    //Recalculate up vector based off new yaw and pitch
    _up.x = sin(camYaw * degrees2Radians) * cos((camPitch+90.0f) * degrees2Radians);
    _up.y = sin((camPitch+90.0f) * degrees2Radians);
    _up.z = -cos(camYaw*degrees2Radians) * cos((camPitch+90.0f)*degrees2Radians);
    _up.normalize();

    //Recalculate right vector based off new 
    _right.x = sin((camYaw+90.0f) * degrees2Radians);
    _right.y = 0.0f;
    _right.z = -cos((camYaw+90.0f)*degrees2Radians);
    _right.normalize();






		lockCamera();
		SDL_WarpMouse(MidX,MidY);
		Uint8* state=SDL_GetKeyState(NULL);
		if(state[SDLK_w])
		{
				moveCamera(0.0);
		}else if(state[SDLK_s])
		{
				moveCamera(180.0);
		}
		if(state[SDLK_a])
			moveCamera(90.0);
		else if(state[SDLK_d])
			moveCamera(270);
	}

	glRotatef(-camPitch,1.0,0.0,0.0);
	glRotatef(-camYaw,0.0,1.0,0.0);
}

void Camera::update()
{//commented out the 10 times land speed scalar
	glTranslatef(-loc.x,-loc.y,-loc.z);
}

Vector3f Camera::getLocation()
{
	return loc;
}

float Camera::getYaw()
{
	return camYaw;
}
float Camera::getPitch()
{
	return camPitch;
}

void Camera::setLocation(const Vector3f& newcoord)
{
	loc=newcoord;
}

void Camera::lookAt(const float& y, const float& p)
{
	camYaw=y;
	camPitch=p;
}

void Camera::mouseIn()
{
	mi=true;
}

void Camera::mouseOut()
{
	mi=false;
}

//returns where the player is looking
Vector3<float> Camera::getVector()
{
    /*
    Vector3f z_axis = (loc - Vector3f(0.0f, 0.8f, 0.0f));
    z_axis.normalize();
    Vector3f up = Vector3f(0.0f, 1.0f, 0.0f);
    Vector3f x_axis = up.crossProduct(z_axis);
    x_axis.normalize();
    Vector3f y_axis = z_axis.crossProduct(x_axis);

    Vector3f eye =      Vector3f(x_axis.x, y_axis.x, z_axis.x);
    Vector3f target =   Vector3f(x_axis.y, y_axis.y, z_axis.y);
    */

	// change spherical coordinates to cartesian
    //pitch = latitude = phi, yaw = longitude = theta
    //tutorial.math.lamar.edu/Classes/CalcIII/SphericalCoords.aspx
    float pitch = (camPitch);   //forward pitch
    float yaw = (camYaw);       //forward yaw
    
    //Closer Translation of spherical to rectangular coordinates
    //Vector3f val = Vector3f(sin(pitch)*cos(yaw), sin(pitch)*sin(yaw), cos(pitch));
    
    //printf("%s\n", val.toString().c_str());

    //return Vector3f(cos(yaw)*cos(yaw), sin(yaw)*cos(pitch), sin(pitch));
    
    float xzLen = cos(pitch);
    float x = xzLen * cos(yaw);
    float y = sin(pitch);
    float z = xzLen * sin(-yaw);

    return Vector3f(x, y, z);
}   

Vector3f Camera::getEye()
{
    Vector3f z_axis = (loc-Vector3f(0.0f, 0.8f, 0.0f));
    z_axis.normalize();
    Vector3f up = Vector3f(0.0f, 1.0f, 0.0f);
    Vector3f x_axis = up.crossProduct(z_axis);
    x_axis.normalize();
    Vector3f y_axis = z_axis.crossProduct(x_axis);

    Vector3f val = Vector3f(x_axis.x, x_axis.y, x_axis.x);
    
    return val;
}

Vector3f Camera::getForward()
{
     Vector3f location = loc;
     location.normalize();
     printf("Location: %s\n", loc.toString().c_str());
     printf("LocNorm: %s\n", location.toString().c_str());
     printf("Forward: %s\n", _forward.toString().c_str());
     return _forward;
}

Vector3f Camera::getRight()
{
    return _right;
}

Vector3f Camera::getUp()
{
    return _up;
}

bool Camera::IsMouseIn()
{
	return mi;
}


void Camera::setSpeed(float sp,float ms)
{
	speed=sp;
	mousespeed=ms;
}
