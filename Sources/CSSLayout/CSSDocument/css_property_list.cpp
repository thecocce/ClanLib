/*
**  ClanLib SDK
**  Copyright (c) 1997-2012 The ClanLib Team
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

#include "CSSLayout/precomp.h"
#include "API/CSSLayout/CSSDocument/css_property_value_list.h"
#include "API/CSSLayout/CSSDocument/css_property.h"

namespace clan
{

/////////////////////////////////////////////////////////////////////////////

class CSSPropertyValueList_Impl
{
public:
	std::vector<CSSPropertyValue *> values;
};

/////////////////////////////////////////////////////////////////////////////

CSSPropertyValueList::CSSPropertyValueList()
: impl(new CSSPropertyValueList_Impl())
{
}

size_t CSSPropertyValueList::size() const
{
	return impl->values.size();
}

CSSPropertyValue *CSSPropertyValueList::at(size_t index)
{
	return impl->values.at(index);
}

const CSSPropertyValue *CSSPropertyValueList::at(size_t index) const
{
	return impl->values.at(index);
}

CSSPropertyValue *CSSPropertyValueList::operator[](size_t index)
{
	return impl->values[index];
}

const CSSPropertyValue *CSSPropertyValueList::operator[](size_t index) const
{
	return impl->values[index];
}

void CSSPropertyValueList::push_back(CSSPropertyValue *value)
{
	impl->values.push_back(value);
}

}
