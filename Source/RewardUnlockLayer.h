#pragma once

#include "PopupLayer.h"
#include "RewardUnlockLayer.h"
#include "getGJRewards.h"
#include "GJChestSprite.h"

class RewardUnlockLayer;
class MenuItemSpriteExtra;

namespace ax 
{ 
	class Node;
	class Scene;
	class Object;
	class Label;
	namespace network 
	{ 
		class HttpRequest; 
		class HttpClient;
		class HttpResponse;
	} 
}

class RewardUnlockLayer : public PopupLayer
{
private:
	GJChestSprite* _chestObj;
	MenuItemSpriteExtra* _rewardBtn;
	MenuItemSpriteExtra* _closeBtn;
	ax::Label* _errorMsg;
public:
	static RewardUnlockLayer* create(int chestID);

	bool init(int chestID);
	void playRewardEffect(getGJRewards* rewards);
	void onHttpRequestCompleted(ax::network::HttpClient* sender, ax::network::HttpResponse* response, int chestID);
	void sendHttpRequest(int chestID);
};