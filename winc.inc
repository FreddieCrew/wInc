#include <a_samp>

#define Warning:%0(%1,%2) \
	forward WNG_%0(%1,%2);public WNG_%0(%1,%2)

enum WNGInfo
{
	__callback[32],
	__timer
}
new __Warning_Info[MAX_PLAYERS][WNGInfo], PlayerText:Warning[MAX_PLAYERS][4], Float:loadingbar[MAX_PLAYERS] = 0.0;

/*
native CreateWarning(playerid, const callback[], const title[], const params[], timer = 80)
*/

#define show_warning(%0, %1, warning(%0, #%1,
stock CreateWarning(playerid, const callback[], const title[], const params[], timer = 80)
{
    LoadTDE_Warning(playerid);
    loadingbar[playerid] = 0.0;
    format(__Warning_Info[playerid][__callback], 32, "WNG_%s", callback);
    PlayerTextDrawSetString(playerid, Warning[playerid][2], title);
    PlayerTextDrawSetString(playerid, Warning[playerid][3], params);
    for(new i = 0; i < 4; i++)
        PlayerTextDrawShow(playerid, Warning[playerid][i]);
    SetTimerEx("warning_update", (__Warning_Info[playerid][__timer]=timer), false, "i", playerid);
    return 1;
}

stock LoadTDE_Warning(playerid)
{
    Warning[playerid][0] = CreatePlayerTextDraw(playerid, 230.000000, 320.000000, "_");
    PlayerTextDrawFont(playerid, Warning[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, Warning[playerid][0], 0.649999, 4.800001);
    PlayerTextDrawTextSize(playerid, Warning[playerid][0], 412.500000, 77.000000);
    PlayerTextDrawSetOutline(playerid, Warning[playerid][0], 3);
    PlayerTextDrawSetShadow(playerid, Warning[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, Warning[playerid][0], 1);
    PlayerTextDrawColor(playerid, Warning[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, Warning[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, Warning[playerid][0], 269488383);
    PlayerTextDrawUseBox(playerid, Warning[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, Warning[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, Warning[playerid][0], 0);

    Warning[playerid][1] = CreatePlayerTextDraw(playerid, 230.000000, 364.000000, "_");
    PlayerTextDrawFont(playerid, Warning[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, Warning[playerid][1], 0.649999, -0.050000);
    PlayerTextDrawTextSize(playerid, Warning[playerid][1], 412.500000, 75.500000);
    PlayerTextDrawSetOutline(playerid, Warning[playerid][1], 3);
    PlayerTextDrawSetShadow(playerid, Warning[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, Warning[playerid][1], 1);
    PlayerTextDrawColor(playerid, Warning[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, Warning[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, Warning[playerid][1], 1097458175);
    PlayerTextDrawUseBox(playerid, Warning[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, Warning[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, Warning[playerid][1], 0);

    Warning[playerid][2] = CreatePlayerTextDraw(playerid, 243.000000, 324.000000, "WARNING:");
    PlayerTextDrawFont(playerid, Warning[playerid][2], 1);
    PlayerTextDrawLetterSize(playerid, Warning[playerid][2], 0.229166, 1.050000);
    PlayerTextDrawTextSize(playerid, Warning[playerid][2], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, Warning[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, Warning[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, Warning[playerid][2], 1);
    PlayerTextDrawColor(playerid, Warning[playerid][2], 1097458175);
    PlayerTextDrawBackgroundColor(playerid, Warning[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, Warning[playerid][2], 50);
    PlayerTextDrawUseBox(playerid, Warning[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, Warning[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, Warning[playerid][2], 0);

    Warning[playerid][3] = CreatePlayerTextDraw(playerid, 238.000000, 333.000000, "_");
    PlayerTextDrawFont(playerid, Warning[playerid][3], 1);
    PlayerTextDrawLetterSize(playerid, Warning[playerid][3], 0.150000, 0.750000);
    PlayerTextDrawTextSize(playerid, Warning[playerid][3], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, Warning[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, Warning[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, Warning[playerid][3], 1);
    PlayerTextDrawColor(playerid, Warning[playerid][3], -160);
    PlayerTextDrawBackgroundColor(playerid, Warning[playerid][3], 255);
    PlayerTextDrawBoxColor(playerid, Warning[playerid][3], 50);
    PlayerTextDrawUseBox(playerid, Warning[playerid][3], 0);
    PlayerTextDrawSetProportional(playerid, Warning[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, Warning[playerid][3], 0);
    return 1;
}

forward warning_update(playerid);
public warning_update(playerid)
{
    if(loadingbar[playerid] > 104)
    {
        for(new i = 0; i < 4; i++)
            PlayerTextDrawDestroy(playerid, Warning[playerid][i]);
        return false;
    }
    SetTimerEx("swarning_update", __Warning_Info[playerid][__timer], false, "i", playerid);
    PlayerTextDrawTextSize(playerid, Warning[playerid][1], 412.500000 - (loadingbar[playerid]*1.82), 1.0);
    PlayerTextDrawShow(playerid, Warning[playerid][1]);
    loadingbar[playerid] += 0.8;
    return CallLocalFunction(__Warning_Info[playerid][__callback], "if", playerid, loadingbar[playerid]);
}

