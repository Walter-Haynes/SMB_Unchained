#pragma once

#include <template.h>
#include <surface.h>

#include <Behaviour.h>
using Engine::Behaviour;

#include <TransformComponent.h>
using Engine::Components::TransformComponent;

using Tmpl8::vec2;
using Tmpl8::Surface;

namespace Engine
{
	namespace Prefabs
	{

		class Camera final : public Component
		{
		public:
			explicit Camera(Surface* window);
			Camera(int window_width, int window_height);

			TransformComponent* GetTransform() const;

			Surface* GetWindow() const;
			void SetWindow(Surface* window);

			vec2 GetCameraPosition() const;
			void SetCameraPosition(float x, float y) const;
			void SetCameraPosition(vec2 pos) const;

			/*!
			 *  Converts a world-relative position to a screen-relative position.
			 *
			 *      @param [in] world_relative_pos: world-relative position IN UNITS.
			 *
			 *      @return screen_relative_pos: screen-relative position IN UNITS
			 */
			vec2 ConvertWorldToScreen(const vec2& world_relative_pos) const;
			/*!
			 *  Converts a screen-relative position to a world-relative position.
			 *
			 *      @param [in] screen_relative_pos: screen-relative position IN UNITS.
			 *
			 *      @return world_relative_pos: world-relative position IN UNITS
			 */
			vec2 ConvertScreenToWorld(const vec2& screen_relative_pos) const;

			//bool IsOnScreen(RendererComponent* renderer) const;

		private:
			Surface* window_ = nullptr;
			
			int window_width_;
			int window_height_;

			TransformComponent* transform_;
		};
	}
}