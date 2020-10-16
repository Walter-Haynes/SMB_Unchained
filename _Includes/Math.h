#pragma once

#include <GameSettings.h>

using Tmpl8::vec2;
using Tmpl8::Surface;

namespace Engine
{
	namespace Math 
	{
		constexpr float DEGTORAD = 0.017453f; // PI/180
		constexpr float RADTODEG = 57.2957795131f; // 180/PI

		constexpr float PIXELSTOUNITS = 1.0f / Core::PIXELS_PER_UNIT;
		constexpr float UNITSTOPIXELS = Core::PIXELS_PER_UNIT; //1*50 

		constexpr float DEFAULT_EPSILON = 0.0000000001f;

		inline float Min(float a, float b)
		{
			return((a < b) ? a : b);
		}
		
		inline float Max(float a, float b)
		{
			return((a > b) ? a : b);
		}
		
		inline bool Equals(float a, float b, const float maxDifference = DEFAULT_EPSILON)
		{
			// Calculate the difference.
			const float diff = fabs(a - b);

			// Find the largest
			a = fabs(a); //Absolute of a
			b = fabs(b); //Absolute of b
	
			//const float largest = b > a ? b : a;
			const float largest = Max(a, b);

			return (diff <= largest * maxDifference);
		}

		inline bool IsZero(const float a, const float maxDifference = DEFAULT_EPSILON)
		{
			return Equals(a, 0, maxDifference);
		}

		/*
		vec2 Lerp(const float mul, const vec2 a, const vec2 b)
		{
			vec2 result;

			result.x = a.x + mul * (b.x - a.x);
			result.y = a.y + mul * (b.y - a.y);

			return result;
		}
		*/

		/*
		struct Ray
		{
			Tmpl8::vec2 origin, direction;
		};
		 */

		/*
		class Rect
		{
			public:
			Rect(Tmpl8::vec2* position, const int width, const int height);

			Tmpl8::vec2* position = nullptr;

			int left = 0, right = 0, top = 0, bottom = 0;

			void SetPosition(Tmpl8::vec2* position);

			void SetWidth(const int width);
			void SetHeight(const int height);

			bool Intersects(const Rect* other) const;

			private:
			int width_ = 0, height_ = 0;
		};
		 */

		class Rect
		{
		public:
			vec2* position = nullptr;

			int left = 0, right = 0, top = 0, bottom = 0;
			
			Rect(vec2* position, const int width, const int height)
			{
				SetPosition(position);

				SetWidth(width);
				SetHeight(height);
			}

			void SetPosition(vec2* position)
			{
				this->position = position;

				SetWidth(width_);
				SetHeight(height_);
			}

			void SetWidth(const int width)
			{
				this->width_ = width;

				const int half_width = width / 2; //.0f;

				this->left = (position->x - half_width);
				this->right = (position->x + half_width);
			}

			void SetHeight(const int height)
			{
				this->height_ = height;

				const int half_height = height / 2; //.0f;

				this->bottom = (position->y - half_height);
				this->top = (position->y + half_height);
			}

			bool Intersects(const Rect* other) const
			{
				const bool in_vertical_bounds = (other->top > this->bottom) && (other->bottom < this->top);
				const bool in_horizontal_bounds = (other->right > this->left) && (other->left < this->right);

				return (in_horizontal_bounds && in_vertical_bounds);
			}

			private:
			int width_ = 0, height_ = 0;
		};
		
	};
}
