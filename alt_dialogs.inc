//Alternative Dialogs by Nexius v6.5

#if defined _alt_dialogs_included
	#endinput
#endif
#define _alt_dialogs_included

#include <a_samp>

#define AD_VERSION						"6.5"

#define AD_STYLE_LIST					2
#define AD_INVALID_ID					-1

#if !defined AD_FAST_DOUBLE_CLICK
	#define AD_FAST_DOUBLE_CLICK		true
#endif

#if AD_FAST_DOUBLE_CLICK
	#if !defined AD_MAX_CLICK_INTERVAL
		#define AD_MAX_CLICK_INTERVAL	250
	#endif
#endif

#if !defined AD_MAX_DIALOG_PAGES
	#define AD_MAX_DIALOG_PAGES			3	//Change if you want
#endif

#if !defined AD_MAX_CAPTION_LENGTH
	#define AD_MAX_CAPTION_LENGTH		38
#endif

#if !defined AD_MAX_ITEM_LENGTH
	#define AD_MAX_ITEM_LENGTH			40
#endif

#if !defined AD_MAX_BUTTONS_LENGTH
	#define AD_MAX_BUTTONS_LENGTH		6
#endif

#if defined AD_SKIN_1
	#define AD_SELECTION_COLOR				-10
	#define AD_TITLE_COLOR					-75
	#define AD_CLOSE_BUTTON_COLOR			-75
	#define AD_BUTTONS_COLOR				-75
	#define AD_UP_DOWN_BUTTONS_COLOR		-75
	#define AD_ITEMS_COLOR					-75

	#define AD_TITLE_BOX_COLOR				200
	#define AD_PANEL_BOX_COLOR				135
	#define AD_CLOSE_BUTTON_BOX_COLOR		-16777156
	#define AD_BUTTONS_BOX_COLOR			80
	#define AD_SCROLL_BOX_COLOR				-16777170
	#define AD_UP_DOWN_BUTTONS_BOX_COLOR	70
	#define AD_ITEMS_BOX_COLOR				20

	#define AD_SELECTED_ITEM_BOX_COLOR		-16777180
#elseif defined AD_SKIN_2
	#define AD_SELECTION_COLOR				-10
	#define AD_TITLE_COLOR					-75
	#define AD_CLOSE_BUTTON_COLOR			-75
	#define AD_BUTTONS_COLOR				-75
	#define AD_UP_DOWN_BUTTONS_COLOR		-75
	#define AD_ITEMS_COLOR					-75

	#define AD_TITLE_BOX_COLOR				200
	#define AD_PANEL_BOX_COLOR				135
	#define AD_CLOSE_BUTTON_BOX_COLOR		-6291346
	#define AD_BUTTONS_BOX_COLOR			100
	#define AD_SCROLL_BOX_COLOR				-6291370
	#define AD_UP_DOWN_BUTTONS_BOX_COLOR	90
	#define AD_ITEMS_BOX_COLOR				40

	#define AD_SELECTED_ITEM_BOX_COLOR		-6291380
#elseif defined AD_SKIN_3
	#define AD_SELECTION_COLOR				-10
	#define AD_TITLE_COLOR					-75
	#define AD_CLOSE_BUTTON_COLOR			-75
	#define AD_BUTTONS_COLOR				-75
	#define AD_UP_DOWN_BUTTONS_COLOR		-75
	#define AD_ITEMS_COLOR					-75

	#define AD_TITLE_BOX_COLOR				190
	#define AD_PANEL_BOX_COLOR				135
	#define AD_CLOSE_BUTTON_BOX_COLOR		4652900
	#define AD_BUTTONS_BOX_COLOR			90
	#define AD_SCROLL_BOX_COLOR				4652875
	#define AD_UP_DOWN_BUTTONS_BOX_COLOR	80
	#define AD_ITEMS_BOX_COLOR				30

	#define AD_SELECTED_ITEM_BOX_COLOR		4652850
#elseif defined AD_SKIN_4
	#define AD_SELECTION_COLOR				50
	#define AD_TITLE_COLOR					100
	#define AD_CLOSE_BUTTON_COLOR			100
	#define AD_BUTTONS_COLOR				100
	#define AD_UP_DOWN_BUTTONS_COLOR		100
	#define AD_ITEMS_COLOR					100

	#define AD_TITLE_BOX_COLOR				-80
	#define AD_PANEL_BOX_COLOR				-165
	#define AD_CLOSE_BUTTON_BOX_COLOR		-6291346
	#define AD_BUTTONS_BOX_COLOR			-110
	#define AD_UP_DOWN_BUTTONS_BOX_COLOR	-90
	#define AD_ITEMS_BOX_COLOR				-425
	#define AD_SCROLL_BOX_COLOR				-6291370

	#define AD_SELECTED_ITEM_BOX_COLOR		-6291380
#elseif defined AD_SKIN_5
	#define AD_SELECTION_COLOR				50
	#define AD_TITLE_COLOR					100
	#define AD_CLOSE_BUTTON_COLOR			100
	#define AD_BUTTONS_COLOR				100
	#define AD_UP_DOWN_BUTTONS_COLOR		100
	#define AD_ITEMS_COLOR					100

	#define AD_TITLE_BOX_COLOR				-90
	#define AD_PANEL_BOX_COLOR				-165
	#define AD_CLOSE_BUTTON_BOX_COLOR		4652900
	#define AD_BUTTONS_BOX_COLOR			-120
	#define AD_UP_DOWN_BUTTONS_BOX_COLOR	-100
	#define AD_ITEMS_BOX_COLOR				-435
	#define AD_SCROLL_BOX_COLOR				4652875

	#define AD_SELECTED_ITEM_BOX_COLOR		4652850
#else //Default skin
	#define AD_SELECTION_COLOR				-10
	#define AD_TITLE_COLOR					-75
	#define AD_CLOSE_BUTTON_COLOR			-75
	#define AD_BUTTONS_COLOR				-75
	#define AD_UP_DOWN_BUTTONS_COLOR		-75
	#define AD_ITEMS_COLOR					-75

	#define AD_TITLE_BOX_COLOR				110
	#define AD_PANEL_BOX_COLOR				70
	#define AD_CLOSE_BUTTON_BOX_COLOR		-16777156
	#define AD_BUTTONS_BOX_COLOR			50
	#define AD_SCROLL_BOX_COLOR				35
	#define AD_UP_DOWN_BUTTONS_BOX_COLOR	25
	#define AD_ITEMS_BOX_COLOR				15

	#define AD_SELECTED_ITEM_BOX_COLOR		35
#endif

static
	adItemID[MAX_PLAYERS],
	adPageID[MAX_PLAYERS],
	adDialogID[MAX_PLAYERS],
	adMaxItems[MAX_PLAYERS],
	bool:adIgnoreEsc[MAX_PLAYERS],
	#if AD_FAST_DOUBLE_CLICK
		adLastClicked[MAX_PLAYERS],
	#endif

	Text:adArrayTDs[11] = {Text:65535, ...},
	PlayerText:adArrayPTDs[MAX_PLAYERS][21],

	adItems[MAX_PLAYERS][AD_MAX_DIALOG_PAGES * 8][AD_MAX_ITEM_LENGTH char];

forward OnAltDialogResponse(playerid, dialogid, response, listitem);

//To unlock the Easter egg, uncomment the next line...
//#define AD_EASTER_EGG_WHITE_STYLE

#if defined AD_EASTER_EGG_WHITE_STYLE
	#undef AD_SELECTION_COLOR
	#define AD_SELECTION_COLOR				50
	#undef AD_TITLE_COLOR
	#define AD_TITLE_COLOR					100
	#undef AD_CLOSE_BUTTON_COLOR
	#define AD_CLOSE_BUTTON_COLOR			100
	#undef AD_BUTTONS_COLOR
	#define AD_BUTTONS_COLOR				100
	#undef AD_UP_DOWN_BUTTONS_COLOR
	#define AD_UP_DOWN_BUTTONS_COLOR		100
	#undef AD_ITEMS_COLOR
	#define AD_ITEMS_COLOR					100

	#undef AD_TITLE_BOX_COLOR
	#define AD_TITLE_BOX_COLOR				-170
	#undef AD_PANEL_BOX_COLOR
	#define AD_PANEL_BOX_COLOR				-165
	#undef AD_CLOSE_BUTTON_BOX_COLOR
	#define AD_CLOSE_BUTTON_BOX_COLOR		-16777156
	#undef AD_BUTTONS_BOX_COLOR
	#define AD_BUTTONS_BOX_COLOR			-160
	#undef AD_UP_DOWN_BUTTONS_BOX_COLOR
	#define AD_UP_DOWN_BUTTONS_BOX_COLOR	-155
	#undef AD_ITEMS_BOX_COLOR
	#define AD_ITEMS_BOX_COLOR				-450
	#undef AD_SCROLL_BOX_COLOR
	#define AD_SCROLL_BOX_COLOR				-125

	#undef AD_SELECTED_ITEM_BOX_COLOR
	#define AD_SELECTED_ITEM_BOX_COLOR		-80
#endif

public OnGameModeInit()
{
	adArrayTDs[0] = TextDrawCreate(470.0, 140.0, "_"); //Title box
	TextDrawTextSize(adArrayTDs[0], 175.0, 0.0);
	TextDrawLetterSize(adArrayTDs[0], 0.0, 1.3);
	TextDrawUseBox(adArrayTDs[0], 1);
	TextDrawBoxColor(adArrayTDs[0], AD_TITLE_BOX_COLOR);
	#undef AD_TITLE_BOX_COLOR

	adArrayTDs[1] = TextDrawCreate(470.0, 155.0, "_"); //Panel box
	TextDrawTextSize(adArrayTDs[1], 175.0, 0.0);
	TextDrawLetterSize(adArrayTDs[1], 0.0, 17.1);
	TextDrawUseBox(adArrayTDs[1], 1);
	TextDrawBoxColor(adArrayTDs[1], AD_PANEL_BOX_COLOR);
	#undef AD_PANEL_BOX_COLOR

	adArrayTDs[2] = TextDrawCreate(470.0, 140.0, "_"); //Close button box
	TextDrawTextSize(adArrayTDs[2], 446.0, 12.0);
	TextDrawLetterSize(adArrayTDs[2], 0.0, 1.3);
	TextDrawUseBox(adArrayTDs[2], 1);
	TextDrawBoxColor(adArrayTDs[2], AD_CLOSE_BUTTON_BOX_COLOR);
	#undef AD_CLOSE_BUTTON_BOX_COLOR

	adArrayTDs[3] = TextDrawCreate(314.0, 290.5, "_"); //Button 1 box
	TextDrawTextSize(adArrayTDs[3], 264.0, 12.0);
	TextDrawLetterSize(adArrayTDs[3], 0.0, 1.3);
	TextDrawUseBox(adArrayTDs[3], 1);
	TextDrawBoxColor(adArrayTDs[3], AD_BUTTONS_BOX_COLOR);

	adArrayTDs[4] = TextDrawCreate(376.0, 290.5, "_"); //Button 2 box
	TextDrawTextSize(adArrayTDs[4], 325.0, 12.0);
	TextDrawLetterSize(adArrayTDs[4], 0.0, 1.3);
	TextDrawUseBox(adArrayTDs[4], 1);
	TextDrawBoxColor(adArrayTDs[4], AD_BUTTONS_BOX_COLOR);

	adArrayTDs[5] = TextDrawCreate(346.0, 290.5, "_"); //Button 1 box only
	TextDrawTextSize(adArrayTDs[5], 296.0, 12.0);
	TextDrawLetterSize(adArrayTDs[5], 0.0, 1.3);
	TextDrawUseBox(adArrayTDs[5], 1);
	TextDrawBoxColor(adArrayTDs[5], AD_BUTTONS_BOX_COLOR);
	#undef AD_BUTTONS_BOX_COLOR

	adArrayTDs[6] = TextDrawCreate(470.0, 155.0, "_"); //Up button box
	TextDrawTextSize(adArrayTDs[6], 460.0, 5.0);
	TextDrawLetterSize(adArrayTDs[6], 0.0, 1.3);
	TextDrawUseBox(adArrayTDs[6], 1);
	TextDrawBoxColor(adArrayTDs[6], AD_UP_DOWN_BUTTONS_BOX_COLOR);

	adArrayTDs[7] = TextDrawCreate(470.0, 262.0, "_"); //Down button box
	TextDrawTextSize(adArrayTDs[7], 460.0, 5.0);
	TextDrawLetterSize(adArrayTDs[7], 0.0, 1.3);
	TextDrawUseBox(adArrayTDs[7], 1);
	TextDrawBoxColor(adArrayTDs[7], AD_UP_DOWN_BUTTONS_BOX_COLOR);
	#undef AD_UP_DOWN_BUTTONS_BOX_COLOR

	adArrayTDs[8] = TextDrawCreate(454.0, 141.0, "X"); //Close button
	TextDrawFont(adArrayTDs[8], 2);
	TextDrawTextSize(adArrayTDs[8], 465.0, 12.0);
	TextDrawLetterSize(adArrayTDs[8], 0.27, 0.9);
	TextDrawColor(adArrayTDs[8], AD_CLOSE_BUTTON_COLOR);
	#undef AD_CLOSE_BUTTON_COLOR
	TextDrawSetShadow(adArrayTDs[8], 0);
	TextDrawSetSelectable(adArrayTDs[8], 1);

	adArrayTDs[9] = TextDrawCreate(462.3, 165.0, "v"); //Up button
	TextDrawFont(adArrayTDs[9], 2);
	TextDrawTextSize(adArrayTDs[9], 471.0, 4.5);
	TextDrawLetterSize(adArrayTDs[9], 0.18, -0.8);
	TextDrawColor(adArrayTDs[9], AD_UP_DOWN_BUTTONS_COLOR);
	TextDrawSetShadow(adArrayTDs[9], 0);
	TextDrawSetSelectable(adArrayTDs[9], 1);

	adArrayTDs[10] = TextDrawCreate(462.3, 264.0, "v"); //Down button
	TextDrawFont(adArrayTDs[10], 2);
	TextDrawTextSize(adArrayTDs[10], 471.0, 4.5);
	TextDrawLetterSize(adArrayTDs[10], 0.18, 0.8);
	TextDrawColor(adArrayTDs[10], AD_UP_DOWN_BUTTONS_COLOR);
	#undef AD_UP_DOWN_BUTTONS_COLOR
	TextDrawSetShadow(adArrayTDs[10], 0);
	TextDrawSetSelectable(adArrayTDs[10], 1);

	printf("Alternative Dialogs v%s by Nexius loaded!\n", AD_VERSION);
	#if defined ad_OnGameModeInit
		return ad_OnGameModeInit();
	#else
		return 1;
	#endif
}

#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit ad_OnGameModeInit
#if defined ad_OnGameModeInit
	forward ad_OnGameModeInit();
#endif

public OnGameModeExit()
{
	for(new i = sizeof(adArrayTDs) - 1; i >= 0; --i) TextDrawDestroy(adArrayTDs[i]);
	#if defined ad_OnGameModeExit
		return ad_OnGameModeExit();
	#else
		return 1;
	#endif
}

#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit ad_OnGameModeExit
#if defined ad_OnGameModeExit
	forward ad_OnGameModeExit();
#endif

public OnPlayerConnect(playerid)
{
	adIgnoreEsc[playerid] = false;
	adDialogID[playerid] = AD_INVALID_ID;
	for(new i = sizeof(adArrayPTDs[]) - 1; i >= 0; --i) adArrayPTDs[playerid][i] = PlayerText:65535;
	#if defined ad_OnPlayerConnect
		return ad_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}

#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect ad_OnPlayerConnect
#if defined ad_OnPlayerConnect
	forward ad_OnPlayerConnect(playerid);
#endif

public OnPlayerClickTextDraw(playerid, Text:clickedid)
{
	if(adIgnoreEsc[playerid] && _:clickedid == 65535) adIgnoreEsc[playerid] = false;
	else if(adDialogID[playerid] != AD_INVALID_ID)
	{
		if(_:clickedid == 65535 || clickedid == adArrayTDs[8])
		{
			new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
			ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
			CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 2, tmp_itemid);
		}
		else if(clickedid == adArrayTDs[9])
		{
			if(adPageID[playerid] > 0)
			{
				new i, Float:s_size, Float:s_pos;
				adPageID[playerid]--;
				adItemID[playerid] = adPageID[playerid] * 8;
				for(i = 11; i >= 5; --i)
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][i], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][i]);
				}
				PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][4], AD_SELECTED_ITEM_BOX_COLOR);
				PlayerTextDrawShow(playerid, adArrayPTDs[playerid][4]);
				i = adPageID[playerid] * 8;
				for(new j = i + 8, c; i < j; i++)
				{
					PlayerTextDrawSetString(playerid, adArrayPTDs[playerid][12 + c], adItems[playerid][i]);
					if(!adItems[playerid][i]{0}) PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][12 + c], 0);
					else PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][12 + c], 1);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][12 + c]);
					c++;
				}
				PlayerTextDrawDestroy(playerid, adArrayPTDs[playerid][20]);
				s_size = 9.8 / (floatround(adMaxItems[playerid] / 8, floatround_tozero) + 1);
				s_pos = (s_size * 9) * adPageID[playerid];
				adArrayPTDs[playerid][20] = CreatePlayerTextDraw(playerid, 470.0, 170.3 + s_pos, "_"); //Scroll box
				PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][20], 460.0, 5.0);
				PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][20], 0.0, s_size);
				PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][20], 1);
				PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][20], AD_SCROLL_BOX_COLOR);
				PlayerTextDrawShow(playerid, adArrayPTDs[playerid][20]);
			}
		}
		else if(clickedid == adArrayTDs[10])
		{
			if(adPageID[playerid] < floatround(adMaxItems[playerid] / 8, floatround_tozero))
			{
				new i, Float:s_size, Float:s_pos;
				adPageID[playerid]++;
				adItemID[playerid] = adPageID[playerid] * 8;
				for(i = 11; i >= 5; --i)
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][i], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][i]);
				}
				PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][4], AD_SELECTED_ITEM_BOX_COLOR);
				PlayerTextDrawShow(playerid, adArrayPTDs[playerid][4]);
				i = adPageID[playerid] * 8;
				for(new j = i + 8, c; i < j; i++)
				{
					PlayerTextDrawSetString(playerid, adArrayPTDs[playerid][12 + c], adItems[playerid][i]);
					if(!adItems[playerid][i]{0}) PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][12 + c], 0);
					else PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][12 + c], 1);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][12 + c]);
					c++;
				}
				PlayerTextDrawDestroy(playerid, adArrayPTDs[playerid][20]);
				s_size = 9.8 / (floatround(adMaxItems[playerid] / 8, floatround_tozero) + 1);
				s_pos = (s_size * 9) * adPageID[playerid];
				adArrayPTDs[playerid][20] = CreatePlayerTextDraw(playerid, 470.0, 170.3 + s_pos, "_"); //Scroll box
				PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][20], 460.0, 5.0);
				PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][20], 0.0, s_size);
				PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][20], 1);
				PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][20], AD_SCROLL_BOX_COLOR);
				PlayerTextDrawShow(playerid, adArrayPTDs[playerid][20]);
			}
		}
	}
	#if defined ad_OnPlayerClickTextDraw
		return ad_OnPlayerClickTextDraw(playerid, clickedid);
	#else
		return 0;
	#endif
}

#if defined _ALS_OnPlayerClickTextDraw
	#undef OnPlayerClickTextDraw
#else
	#define _ALS_OnPlayerClickTextDraw
#endif
#define OnPlayerClickTextDraw ad_OnPlayerClickTextDraw
#if defined ad_OnPlayerClickTextDraw
	forward ad_OnPlayerClickTextDraw(playerid, Text:clickedid);
#endif

public OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid)
{
	if(adDialogID[playerid] != AD_INVALID_ID)
	{
		if(playertextid == adArrayPTDs[playerid][1] || playertextid == adArrayPTDs[playerid][2])
		{
			new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
			ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
			CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
		}
		else if(playertextid == adArrayPTDs[playerid][3])
		{
			new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
			ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
			CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 0, tmp_itemid);
		}
		else
		{
			#if AD_FAST_DOUBLE_CLICK
				new gtc = GetTickCount();
			#endif
			if(playertextid == adArrayPTDs[playerid][12])
			{
				if(adItemID[playerid] == 0 + (adPageID[playerid] * 8))
				{
					#if AD_FAST_DOUBLE_CLICK
						if(gtc - adLastClicked[playerid] <= AD_MAX_CLICK_INTERVAL)
						{
							adLastClicked[playerid] = 0;
					#endif
					new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
					ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
					CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
					#if AD_FAST_DOUBLE_CLICK
						}
						else adLastClicked[playerid] = gtc;
					#endif
				}
				else
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][4], AD_SELECTED_ITEM_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][4]);
					if(adItemID[playerid] > 7) adItemID[playerid] %= 8;
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4]);
					adItemID[playerid] = 0 + (adPageID[playerid] * 8);
					#if AD_FAST_DOUBLE_CLICK
						adLastClicked[playerid] = gtc;
					#endif
				}
			}
			else if(playertextid == adArrayPTDs[playerid][13])
			{
				if(adItemID[playerid] == 1 + (adPageID[playerid] * 8))
				{
					#if AD_FAST_DOUBLE_CLICK
						if(gtc - adLastClicked[playerid] <= AD_MAX_CLICK_INTERVAL)
						{
							adLastClicked[playerid] = 0;
					#endif
					new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
					ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
					CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
					#if AD_FAST_DOUBLE_CLICK
						}
						else adLastClicked[playerid] = gtc;
					#endif
				}
				else
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][5], AD_SELECTED_ITEM_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][5]);
					if(adItemID[playerid] > 7) adItemID[playerid] %= 8;
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4]);
					adItemID[playerid] = 1 + (adPageID[playerid] * 8);
					#if AD_FAST_DOUBLE_CLICK
						adLastClicked[playerid] = gtc;
					#endif
				}
			}
			else if(playertextid == adArrayPTDs[playerid][14])
			{
				if(adItemID[playerid] == 2 + (adPageID[playerid] * 8))
				{
					#if AD_FAST_DOUBLE_CLICK
						if(gtc - adLastClicked[playerid] <= AD_MAX_CLICK_INTERVAL)
						{
							adLastClicked[playerid] = 0;
					#endif
					new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
					ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
					CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
					#if AD_FAST_DOUBLE_CLICK
						}
						else adLastClicked[playerid] = gtc;
					#endif
				}
				else
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][6], AD_SELECTED_ITEM_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][6]);
					if(adItemID[playerid] > 7) adItemID[playerid] %= 8;
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4]);
					adItemID[playerid] = 2 + (adPageID[playerid] * 8);
					#if AD_FAST_DOUBLE_CLICK
						adLastClicked[playerid] = gtc;
					#endif
				}
			}
			else if(playertextid == adArrayPTDs[playerid][15])
			{
				if(adItemID[playerid] == 3 + (adPageID[playerid] * 8))
				{
					#if AD_FAST_DOUBLE_CLICK
						if(gtc - adLastClicked[playerid] <= AD_MAX_CLICK_INTERVAL)
						{
							adLastClicked[playerid] = 0;
					#endif
					new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
					ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
					CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
					#if AD_FAST_DOUBLE_CLICK
						}
						else adLastClicked[playerid] = gtc;
					#endif
				}
				else
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][7], AD_SELECTED_ITEM_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][7]);
					if(adItemID[playerid] > 7) adItemID[playerid] %= 8;
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4]);
					adItemID[playerid] = 3 + (adPageID[playerid] * 8);
					#if AD_FAST_DOUBLE_CLICK
						adLastClicked[playerid] = gtc;
					#endif
				}
			}
			else if(playertextid == adArrayPTDs[playerid][16])
			{
				if(adItemID[playerid] == 4 + (adPageID[playerid] * 8))
				{
					#if AD_FAST_DOUBLE_CLICK
						if(gtc - adLastClicked[playerid] <= AD_MAX_CLICK_INTERVAL)
						{
							adLastClicked[playerid] = 0;
					#endif
					new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
					ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
					CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
					#if AD_FAST_DOUBLE_CLICK
						}
						else adLastClicked[playerid] = gtc;
					#endif
				}
				else
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][8], AD_SELECTED_ITEM_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][8]);
					if(adItemID[playerid] > 7) adItemID[playerid] %= 8;
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4]);
					adItemID[playerid] = 4 + (adPageID[playerid] * 8);
					#if AD_FAST_DOUBLE_CLICK
						adLastClicked[playerid] = gtc;
					#endif
				}
			}
			else if(playertextid == adArrayPTDs[playerid][17])
			{
				if(adItemID[playerid] == 5 + (adPageID[playerid] * 8))
				{
					#if AD_FAST_DOUBLE_CLICK
						if(gtc - adLastClicked[playerid] <= AD_MAX_CLICK_INTERVAL)
						{
							adLastClicked[playerid] = 0;
					#endif
					new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
					ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
					CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
					#if AD_FAST_DOUBLE_CLICK
						}
						else adLastClicked[playerid] = gtc;
					#endif
				}
				else
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][9], AD_SELECTED_ITEM_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][9]);
					if(adItemID[playerid] > 7) adItemID[playerid] %= 8;
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4]);
					adItemID[playerid] = 5 + (adPageID[playerid] * 8);
					#if AD_FAST_DOUBLE_CLICK
						adLastClicked[playerid] = gtc;
					#endif
				}
			}
			else if(playertextid == adArrayPTDs[playerid][18])
			{
				if(adItemID[playerid] == 6 + (adPageID[playerid] * 8))
				{
					#if AD_FAST_DOUBLE_CLICK
						if(gtc - adLastClicked[playerid] <= AD_MAX_CLICK_INTERVAL)
						{
							adLastClicked[playerid] = 0;
					#endif
					new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
					ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
					CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
					#if AD_FAST_DOUBLE_CLICK
						}
						else adLastClicked[playerid] = gtc;
					#endif
				}
				else
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][10], AD_SELECTED_ITEM_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][10]);
					if(adItemID[playerid] > 7) adItemID[playerid] %= 8;
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4]);
					adItemID[playerid] = 6 + (adPageID[playerid] * 8);
					#if AD_FAST_DOUBLE_CLICK
						adLastClicked[playerid] = gtc;
					#endif
				}
			}
			else if(playertextid == adArrayPTDs[playerid][19])
			{
				if(adItemID[playerid] == 7 + (adPageID[playerid] * 8))
				{
					#if AD_FAST_DOUBLE_CLICK
						if(gtc - adLastClicked[playerid] <= AD_MAX_CLICK_INTERVAL)
						{
							adLastClicked[playerid] = 0;
					#endif
					new tmp_dialogid = adDialogID[playerid], tmp_itemid = adItemID[playerid];
					ShowPlayerAltDialog(playerid, AD_INVALID_ID, -1, "", "", "");
					CallRemoteFunction("OnAltDialogResponse", "iiii", playerid, tmp_dialogid, 1, tmp_itemid);
					#if AD_FAST_DOUBLE_CLICK
						}
						else adLastClicked[playerid] = gtc;
					#endif
				}
				else
				{
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][11], AD_SELECTED_ITEM_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][11]);
					if(adItemID[playerid] > 7) adItemID[playerid] %= 8;
					PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4], AD_ITEMS_BOX_COLOR);
					PlayerTextDrawShow(playerid, adArrayPTDs[playerid][adItemID[playerid] + 4]);
					adItemID[playerid] = 7 + (adPageID[playerid] * 8);
					#if AD_FAST_DOUBLE_CLICK
						adLastClicked[playerid] = gtc;
					#endif
				}
			}
		}
	}
	#if defined ad_OnPlayerClickPlayerTextDraw
		return ad_OnPlayerClickPlayerTextDraw(playerid, playertextid);
	#else
		return 0;
	#endif
}

#if defined _ALS_OnPlayerClickPlayerTextDra\
	|| defined _ALS_OnPlayerClickPlayerTD
	#undef OnPlayerClickPlayerTextDraw
#else
	#define _ALS_OnPlayerClickPlayerTextDra
	#define _ALS_OnPlayerClickPlayerTD
#endif
#define OnPlayerClickPlayerTextDraw ad_OnPlayerClickPlayerTextDraw
#if defined ad_OnPlayerClickPlayerTextDraw
	forward ad_OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
#endif

#if AD_FAST_DOUBLE_CLICK
	#undef AD_MAX_CLICK_INTERVAL
#endif

#undef AD_FAST_DOUBLE_CLICK

ShowPlayerAltDialog(playerid, dialogid, style, caption[], info[], button1[], button2[] = "")
{
	if(IsPlayerConnected(playerid))
	{
		new i;
		adDialogID[playerid] = AD_INVALID_ID;
		for(i = (AD_MAX_DIALOG_PAGES * 8) - 1; i >= 0; --i) adItems[playerid][i]{0} = EOS;
		#undef AD_MAX_DIALOG_PAGES
		for(i = sizeof(adArrayTDs) - 1; i >= 0; --i) TextDrawHideForPlayer(playerid, adArrayTDs[i]);
		for(i = sizeof(adArrayPTDs[]) - 1; i >= 0; --i)
		{
			PlayerTextDrawDestroy(playerid, adArrayPTDs[playerid][i]);
			adArrayPTDs[playerid][i] = PlayerText:65535;
		}
		if(dialogid <= AD_INVALID_ID)
		{
			adIgnoreEsc[playerid] = true;
			return CancelSelectTextDraw(playerid);
		}
		if(style == AD_STYLE_LIST)
		{
			adPageID[playerid] = 0;
			adItemID[playerid] = 0;
			adDialogID[playerid] = dialogid;

			adArrayPTDs[playerid][4] = CreatePlayerTextDraw(playerid, 464.0, 155.0, "_"); //Item 1 box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][4], 181.0, 12.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][4], 0.0, 1.3);
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][4], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][4], AD_SELECTED_ITEM_BOX_COLOR);
			#undef AD_SELECTED_ITEM_BOX_COLOR

			adArrayPTDs[playerid][5] = CreatePlayerTextDraw(playerid, 464.0, 170.5, "_"); //Item 2 box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][5], 181.0, 12.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][5], 0.0, 1.3);
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][5], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][5], AD_ITEMS_BOX_COLOR);

			adArrayPTDs[playerid][6] = CreatePlayerTextDraw(playerid, 464.0, 185.8, "_"); //Item 3 box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][6], 181.0, 12.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][6], 0.0, 1.3);
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][6], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][6], AD_ITEMS_BOX_COLOR);

			adArrayPTDs[playerid][7] = CreatePlayerTextDraw(playerid, 464.0, 201.0, "_"); //Item 4 box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][7], 181.0, 12.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][7], 0.0, 1.3);
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][7], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][7], AD_ITEMS_BOX_COLOR);

			adArrayPTDs[playerid][8] = CreatePlayerTextDraw(playerid, 464.0, 216.2, "_"); //Item 5 box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][8], 181.0, 12.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][8], 0.0, 1.3);
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][8], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][8], AD_ITEMS_BOX_COLOR);

			adArrayPTDs[playerid][9] = CreatePlayerTextDraw(playerid, 464.0, 231.2, "_"); //Item 6 box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][9], 181.0, 12.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][9], 0.0, 1.3);
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][9], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][9], AD_ITEMS_BOX_COLOR);

			adArrayPTDs[playerid][10] = CreatePlayerTextDraw(playerid, 464.0, 246.5, "_"); //Item 7 box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][10], 181.0, 12.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][10], 0.0, 1.3);
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][10], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][10], AD_ITEMS_BOX_COLOR);

			adArrayPTDs[playerid][11] = CreatePlayerTextDraw(playerid, 464.0, 261.8, "_"); //Item 8 box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][11], 181.0, 12.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][11], 0.0, 1.3);
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][11], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][11], AD_ITEMS_BOX_COLOR);
			#undef AD_ITEMS_BOX_COLOR

			adArrayPTDs[playerid][12] = CreatePlayerTextDraw(playerid, 191.0, 156.3, ""); //Item 1
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][12], 2);
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][12], 460.0, 13.6);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][12], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][12], AD_ITEMS_COLOR);
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][12], 0);
			PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][12], 1);

			adArrayPTDs[playerid][13] = CreatePlayerTextDraw(playerid, 191.0, 171.8, ""); //Item 2
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][13], 2);
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][13], 460.0, 13.6);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][13], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][13], AD_ITEMS_COLOR);
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][13], 0);
			PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][13], 1);

			adArrayPTDs[playerid][14] = CreatePlayerTextDraw(playerid, 191.0, 187.3, ""); //Item 3
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][14], 2);
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][14], 460.0, 13.6);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][14], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][14], AD_ITEMS_COLOR);
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][14], 0);
			PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][14], 1);

			adArrayPTDs[playerid][15] = CreatePlayerTextDraw(playerid, 191.0, 202.6, ""); //Item 4
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][15], 2);
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][15], 460.0, 13.6);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][15], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][15], AD_ITEMS_COLOR);
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][15], 0);
			PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][15], 1);

			adArrayPTDs[playerid][16] = CreatePlayerTextDraw(playerid, 191.0, 217.6, ""); //Item 5
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][16], 2);
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][16], 460.0, 13.6);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][16], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][16], AD_ITEMS_COLOR);
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][16], 0);
			PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][16], 1);

			adArrayPTDs[playerid][17] = CreatePlayerTextDraw(playerid, 191.0, 232.7, ""); //Item 6
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][17], 2);
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][17], 460.0, 13.6);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][17], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][17], AD_ITEMS_COLOR);
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][17], 0);
			PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][17], 1);

			adArrayPTDs[playerid][18] = CreatePlayerTextDraw(playerid, 191.0, 247.9, ""); //Item 7
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][18], 2);
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][18], 460.0, 13.6);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][18], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][18], AD_ITEMS_COLOR);
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][18], 0);
			PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][18], 1);

			adArrayPTDs[playerid][19] = CreatePlayerTextDraw(playerid, 191.0, 263.0, ""); //Item 8
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][19], 2);
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][19], 460.0, 13.6);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][19], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][19], AD_ITEMS_COLOR);
			#undef AD_ITEMS_COLOR
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][19], 0);
			PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][19], 1);

			if(strlen(caption) >= AD_MAX_CAPTION_LENGTH)
			{
				caption[AD_MAX_CAPTION_LENGTH - 3] = '.';
				caption[AD_MAX_CAPTION_LENGTH - 2] = '.';
				caption[AD_MAX_CAPTION_LENGTH - 1] = '.';
				caption[AD_MAX_CAPTION_LENGTH] = EOS;
				#undef AD_MAX_CAPTION_LENGTH
			}

			adArrayPTDs[playerid][0] = CreatePlayerTextDraw(playerid, 188.0, 141.0, caption); //Title
			PlayerTextDrawFont(playerid, adArrayPTDs[playerid][0], 2);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][0], 0.27, 0.9);
			PlayerTextDrawColor(playerid, adArrayPTDs[playerid][0], AD_TITLE_COLOR);
			#undef AD_TITLE_COLOR
			PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][0], 0);

			if(strlen(button1) >= AD_MAX_BUTTONS_LENGTH) button1[AD_MAX_BUTTONS_LENGTH] = EOS;
			new b2_len = strlen(button2);
			if(b2_len > 0)
			{
				adArrayPTDs[playerid][1] = CreatePlayerTextDraw(playerid, 289.0, 292.0, button1); //Button 1
				PlayerTextDrawAlignment(playerid, adArrayPTDs[playerid][1], 2);
				PlayerTextDrawFont(playerid, adArrayPTDs[playerid][1], 2);
				PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][1], 12.0, 38.0);
				PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][1], 0.27, 0.9);
				PlayerTextDrawColor(playerid, adArrayPTDs[playerid][1], AD_BUTTONS_COLOR);
				PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][1], 0);
				PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][1], 1);

				if(b2_len >= AD_MAX_BUTTONS_LENGTH) button2[AD_MAX_BUTTONS_LENGTH] = EOS;
				#undef AD_MAX_BUTTONS_LENGTH

				adArrayPTDs[playerid][3] = CreatePlayerTextDraw(playerid, 350.5, 292.0, button2); //Button 2
				PlayerTextDrawAlignment(playerid, adArrayPTDs[playerid][3], 2);
				PlayerTextDrawFont(playerid, adArrayPTDs[playerid][3], 2);
				PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][3], 12.0, 38.0);
				PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][3], 0.27, 0.9);
				PlayerTextDrawColor(playerid, adArrayPTDs[playerid][3], AD_BUTTONS_COLOR);
				PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][3], 0);
				PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][3], 1);
			}
			else
			{
				adArrayPTDs[playerid][2] = CreatePlayerTextDraw(playerid, 321.0, 292.0, button1); //Button 1 only
				PlayerTextDrawAlignment(playerid, adArrayPTDs[playerid][2], 2);
				PlayerTextDrawFont(playerid, adArrayPTDs[playerid][2], 2);
				PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][2], 12.0, 38.0);
				PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][2], 0.27, 0.9);
				PlayerTextDrawColor(playerid, adArrayPTDs[playerid][2], AD_BUTTONS_COLOR);
				#undef AD_BUTTONS_COLOR
				PlayerTextDrawSetShadow(playerid, adArrayPTDs[playerid][2], 0);
				PlayerTextDrawSetSelectable(playerid, adArrayPTDs[playerid][2], 1);
			}
			i = 0;
			new c = -1;
			for(new j, strtmp[AD_MAX_ITEM_LENGTH], s = strlen(info); i <= s; i++)
			{
				#undef AD_MAX_ITEM_LENGTH
				if(info[i] == '\n' || i == s)
				{
					if(c + 1 >= sizeof adItems[]) break;
					c++;
					strmid(strtmp, info, j, i);
					strpack(adItems[playerid][c], strtmp);
					if(i - j >= sizeof adItems[][] * (cellbits / charbits))
					{
						adItems[playerid][c]{(sizeof(adItems[][]) * (cellbits / charbits)) - 3} = '.';
						adItems[playerid][c]{(sizeof(adItems[][]) * (cellbits / charbits)) - 2} = '.';
						adItems[playerid][c]{(sizeof(adItems[][]) * (cellbits / charbits)) - 1} = '.';
					}
					if(c < 8) PlayerTextDrawSetString(playerid, adArrayPTDs[playerid][12 + c], adItems[playerid][c]);
					j = i + 1;
				}
			}
			adMaxItems[playerid] = c;

			adArrayPTDs[playerid][20] = CreatePlayerTextDraw(playerid, 470.0, 170.3, "_"); //Scroll box
			PlayerTextDrawTextSize(playerid, adArrayPTDs[playerid][20], 460.0, 5.0);
			PlayerTextDrawLetterSize(playerid, adArrayPTDs[playerid][20], 0.0, 9.8 / (floatround(c / 8, floatround_tozero) + 1));
			PlayerTextDrawUseBox(playerid, adArrayPTDs[playerid][20], 1);
			PlayerTextDrawBoxColor(playerid, adArrayPTDs[playerid][20], AD_SCROLL_BOX_COLOR);
			#undef AD_SCROLL_BOX_COLOR

			for(i = sizeof(adArrayTDs) - 1; i >= 0; --i)
			{
				if(c < 8 && (6 <= i <= 7 || 9 <= i <= 10)
				|| b2_len > 0 && i == 5 || b2_len == 0 && 3 <= i <= 4) continue;
				TextDrawShowForPlayer(playerid, adArrayTDs[i]);
			}
			for(i = sizeof(adArrayPTDs[]) - 1; i >= 0; --i)
			{
				if(c < 8 && i == 20) continue;
				PlayerTextDrawShow(playerid, adArrayPTDs[playerid][i]);
			}
			return SelectTextDraw(playerid, AD_SELECTION_COLOR);
			#undef AD_SELECTION_COLOR
		}
	}
	return 0;
}

stock GetPlayerAltDialog(playerid)
{
	if(!IsPlayerConnected(playerid)) return AD_INVALID_ID;
	return adDialogID[playerid];
}
