#include "precomp.h"

#include "ColliderComponent.h"

namespace Engine
{
	namespace Components
	{
		bool ColliderComponent::CollidesWith(const vec2& point)
		{
			return (
				point.x >= this->OffsetCentre().x &&
				point.y >= this->OffsetCentre().y &&
				point.x <  this->OffsetCentre().x + this->bounds.x &&
				point.y <  this->OffsetCentre().y + this->bounds.y);
		}

		bool ColliderComponent::CollidesWith(ColliderComponent* other)
		{
			return (
				this->OffsetCentre().x + this->bounds.x > other->OffsetCentre().x  && //Horizontal
				this->OffsetCentre().y + this->bounds.y > other->OffsetCentre().y  && //Vertical
				this->OffsetCentre().x < other->OffsetCentre().x + other->bounds.x && //Horizontal
				this->OffsetCentre().y < other->OffsetCentre().y + other->bounds.y);  //Vertical
		}

		void ColliderComponent::DebugBounds(const Tmpl8::Pixel color)
		{
			const vec2 screen_pos = Managers::RenderManager::Instance()->ConvertWorldToScreen(Centre()) * MathUtilities::UNITS_TO_PIXELS;

			Managers::RenderManager::Instance()->GetMainCamera()->GetWindow()->Box(
				screen_pos.x - (GetExtends()->x * MathUtilities::UNITS_TO_PIXELS),
				screen_pos.y - (GetExtends()->y * MathUtilities::UNITS_TO_PIXELS),
				screen_pos.x + (GetExtends()->x * MathUtilities::UNITS_TO_PIXELS),
				screen_pos.y + (GetExtends()->y * MathUtilities::UNITS_TO_PIXELS),
				color);
		}

		vec2 ColliderComponent::Centre()
		{
			return GetTransform()->position + *GetExtends();
		}

		vec2 ColliderComponent::OffsetCentre()
		{
			return Centre() + offset;
		}
	}
}
