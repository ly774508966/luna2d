﻿//
// App.xaml.h
// Declaration of the App class.
//

#pragma once

#include "App.g.h"

namespace LUNA_PROJECT_NAME
{
	/// <summary>
	/// Provides application-specific behavior to supplement the default Application class.
	/// </summary>
	ref class App sealed
	{
	public:
		App();

		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override;

	private:
		luna2d::OpenGLESPage^ mPage;
	};
}
