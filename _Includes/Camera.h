#pragma once

#include <Behaviour.h>
#include <TransformComponent.h>

//WHY THE FUCK WONT THE PRECOMPILE WORK?!!!
#include "../template.h"

namespace Tmpl8 {
	class Surface;
}

using Engine::Components::Behaviour;

using Engine::Components::TransformComponent;

using Tmpl8::vec2;
using Tmpl8::Surface;

namespace Engine
{
	namespace Components
	{

		class Camera final : public Component
		{
		public:
			explicit Camera(Surface* window);
			Camera(int window_width, int window_height);

			TransformComponent* Transform() const;


			Surface* GetWindow() const;
			void SetWindow(Surface* window);

			vec2 GetCameraPosition() const;
			void SetCameraPosition(float x, float y) const;
			void SetCameraPosition(vec2 pos) const;

			vec2 WorldToScreen(const vec2& world_pos) const;
			vec2 ScreenToWorld(const vec2& screen_pos) const;

			//bool IsOnScreen(RendererComponent* renderer) const;


		private:
			Surface* window_ = nullptr;
			
			int window_width_;
			int window_height_;

			TransformComponent* transform_;
		};
	}
}