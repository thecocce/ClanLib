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

#include "UI/precomp.h"
#include "block_layout.h"
#include <algorithm>

namespace clan
{
	float BlockLayout::get_preferred_width(Canvas &canvas, View *view)
	{
		if (!view->box_style.is_width_auto())
			return view->box_style.width();

		float width = 0.0f;
		for (const std::shared_ptr<View> &subview : view->subviews())
		{
			if (subview->box_style.is_static() && !subview->hidden())
			{
				float margin_box_width = 0.0f;
				margin_box_width += subview->box_style.margin_left();
				margin_box_width += subview->box_style.border_left();
				margin_box_width += subview->box_style.padding_left();
				margin_box_width += subview->get_preferred_width(canvas);
				margin_box_width += subview->box_style.padding_right();
				margin_box_width += subview->box_style.border_right();
				margin_box_width += subview->box_style.margin_right();
				width = clan::max(width, margin_box_width);
			}
		}
		return width;
	}

	float BlockLayout::get_preferred_height(Canvas &canvas, View *view, float width)
	{
		if (!view->box_style.is_height_auto())
			return view->box_style.height();

		float height = 0.0f;
		for (const std::shared_ptr<View> &subview : view->subviews())
		{
			if (subview->box_style.is_static() && !subview->hidden())
			{
				height += subview->box_style.margin_top();
				height += subview->box_style.border_top();
				height += subview->box_style.padding_top();
				height += subview->get_preferred_height(canvas, width);
				height += subview->box_style.padding_bottom();
				height += subview->box_style.border_bottom();
				height += subview->box_style.margin_bottom();
			}
		}
		return height;
	}

	float BlockLayout::get_first_baseline_offset(Canvas &canvas, View *view, float width)
	{
		const auto &subviews = view->subviews();
		for (const auto & subview : subviews)
		{
			if (!(subview)->hidden())
				return (subview)->get_first_baseline_offset(canvas, width);
		}
		return 0.0f;
	}

	float BlockLayout::get_last_baseline_offset(Canvas &canvas, View *view, float width)
	{
		const auto &subviews = view->subviews();
		for (auto it = subviews.rbegin(); it != subviews.rend(); ++it)
		{
			if (!(*it)->hidden())
				return (*it)->get_last_baseline_offset(canvas, width);
		}
		return 0.0f;
	}

	void BlockLayout::layout_subviews(Canvas &canvas, View *view)
	{
		float y = 0.0f;
		for (const std::shared_ptr<View> &subview : view->subviews())
		{
			if (subview->box_style.is_static() && !subview->hidden())
			{
				float left_noncontent = 0.0f;
				left_noncontent += subview->box_style.margin_left();
				left_noncontent += subview->box_style.border_left();
				left_noncontent += subview->box_style.padding_left();

				float right_noncontent = 0.0f;
				right_noncontent += subview->box_style.margin_right();
				right_noncontent += subview->box_style.border_right();
				right_noncontent += subview->box_style.padding_right();

				float subview_width = view->geometry().content.get_width() - left_noncontent - right_noncontent;
				if (subview_width < 0.0f)
				{
					right_noncontent = 0.0f;
					subview_width = view->geometry().content.get_width() - left_noncontent;
					if (subview_width < 0.0f)
					{
						left_noncontent = 0.0f;
						subview_width = view->geometry().content.get_width();
					}
				}

				float subview_height = subview->get_preferred_height(canvas, subview_width);

				y += subview->box_style.margin_top();
				y += subview->box_style.border_top();
				y += subview->box_style.padding_top();

				subview->set_geometry(BoxGeometry::from_content_box(subview->box_style, Rectf::xywh(left_noncontent, y, subview_width, subview_height)));

				y += subview_height;
				y += subview->box_style.padding_bottom();
				y += subview->box_style.border_bottom();
				y += subview->box_style.margin_bottom();

				subview->layout_subviews(canvas);
			}
		}
	}
}
