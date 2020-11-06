#pragma once

#include <Manager.h>
using Engine::Utilities::Manager;

#include <Camera.h>
using Engine::Prefabs::Camera;

#include <RendererComponent.h>
using Engine::Components::RendererComponent;

namespace Engine
{
	namespace Managers
	{

		/*!
		 *  Manages drawing Renderers to the screen, and keeps track of the main camera.
		 *  You can use it to convert positions from world to screen, and to check whether something is on screen or not.
		 */
		class RenderManager : public Manager<RenderManager>
		{
		public:
			Camera* GetMainCamera() const;
			void SetMainCamera(Camera* camera);

			void ClearScreen() const;
			void DrawAllRenderers() const;

			bool IsOnScreen(RendererComponent* renderer);

			vec2 ConvertWorldToScreen(const vec2& world_relative_pos) const;
			vec2 ConvertScreenToWorld(const vec2& screen_relative_pos) const;

		private:
			Camera* main_camera_ = nullptr;

		};

	}
}