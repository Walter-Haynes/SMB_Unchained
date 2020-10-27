#pragma once

#include <Component.h>
#include <TransformComponent.h>
#include <Instancer.h>

#include <Camera.h>
using Engine::Prefabs::Camera;

using Tmpl8::Sprite;
using Tmpl8::Surface;

namespace Engine
{
	namespace Components
	{
		class RendererComponent final : public Component, public Utilities::Instancer<RendererComponent>
		{
		public:
			Sprite* sprite;
			unsigned short int animation_frames;

			RendererComponent(Sprite* sprite);

			RendererComponent(Surface* sprite_image, const unsigned short frame_count);

			virtual ~RendererComponent();

			void Draw(Camera* draw_camera);

			void Animate();


		private:
			unsigned short int current_frame_ = 0;
			TransformComponent* transform_ = nullptr;

			TransformComponent* GetTransform();
		};
		
	}
}
