//-----------------------------------------------------------------------------
// luna2d engine
// Copyright 2014-2017 Stepan Prokofjev
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

#include "lunaads.h"
#include "lunalua.h"
#include "lunaconfig.h"

using namespace luna2d;

static LuaTable GetAdsTable()
{
	return LUNAEngine::SharedLua()->GetGlobalTable().GetTable("luna").GetTable("ads");
}

// Load services from config
void LUNAAds::LoadServices()
{
	auto config = LUNAEngine::Shared()->GetConfig();
	std::string serviceName = config->GetCustomValues()["adsService"].string_value();
	
	if(serviceName.empty()) return;
	
	service = LoadService(serviceName);
}

// Check for interstitial is downloaded ready to showing
bool LUNAAds::IsInterstitalReady()
{
	if(!service) return false;

	return service->IsInterstitalReady();
}

// Check for rewarded video is downloaded ready to showing
bool LUNAAds::IsRewardedVideoReady()
{
	if(!service) return false;

	return service->IsRewardedVideoReady();
}

// Show interstitial
void LUNAAds::ShowInterstital()
{
	if(!service) return;

	service->ShowInterstital();
}

// Show rewarded video
void LUNAAds::ShowRewardedVideo()
{
	if(!service) return;

	service->ShowRewardedVideo();
}

// Called when video has been succesfully viewed
void LUNAAds::OnRewardedVideoSuccess()
{
	auto tblAds = GetAdsTable();
	auto fnSuccess = tblAds.GetFunction("onRewardedVideoSuccess");
	
	if(fnSuccess) fnSuccess.CallVoid();
}

// Called when video has been dismissed or in case of error
void LUNAAds::OnRewardedVideoFail()
{
	auto tblAds = GetAdsTable();
	auto fnFail = tblAds.GetFunction("onRewardedVideoFail");
	
	if(fnFail) fnFail.CallVoid();
}
