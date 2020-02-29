#include "Camera2.h"
#include "Application.h"
#include "Mtx44.h"
#include "Utility.h"

Camera2::Camera2()
{
}

Camera2::~Camera2()
{
}

void Camera2::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();
}

void Camera2::Update(double dt)
{
	

	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up).Normalized();
	POINT mousePos;
	GetCursorPos(&mousePos);
	int xpos = mousePos.x;
	int ypos = mousePos.y;
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.3f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	Vector3 front;
	front.x = cos(Math::DegreeToRadian(yaw)) * cos(Math::DegreeToRadian(pitch));
	front.y = sin(Math::DegreeToRadian(pitch));
	front.z = sin(Math::DegreeToRadian(yaw)) * cos(Math::DegreeToRadian(pitch));

	view = front.Normalized();
	right.y = 0;
	right.Normalize();
	up = right.Cross(view).Normalized();
	right = view.Cross(up).Normalized();
	target = position + view;


	static const float CAMERA_SPEED = 50.f;
	if (Application::IsKeyPressed(VK_LEFT) || Application::IsKeyPressed('A'))
	{
		target -= right * dt * 10;
		position -= right * dt * 10;
		position.y = 0;
	}
	if (Application::IsKeyPressed(VK_RIGHT) || Application::IsKeyPressed('D'))
	{
		target += right * dt * 10;
		position += right * dt * 10;
		position.y = 0;
	}
	if (Application::IsKeyPressed(VK_UP) || Application::IsKeyPressed('W'))
	{
		target += view * dt * 10;
		position += view * dt * 10;
		position.y = 0;
		target.y = view.y;
	}
	if (Application::IsKeyPressed(VK_DOWN) || Application::IsKeyPressed('S'))
	{
		target -= view * dt * 10;
		position -= view * dt * 10;
		position.y = 0;
		target.y = view.y;
	}

	if (Application::IsKeyPressed('N'))
	{
		Vector3 direction = target - position;
		if (direction.Length() > 5)
		{
			Vector3 view = (target - position).Normalized();
			position += view * (float)(10.f * dt);
		}
	}
	if (Application::IsKeyPressed('M'))
	{
		Vector3 view = (target - position).Normalized();
		position -= view * (float)(10.f * dt);
	}
	if (Application::IsKeyPressed('R'))
	{
		Reset();
	}


}

void Camera2::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
}

