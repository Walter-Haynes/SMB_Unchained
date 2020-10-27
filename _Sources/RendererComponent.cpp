#include "precomp.h"

#include <RendererComponent.h>

namespace Engine
{
	namespace Components
	{

		RendererComponent::RendererComponent(Sprite* sprite)
		{
			this->sprite = sprite;
			this->animation_frames = sprite->Frames();
		}

		RendererComponent::RendererComponent(Surface* sprite_image, const unsigned short frame_count)
		{
			this->sprite = new Sprite(sprite_image, frame_count);
			this->animation_frames = frame_count;
		}

		RendererComponent::~RendererComponent() = default;

		void RendererComponent::Draw(Camera* draw_camera)
		{
			if (sprite)
			{
				sprite->SetFrame(current_frame_);

				Surface* window = draw_camera->GetWindow();

				const vec2 screen_pos = draw_camera->ConvertWorldToScreen(GetTransform()->GetPositionUnits()) * MathUtilities::UNITS_TO_PIXELS;

				sprite->Draw(window,
					static_cast<int>(screen_pos.x),
					static_cast<int>(screen_pos.y));
			}
		}

		void RendererComponent::Animate()
		{
			current_frame_++;

			if (current_frame_ > animation_frames) current_frame_ = 0;
		}

		TransformComponent* RendererComponent::GetTransform()
		{
			if (transform_)
			{
				return transform_;
			}
			if ((transform_ = GetParent()->GetComponent<TransformComponent>()))
			{
				return transform_;
			}

			printf("Warning: No Transform attached to Renderer's GameObject!");

			return nullptr;
		}
		
	}
}