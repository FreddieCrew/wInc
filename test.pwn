#include <a_samp>
#include <winc>

main() {}

public OnGameModeInit() {

	return 1;
}

public OnPlayerConnect(playerid) {
	CreateWarning(playerid, "Missing", "Warning:", "You are missing nothing?", 10);
	return 1;
}

Warning:Missing(playerid, Float:td) {
	if(td >= 50) return SendClientMessage(playerid, -1, "Make sure than you're missing nothing.");
	return 1;
}
