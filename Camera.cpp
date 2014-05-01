#include "src/Camera.h"

Camera::Camera()
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

    loc.x-=sin(rad)*speed;
	loc.z-=cos(rad)*speed;

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
	// change spherical coordinates to cartesian
	//return (Vector3f(-cos(camPitch*M_PI/180.0)*sin(camYaw*M_PI/180.0),sin(camPitch*M_PI/180.0),-cos(camPitch*M_PI/180.0)*cos(camYaw*M_PI/180.0)));
    //pitch = latitude = phi, yaw = longitude = theta
    //tutorial.math.lamar.edu/Classes/CalcIII/SphericalCoords.aspx

   
    //float pitch = (camPitch);   //forward pitch
    //float yaw = (camYaw+90.0f);       //forward yaw

	
	float pitch = (camPitch ); //*M_PI/180.0;
	float yaw = (camYaw + 90.0f); //*M_PI/180.0;

    //Closer Translation of sphericl to rectangular coordinates
    return Vector3f(sin(pitch)*cos(yaw), sin(pitch)*sin(yaw), cos(pitch) );




	
    
	//float xzlen = cos(camPitch);

	 //return Vector3f(xzlen * cos(yaw), xzlen*sin(-yaw),  sin(pitch)); // works a lil better
	
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
