#pragma once

#include <cmath>

#include <GameSettings.h>

using Game::PIXELS_PER_UNIT;

#include "template.h"
using Tmpl8::vec2;

namespace Engine
{
	namespace MathUtilities
	{
		constexpr float DEG_TO_RAD = 0.017453f; // PI/180
		constexpr float RAD_TO_DEG = 57.2957795131f; // 180/PI

		constexpr float PIXELS_TO_UNITS = 1.0f / PIXELS_PER_UNIT;
		constexpr float UNITS_TO_PIXELS = PIXELS_PER_UNIT; //1*Pixels Per Unit

		constexpr float DEFAULT_EPSILON = 0.0000000001f;

		inline float Min(const float a, const float b)
		{
			return((a < b) ? a : b);
		}

		inline float Max(const float a, const float b)
		{
			return((a > b) ? a : b);
		}

		//float Abs

		inline int Sign(const float val)
		{
			if (val > 0) return 1;
			if (val < 0) return -1;
			return 0;
		}
		inline float SignF(const float val)
		{
			if (val > 0) return 1;
			if (val < 0) return -1;
			return 0;
		}

		inline float Clamp(float value, const float min, const float max)
		{
			if (value < min)
			{
				value = min;
			}
			else if (value > max)
			{
				value = max;
			}

			return value;
		}
		inline int Clamp(int value, const int min, const int max)
		{
			if (value < min)
			{
				value = min;
			}
			else if (value > max)
			{
				value = max;
			}
			
			return value;
		}

		inline float Magnitude(const vec2 vector)
		{
			return (vector.x * vector.x) + (vector.y * vector.y);
		}
		

		/*!
		 *      @return  The angle between two vec2 directions IN DEGREES.
		 */
		inline float Angle(const vec2 from, const vec2 to)
		{
			//Made with help from https://www.omnicalculator.com/math/angle-between-two-vectors.
			
			return acos(from.dot(to) / (Magnitude(from) * Magnitude(to))) * RAD_TO_DEG;

			//The Magnitude stuff can be dumped if we normalize the directions I think.
			
			//return acos(Clamp(from.dot(to), -1.0f, 1.0f)) * RAD_TO_DEG;
		}
		

		/*!
		 *  Checks if two floats are approximately the same.
		 *        
		 *      @param [in] max_difference: (Optional) The maximum difference between the floats.
		 *
		 *      @return True if approximately the same. False if not.
		 */
		inline bool Equals(float a, float b, const float max_difference = DEFAULT_EPSILON)
		{
			// Calculate the difference.
			const float diff = fabs(a - b);

			// Find the largest
			a = fabs(a); //Absolute of a
			b = fabs(b); //Absolute of b

			//const float largest = b > a ? b : a;
			const float largest = Max(a, b);

			return (diff <= largest * max_difference);
		}

		/*!
		 *  Returns true if the input float a is zero.
		 *
		 *      @param [in] a: the float which we're checking.
		 *      @param [in] max_difference: optional parameter.
		 *
		 *      @return True if zero. False if not.
		 */
		inline bool IsZero(const float a, const float max_difference = DEFAULT_EPSILON)
		{
			return Equals(a, 0, max_difference);
		}

		/*!
		 *  Moves a value current towards target.
		 *
		 *      @param [in] current: The current value.   
		 *      @param [in] target: The value to move towards.  
		 *      @param [in] max_delta: The maximum change that should be applied to the value.
		 */
		inline float MoveTowards(const float current, const float target, const float max_delta)
		{
			if (abs(target - current) <= max_delta) 
			{
				return target;
			}
			
			return current + Sign(target - current) * max_delta;
		}

		

	};
}
