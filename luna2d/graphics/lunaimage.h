//-----------------------------------------------------------------------------
// luna2d engine
// Copyright 2014-2015 Stepan Prokofjev
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#pragma once

#include "platform/lunafiles.h"
#include "lunapngformat.h"

namespace luna2d{

class LUNATexture;

//------------------------------
// Class for working with images
//------------------------------
class LUNAImage
{
public:
	LUNAImage(); // Construct empty image
	LUNAImage(const std::string& filename, const LUNAImageFormat& format,
		LUNAFileLocation location = LUNAFileLocation::ASSETS); // Constructor with loading

private:
	std::vector<unsigned char> data;
	int width, height;
	LUNAColorType colorType;

public:
	bool IsEmpty();
	const std::vector<unsigned char>& GetData() const;
	int GetWidth() const;
	int GetHeight() const;
	LUNAColorType GetColorType() const;
	bool Load(const std::string& filename, const LUNAImageFormat& format,
		LUNAFileLocation location = LUNAFileLocation::ASSETS);
};

}
