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
**    Harry Storbacka
**    Mark Page
*/

#include "Display/precomp.h"
#include "API/Display/2D/path_group.h"
#include "path_group_impl.h"
#include "API/Core/Math/ear_clip_result.h"
#include "API/Display/2D/canvas.h"
#include "API/Display/Font/font_vector.h"
#include <vector>

namespace clan
{

/////////////////////////////////////////////////////////////////////////////
// PathGroup Construction:

PathGroup::PathGroup() : impl(new PathGroup_Impl())
{
}

PathGroup::~PathGroup()
{
}

/////////////////////////////////////////////////////////////////////////////
// PathGroup Attributes:


/////////////////////////////////////////////////////////////////////////////
// PathGroup Operations:

void PathGroup::add_contour(Path &contour)
{
	impl->add_contour(contour);
}

void PathGroup::triangulate(GlyphPrimitivesArray &out_primitives_array)
{
	impl->triangulate(&out_primitives_array, NULL, NULL);
}
void PathGroup::triangulate(GlyphPrimitivesArrayOutline &out_primitives_array_outline)
{
	impl->triangulate(NULL, &out_primitives_array_outline, NULL);
}

void PathGroup::triangulate(GlyphPrimitivesArray &out_primitives_array, GlyphPrimitivesArrayOutline &out_primitives_array_outline)
{
	impl->triangulate(&out_primitives_array, &out_primitives_array_outline, NULL);
}

void PathGroup::triangulate(GlyphPrimitivesJoinedOutlines &out_joined_outlines)
{
	impl->triangulate(NULL, NULL, &out_joined_outlines);
}


/////////////////////////////////////////////////////////////////////////////
// PathGroup Implementation:

}