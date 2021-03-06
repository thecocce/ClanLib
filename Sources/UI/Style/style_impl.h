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

#include "API/UI/Style/style_property_parser.h"
#include <memory>
#include <string>

namespace clan
{
	class Style;
	class ImageSource;
	class Colorf;

	class StyleImpl : public StylePropertySetter
	{
	public:
		void set_keyword(const std::string &name, const std::string &keyword) override;
		void set_length(const std::string &name, float length) override;
		void set_percentage(const std::string &name, float length) override;
		void set_string(const std::string &name, const std::string &str) override;
		void set_url(const std::string &name, const std::string &url) override;
		void set_color(const std::string &name, const Colorf &color) override;
		void set_image(const std::string &name, const std::shared_ptr<ImageSource> &image) override;

		std::shared_ptr<Style> base;
	};
}
