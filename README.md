# [Alternative Dialogs](https://pawn.wiki/index.php?/topic/29973-alternative-dialogs/)
These dialogs have nearly all of the functions that the default dialogs have, but they can be used together.  
The new design drawn via textdraws, it will radically change the interface of your server.

## How do they look
AD_STYLE_LIST / [SKINS](https://imgur.com/a/Vounp)  
![](https://i.imgur.com/8sAdgUy.png)

To choose any of the available skins, just write the following before connecting the include:
```pawn
#define AD_SKIN_1 //1 - ID of the skin
```

## How to install
Simply install to your project:
```bash
sampctl package install NexiusTailer/Alternative-Dialogs
```

Include in your code and begin using the library:
```pawn
#include <alt_dialogs>
```

## Functions
* ShowPlayerAltDialog`(playerid, dialogid, style, caption[], info[], button1[], button2[] = "")`  
Use to show the dialog for a player
* OnAltDialogResponse`(playerid, dialogid, response, listitem)`  
Called when a player "response" on the dialog
* GetPlayerAltDialog`(playerid)`  
Use to get a player's current dialog ID

## Usage example
```pawn
public OnPlayerCommandText(playerid, cmdtext[])
{
	if(!strcmp("/wdialog", cmdtext, true)) return cmd_wdialog(playerid);
	return 0;
}

forward cmd_wdialog(playerid);
public cmd_wdialog(playerid)
{
	ShowPlayerAltDialog(playerid, 0, AD_STYLE_LIST, "Weapons", "AK47\nM4\nSniper Rifle", "Ok", "Cancel");
	return 1;
}

public OnAltDialogResponse(playerid, dialogid, response, listitem)
{
	if(dialogid == 0)
	{
		if(response == 1)
		{
			switch(listitem)
			{
				case 0: GivePlayerWeapon(playerid, 30, 100);
				case 1: GivePlayerWeapon(playerid, 31, 100);
				case 2: GivePlayerWeapon(playerid, 34, 50);
			}
			return 1;
		}
	}
	return 0;
}
```

## Thanks
Zamaroht and adri1 for [Zamaroht's Textdraw Editor](https://sampforum.blast.hk/showthread.php?tid=406833)

## Frequently asked Questions
**Q:** How to hide the shown dialog?  
**A:** This can be done like in default dialogs.  
Use `ShowPlayerAltDialog` function, specifying `dialogid` parameter with the value of -1.

**Q:** What does the `response` parameter mean with the value of 2 in `OnAltDialogResponse`?  
**A:** This means that the dialog was closed by pressing the `"cross"` button or by `ESC`.

**Q:** How to make the separate words in the dialog colored?  
**A:** In this case you can use [that](https://team.sa-mp.com/wiki/GameText_Styles).

This section will be updated as questions are received.
