/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
/* zCatch by erd and Teetime                                                                 */

#ifndef GAME_SERVER_GAMEMODES_ZCATCH_H
#define GAME_SERVER_GAMEMODES_ZCATCH_H

#include <game/server/gamecontroller.h>
#include <thread>

class CGameController_zCatch: public IGameController
{
	int m_OldMode;
	int m_OldColor;
	int m_OldReleaseGame;
	
	void RewardWinner(int winnerId);
	
	/* ranking system */
	static void ChatCommandTopFetchDataAndPrint(CGameContext* GameServer, int clientId, const char *column);
	static void ChatCommandRankFetchDataAndPrint(CGameContext* GameServer, int clientId, char *name);
	static void SaveScore(CGameContext* GameServer, char *name, int score, int numWins, int numKills, int numKillsWallshot, int numDeaths, int numShots, int highestSpree, int timePlayed);
	static void FormatRankingColumn(const char* column, char buf[32], int value);

public:
	CGameController_zCatch(class CGameContext *pGameServer);
	~CGameController_zCatch();
	virtual void Tick();
	virtual void DoWincheck();

	virtual void StartRound();
	virtual void OnCharacterSpawn(class CCharacter *pChr);
	virtual void OnPlayerInfoChange(class CPlayer *pP);
	virtual int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int WeaponID);
	virtual bool OnEntity(int Index, vec2 Pos);
	virtual bool CanChangeTeam(CPlayer *pPlayer, int JoinTeam);
	virtual void EndRound();
	
	/* ranking system */
	virtual void SaveRanking(CPlayer *player);
	virtual void OnInitRanking(sqlite3 *rankingDb);
	virtual void OnChatCommandTop(CPlayer *pPlayer, const char *category = "");
	virtual void OnChatCommandOwnRank(CPlayer *pPlayer);
	virtual void OnChatCommandRank(CPlayer *pPlayer, const char *name);
};

#endif
