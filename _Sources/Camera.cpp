#include "precomp.h"

#include <Camera.h>

namespace Engine
{
	namespace Components
	{
		Camera::Camera(Surface* window)
		{
			AddComponent(transform_ = new TransformComponent());

			this->window_ = window;
			
			this->window_width_ = window_->GetWidth();
			this->window_height_ = window_->GetHeight();

			//bounds_ = { 0, 0, window_width_, window_height_ };
		}
		Camera::Camera(const int window_width, const int window_height)
		{
			AddComponent(transform_ = new TransformComponent());

			this->window_ = new Surface(window_width, window_height);
			
			this->window_width_ = window_->GetWidth();
			this->window_height_ = window_->GetHeight();

			//bounds_ = { 0, 0, window_width_, window_height_ };
		}


		Surface* Camera::GetWindow() const
		{
			return window_;
		}
		void Camera::SetWindow(Surface* window)
		{
			window_ = window;
		}

		vec2 Camera::GetCameraPosition() const
		{
			return transform_->position;
		}
		void Camera::SetCameraPosition(const float x = 0, const float y = 0) const
		{
			transform_->position.x = x;
			transform_->position.y = y;
		}
		void Camera::SetCameraPosition(const vec2 pos) const
		{
			transform_->position = pos;
		}

		vec2 Camera::WorldToScreen(const vec2& world_pos) const
		{
			return world_pos - this->GetCameraPosition();
		}
		vec2 Camera::ScreenToWorld(const vec2& screen_pos) const
		{
			return screen_pos + this->GetCameraPosition();
		}

		/*
		bool CameraComponent::IsOnScreen(RendererComponent* renderer) const
		{
			//TODO: Use Rect
			return true;
		}
		*/
		
	}
}
