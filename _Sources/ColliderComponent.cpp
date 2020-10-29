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


		//Made using help from https://noonat.github.io/intersect/#aabb-vs-aabb
		ColliderComponent::Hit2D* ColliderComponent::Intersects(ColliderComponent* other)
		{
			//TODO: Maybe a built in intersection resolve method, with options like for preferring horizontal or vertical, or whether it should bounce/slide etc
			
			const float dx = other->OffsetCentre().x - this->OffsetCentre().x;
			const float px = (other->bounds.x + this->bounds.x) - abs(dx);
			
			if (px <= 0) 
			{
				return nullptr; //You can nullcheck to see if there were intersects or not.
			}

			const float dy = other->OffsetCentre().y - this->OffsetCentre().y;
			const float py = (other->bounds.y + this->bounds.y) - abs(dy);
			
			if (py <= 0) 
			{
				return nullptr;
			}

			auto* const hit = new Hit2D();
			if (px < py) //Horizontal
			{
				const float sx = MathUtilities::SignF(dx);
				hit->delta.x = px * sx;
				hit->normal.x = sx;
				hit->contact.x = this->OffsetCentre().x + (this->bounds.x * sx);
				hit->contact.y = other->OffsetCentre().y;
			}
			else //Vertical
			{
				const float sy = MathUtilities::SignF(dy);
				hit->delta.y = py * sy;
				hit->normal.y = sy;
				hit->contact.x = other->OffsetCentre().x;
				hit->contact.y = this->OffsetCentre().y + (this->bounds.y * sy);
			}
			return hit;
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
