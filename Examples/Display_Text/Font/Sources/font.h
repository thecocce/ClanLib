/*
**  ClanLib SDK
**  Copyright (c) 1997-2015 The ClanLib Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Mark Page
*/

#pragma once

enum FontClass
{
	font_ttf,
	font_sprite
};

// This is the Application class (That is instantiated by the Program Class)
class App
{
public:
	int start(const std::vector<std::string> &args);

private:
	void on_button_clicked_class_system();
	void on_button_clicked_class_sprite();
	void on_button_clicked_typeface_tahoma();
	void on_button_clicked_typeface_sans();
	void on_button_clicked_typeface_bitstream();
	void on_checkbox_state_italic();
	void on_checkbox_state_subpixel();
	void on_checkbox_state_antialias();
	void on_button_clicked_weight_light();
	void on_button_clicked_weight_normal();
	void on_button_clicked_weight_bold();
	void on_button_clicked_size_16();
	void on_button_clicked_size_32();
	void on_button_clicked_size_64();

	void on_input_up(const InputEvent &key);
	void on_window_close();
	void on_lineedit_changed(InputEvent &e);
	void render(DisplayWindow &window, GameTime &game_time);
	void select_font();
	void draw_font_example();
	void draw_font_info();

private:
	bool quit;
	Canvas canvas;
	std::string font_text;
	FontMetrics font_metrics;
	std::string font_typeface;
	std::string font_filename;
	FontDescription font_desc;
	Sizef font_size;
	clan::Font small_font;
	clan::Font selected_font;
	FontClass selected_fontclass;
	float last_fps;
	ResourceManager resources;
};



