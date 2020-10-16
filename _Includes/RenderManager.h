#pragma once

#include <Manager.h>

#include <Camera.h>
using Engine::Components::Camera;

#include <RendererComponent.h>
using Engine::Components::RendererComponent;

namespace Engine
{
	namespace Managers
	{
		class RenderManager : public Utilities::Manager<RenderManager>
		{
		public:
			Camera* GetMainCamera() const;
			void SetMainCamera(Camera* camera);

			void ClearScreen() const;
			void DrawAllRenderers() const;

			bool IsOnScreen(RendererComponent* renderer);

			vec2 WorldToScreen(const vec2& world_pos) const;
			vec2 ScreenToWorld(const vec2& screen_pos) const;

		private:
		Camera* main_camera_ = nullptr;

		};

	}
}