#pragma once

namespace Engine
{
	namespace Math 
	{
		constexpr float DEG_TO_RAD = 0.017453f; // PI/180
		constexpr float RAD_TO_DEG = 57.2957795131f; // 180/PI

		//constexpr float PIXELSTOUNITS = 1.0f / Core::PIXELS_PER_UNIT;
		//constexpr float UNITSTOPIXELS = Core::PIXELS_PER_UNIT; //1*50 

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
			//TODO: Re-Enable this
			
			/*
			// Calculate the difference.
			const float diff = fabs(a - b);

			// Find the largest
			a = fabs(a); //Absolute of a
			b = fabs(b); //Absolute of b
	
			//const float largest = b > a ? b : a;
			const float largest = Max(a, b);

			return (diff <= largest * maxDifference);
			*/
			
			return true;
		}

		inline bool IsZero(const float a, const float maxDifference = DEFAULT_EPSILON)
		{
			return Equals(a, 0, maxDifference);
		}
		
	};
}
