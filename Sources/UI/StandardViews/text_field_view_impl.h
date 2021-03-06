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
**    Magnus Norddahl
*/

#pragma once

#include "API/Core/Signals/signal.h"
#include "API/UI/Events/key_event.h"
#include "API/Display/System/timer.h"
#include "API/Display/Font/font.h"
#include "API/UI/Style/text_style.h"

namespace clan
{
	class TextFieldViewImpl
	{
	public:
		void on_key_press(KeyEvent &e);
		void on_key_release(KeyEvent &e);
		void on_pointer_press(PointerEvent &e);
		void on_pointer_release(PointerEvent &e);
		void on_pointer_move(PointerEvent &e);
		void on_focus_gained(FocusChangeEvent &e);
		void on_focus_lost(FocusChangeEvent &e);
		void on_activated(ActivationChangeEvent &e);
		void on_deactivated(ActivationChangeEvent &e);

		void select_to(size_t pos);

		void select_all();
		void move(int direction, bool ctrl, bool shift);
		void backspace();
		void del();
		void home(bool shift);
		void end(bool shift);
		void cut();
		void copy();
		void paste();
		void undo();
		void add(std::string new_text);

		void start_blink();
		void stop_blink();

		TextFieldView *textfield = nullptr;

		TextStyle text_style;
		TextAlignment alignment = TextAlignment::left;

		Font &get_font(Canvas &canvas);
		Font font; // Do not use directly. Use get_font.

		std::string text;
		std::string placeholder;

		Signal<void(KeyEvent &)> sig_before_edit_changed;
		Signal<void(KeyEvent &)> sig_after_edit_changed;
		Signal<void()> sig_selection_changed;
		Signal<void()> sig_enter_pressed;

		int max_length = -1;
		bool lowercase = false;
		bool uppercase = false;
		bool password_mode = false;
		bool numeric_mode = false;
		bool numeric_mode_decimals = false;
		bool readonly = false;
		bool select_all_on_focus_gain = true;
		bool cursor_drawing_enabled_when_parent_focused = false;
		std::string input_mask;
		std::string decimal_char = std::string(".");

		size_t selection_start = 0;
		size_t selection_length = 0;
		size_t cursor_pos = 0;

		float scroll_pos = 0.0f;

		bool cursor_blink_visible = false;
		Timer blink_timer;
		bool mouse_moves_left = false;
		Timer scroll_timer;
		bool ignore_mouse_events = false;
		bool mouse_selecting = false;

		struct UndoInfo
		{
			/* set undo text when:
			- added char after moving
			- destructive block operation (del, cut etc)
			- beginning erase
			*/
			std::string undo_text;
			bool first_erase = false;
			bool first_text_insert = false;
		};

		UndoInfo undo_info;

		static const std::string break_characters;
		static const std::string numeric_mode_characters;

		std::vector<Rectf> last_measured_rects;

		void set_text_selection(size_t start, size_t length);

		std::string get_text_before_selection() const;
		std::string get_selected_text() const;
		std::string get_text_after_selection() const;

		std::string create_password(std::string::size_type num_letters) const;

		int find_next_break_character(int search_start) const;
		int find_previous_break_character(int search_start) const;

		bool input_mask_accepts_input(const std::string &str) const;
		unsigned int get_character_index(int mouse_x_wincoords);
		Size get_visual_text_size(Canvas &canvas, int pos, int npos);
	};
}
