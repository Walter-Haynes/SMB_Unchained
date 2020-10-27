#pragma once

namespace Game
{
	constexpr auto GAME_NAME = "Super Mario Bros - Unchained";

	constexpr int PIXELS_PER_UNIT = 16;

	constexpr int SCREEN_WIDTH_PIXELS  = 256; //1500
	constexpr int SCREEN_HEIGHT_PIXELS = 240;  //750

	constexpr int SCREEN_WIDTH_UNITS  = SCREEN_WIDTH_PIXELS / PIXELS_PER_UNIT;
	constexpr int SCREEN_HEIGHT_UNITS = SCREEN_HEIGHT_PIXELS / PIXELS_PER_UNIT;

	constexpr float SCREEN_WIDTH_CENTRE_PIXELS = SCREEN_WIDTH_PIXELS / 2.0f;
	constexpr float SCREEN_HEIGHT_CENTRE_PIXELS = SCREEN_HEIGHT_PIXELS / 2.0f;

	constexpr float SCREEN_WIDTH_CENTRE_UNITS = SCREEN_WIDTH_UNITS / 2.0f;
	constexpr float SCREEN_HEIGHT_CENTRE_UNITS = SCREEN_HEIGHT_UNITS / 2.0f;
	
}