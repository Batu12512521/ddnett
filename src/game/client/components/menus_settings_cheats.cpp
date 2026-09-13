/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */

#include "menus.h"

#include <engine/shared/config.h>

#include <game/client/ui.h>
#include <game/localization.h>

void CMenus::RenderSettingsCheats(CUIRect MainView)
{
	CUIRect Label, Button;

	MainView.HSplitTop(30.0f, &Label, &MainView);
	Ui()->DoLabel(&Label, Localize("Cheats"), 20.0f, TEXTALIGN_ML);
	MainView.HSplitTop(5.0f, nullptr, &MainView);

	MainView.HSplitTop(20.0f, &Button, &MainView);
	if(DoButton_CheckBox(&g_Config.m_ClAimbot, Localize("Aimbot"), g_Config.m_ClAimbot, &Button))
		g_Config.m_ClAimbot ^= 1;

	MainView.HSplitTop(20.0f, &Button, &MainView);
	Ui()->DoScrollbarOption(&g_Config.m_ClAimbotFov, &g_Config.m_ClAimbotFov, &Button, Localize("Fov"), 0, 360);

	MainView.HSplitTop(20.0f, &Button, &MainView);
	if(DoButton_CheckBox(&g_Config.m_ClDrawlines, Localize("Drawlines"), g_Config.m_ClDrawlines, &Button))
		g_Config.m_ClDrawlines ^= 1;
}