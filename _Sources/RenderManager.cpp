#include "precomp.h"

#include <RenderManager.h>

namespace Engine
{
	namespace Managers
	{
		Camera* RenderManager::GetMainCamera() const
		{
			return main_camera_;
		}
		void RenderManager::SetMainCamera(Camera* camera)
		{
			main_camera_ = camera;
		}

		void RenderManager::ClearScreen() const
		{
			main_camera_->GetWindow()->Clear(0xA1ADFF);
		}

		void RenderManager::DrawAllRenderers() const
		{
			for(int i = RendererComponent::GetCount() - 1; i >= 0; --i)
			{
				//TODO: Check if inside Camera bounds, only draw then.
				RendererComponent::GetInstance(i)->Draw(main_camera_);
			}

			//ClearScreen();
		}

		bool RenderManager::IsOnScreen(RendererComponent* renderer)
		{
			//return main_camera_->IsOnScreen(renderer);
			return true;
		}

		vec2 RenderManager::ConvertWorldToScreen(const vec2& world_relative_pos) const
		{
			return main_camera_->ConvertWorldToScreen(world_relative_pos);
		}

		vec2 RenderManager::ConvertScreenToWorld(const vec2& screen_relative_pos) const
		{
			return main_camera_->ConvertScreenToWorld(screen_relative_pos);
		}
	}
}