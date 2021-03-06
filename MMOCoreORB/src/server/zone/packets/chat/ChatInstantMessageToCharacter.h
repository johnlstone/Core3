/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef CHATINSTANTMESSAGETOCHARACTER_H_
#define CHATINSTANTMESSAGETOCHARACTER_H_

#include "server/zone/packets/MessageCallback.h"
#include "server/chat/ChatManager.h"

namespace server {
namespace zone {
namespace packets {
namespace chat {

class ChatInstantMessageToCharacter : public MessageCallback {
	String game;
	String galaxy;
	String name;
	UnicodeString message;

	uint32 sequence;
public:
	ChatInstantMessageToCharacter(ZoneClientSession* client, ZoneProcessServer* server) :
		MessageCallback(client, server), sequence(0) {

	}

	void parse(Message* pack) {
		pack->parseAscii(game);
		pack->parseAscii(galaxy);

		pack->parseAscii(name);
		
		pack->parseUnicode(message);
		
		pack->shiftOffset(4);
		
		sequence = pack->parseInt();
	}
	
	void run() {
		ChatManager* chatManager = server->getChatManager();

		chatManager->handleChatInstantMessageToCharacter(this);
	}

	inline const String& getName() const {
		return name;
	}

	inline const String& getGalaxy() const {
		return galaxy;
	}

	inline const String& getGame() const {
		return game;
	}

	inline const UnicodeString& getMessage() const {
		return message;
	}

	inline int getSequence() const {
		return sequence;
	}

};

}
}
}
}

using namespace server::zone::packets::chat;

#endif /*CHATINSTANTMESSAGETOCHARACTER_H_*/
