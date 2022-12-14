#if defined _winc_included
	#endinput
#endif

#define Warning:%0(%1,%2) \
	forward WNG_%0(%1,%2);public WNG_%0(%1,%2)

	#if !defined _samp_included
	#tryinclude <a_samp>
	#if !defined _samp_included
		#error winc could not find a_samp.inc file, please check your server includes
	#endif
#endif

#pragma warning disable 238


enum WNGInfo
{
	__callback[32],
	__timer
}
new __Warning_Info[MAX_PLAYERS][WNGInfo], PlayerText:WarningTD[MAX_PLAYERS][4], Float:loadingbar[MAX_PLAYERS] = 0.0;

#if !defined FixText
stock FixText(string[])
{
    new szFixed[1024], iPos, iLen;

    for(iLen = strlen(string); iPos < iLen; iPos ++)
        switch(string[iPos])
        {
            case '%':          szFixed[iPos] = 37;
            case '&':          szFixed[iPos] = 38;
            case '¡':          szFixed[iPos] = 64;
            case '°':          szFixed[iPos] = 124;
            case 'À':          szFixed[iPos] = 128;
            case 'Á':          szFixed[iPos] = 129;
            case 'Â':          szFixed[iPos] = 130;
            case 'Ä', 'Ã':     szFixed[iPos] = 131;
            case 'Ç':          szFixed[iPos] = 133;
            case 'È':          szFixed[iPos] = 134;
            case 'É':          szFixed[iPos] = 135;
            case 'Ê':          szFixed[iPos] = 136;
            case 'Ë':          szFixed[iPos] = 137;
            case 'Ì':          szFixed[iPos] = 138;
            case 'Í':          szFixed[iPos] = 139;
            case 'Î':          szFixed[iPos] = 140;
            case 'Ï':          szFixed[iPos] = 141;
            case 'Ò':          szFixed[iPos] = 142;
            case 'Ó':          szFixed[iPos] = 143;
            case 'Ô':          szFixed[iPos] = 144;
            case 'Ö', 'Õ':     szFixed[iPos] = 145;
            case 'Ù':          szFixed[iPos] = 146;
            case 'Ú':          szFixed[iPos] = 147;
            case 'Û':          szFixed[iPos] = 148;
            case 'Ü':          szFixed[iPos] = 149;
            case 'à':          szFixed[iPos] = 151;
            case 'á':          szFixed[iPos] = 152;
            case 'â':          szFixed[iPos] = 153;
            case 'ä', 'ã':     szFixed[iPos] = 154;
            case 'ç':          szFixed[iPos] = 156;
            case 'è':          szFixed[iPos] = 157;
            case 'é':          szFixed[iPos] = 158;
            case 'ê':          szFixed[iPos] = 159;
            case 'ë':          szFixed[iPos] = 160;
            case 'ì':          szFixed[iPos] = 161;
            case 'í':          szFixed[iPos] = 162;
            case 'î':          szFixed[iPos] = 163;
            case 'ï':          szFixed[iPos] = 164;
            case 'ò':          szFixed[iPos] = 165;
            case 'ó':          szFixed[iPos] = 166;
            case 'ô':          szFixed[iPos] = 167;
            case 'ö', 'õ':     szFixed[iPos] = 168;
            case 'ù':          szFixed[iPos] = 169;
            case 'ú':          szFixed[iPos] = 170;
            case 'û':          szFixed[iPos] = 171;
            case 'ü':          szFixed[iPos] = 172;
            case 'Ñ':          szFixed[iPos] = 173;
            case 'ñ':          szFixed[iPos] = 174;
            case '¿':          szFixed[iPos] = 175;
            case '`':          szFixed[iPos] = 177;
            default:           szFixed[iPos] = string[iPos];
          }
    return szFixed;
}
#endif


/*
native CreateWarning(playerid, const callback[], const title[], const params[], timer = 80, fixtext = 0)
*/

#define show_warning(%0, %1, warning(%0, %1)
stock CreateWarning(playerid, const callback[], title[], params[], timer = 80)
{
	LoadTDE_Warning(playerid);
    loadingbar[playerid] = 0.0;
    format(__Warning_Info[playerid][__callback], 32, "WNG_%s", callback);
    PlayerTextDrawSetString(playerid, WarningTD[playerid][2], title);
    PlayerTextDrawSetString(playerid, WarningTD[playerid][3], params);
    for(new i = 0; i < 4; i++)
    PlayerTextDrawShow(playerid, WarningTD[playerid][i]);
    SetTimerEx("warning_update", (__Warning_Info[playerid][__timer]=timer), false, "i", playerid);
	return 1;
}

stock LoadTDE_Warning(playerid)
{
    WarningTD[playerid][0] = CreatePlayerTextDraw(playerid, 230.000000, 320.000000, "_");
    PlayerTextDrawFont(playerid, WarningTD[playerid][0], 1);
    PlayerTextDrawLetterSize(playerid, WarningTD[playerid][0], 0.649999, 4.800001);
    PlayerTextDrawTextSize(playerid, WarningTD[playerid][0], 412.500000, 77.000000);
    PlayerTextDrawSetOutline(playerid, WarningTD[playerid][0], 3);
    PlayerTextDrawSetShadow(playerid, WarningTD[playerid][0], 0);
    PlayerTextDrawAlignment(playerid, WarningTD[playerid][0], 1);
    PlayerTextDrawColor(playerid, WarningTD[playerid][0], -1);
    PlayerTextDrawBackgroundColor(playerid, WarningTD[playerid][0], 255);
    PlayerTextDrawBoxColor(playerid, WarningTD[playerid][0], 269488383);
    PlayerTextDrawUseBox(playerid, WarningTD[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, WarningTD[playerid][0], 1);
    PlayerTextDrawSetSelectable(playerid, WarningTD[playerid][0], 0);

    WarningTD[playerid][1] = CreatePlayerTextDraw(playerid, 230.000000, 364.000000, "_");
    PlayerTextDrawFont(playerid, WarningTD[playerid][1], 1);
    PlayerTextDrawLetterSize(playerid, WarningTD[playerid][1], 0.649999, -0.050000);
    PlayerTextDrawTextSize(playerid, WarningTD[playerid][1], 412.500000, 75.500000);
    PlayerTextDrawSetOutline(playerid, WarningTD[playerid][1], 3);
    PlayerTextDrawSetShadow(playerid, WarningTD[playerid][1], 0);
    PlayerTextDrawAlignment(playerid, WarningTD[playerid][1], 1);
    PlayerTextDrawColor(playerid, WarningTD[playerid][1], -1);
    PlayerTextDrawBackgroundColor(playerid, WarningTD[playerid][1], 255);
    PlayerTextDrawBoxColor(playerid, WarningTD[playerid][1], 1097458175);
    PlayerTextDrawUseBox(playerid, WarningTD[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, WarningTD[playerid][1], 1);
    PlayerTextDrawSetSelectable(playerid, WarningTD[playerid][1], 0);

    WarningTD[playerid][2] = CreatePlayerTextDraw(playerid, 243.000000, 324.000000, "WARNING:");
    PlayerTextDrawFont(playerid, WarningTD[playerid][2], 1);
    PlayerTextDrawLetterSize(playerid, WarningTD[playerid][2], 0.229166, 1.050000);
    PlayerTextDrawTextSize(playerid, WarningTD[playerid][2], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, WarningTD[playerid][2], 0);
    PlayerTextDrawSetShadow(playerid, WarningTD[playerid][2], 0);
    PlayerTextDrawAlignment(playerid, WarningTD[playerid][2], 1);
    PlayerTextDrawColor(playerid, WarningTD[playerid][2], 1097458175);
    PlayerTextDrawBackgroundColor(playerid, WarningTD[playerid][2], 255);
    PlayerTextDrawBoxColor(playerid, WarningTD[playerid][2], 50);
    PlayerTextDrawUseBox(playerid, WarningTD[playerid][2], 0);
    PlayerTextDrawSetProportional(playerid, WarningTD[playerid][2], 1);
    PlayerTextDrawSetSelectable(playerid, WarningTD[playerid][2], 0);

    WarningTD[playerid][3] = CreatePlayerTextDraw(playerid, 238.000000, 333.000000, "Message");
    PlayerTextDrawFont(playerid, WarningTD[playerid][3], 1);
    PlayerTextDrawLetterSize(playerid, WarningTD[playerid][3], 0.150000, 0.750000);
    PlayerTextDrawTextSize(playerid, WarningTD[playerid][3], 400.000000, 17.000000);
    PlayerTextDrawSetOutline(playerid, WarningTD[playerid][3], 0);
    PlayerTextDrawSetShadow(playerid, WarningTD[playerid][3], 0);
    PlayerTextDrawAlignment(playerid, WarningTD[playerid][3], 1);
    PlayerTextDrawColor(playerid, WarningTD[playerid][3], -160);
    PlayerTextDrawBackgroundColor(playerid, WarningTD[playerid][3], 255);
    PlayerTextDrawBoxColor(playerid, WarningTD[playerid][3], 50);
    PlayerTextDrawUseBox(playerid, WarningTD[playerid][3], 0);
    PlayerTextDrawSetProportional(playerid, WarningTD[playerid][3], 1);
    PlayerTextDrawSetSelectable(playerid, WarningTD[playerid][3], 0);
    return 1;
}

forward warning_update(playerid);
public warning_update(playerid)
{
    if(loadingbar[playerid] > 104)
    {
        for(new i = 0; i < 4; i++)
            PlayerTextDrawDestroy(playerid, WarningTD[playerid][i]);
        return false;
    }
    SetTimerEx("warning_update", __Warning_Info[playerid][__timer], false, "i", playerid);
    PlayerTextDrawTextSize(playerid, WarningTD[playerid][1], 412.500000 - (loadingbar[playerid]*1.82), 1.0);
    PlayerTextDrawShow(playerid, WarningTD[playerid][1]);
    loadingbar[playerid] += 0.8;
    return CallLocalFunction(__Warning_Info[playerid][__callback], "if", playerid, loadingbar[playerid]);
}
