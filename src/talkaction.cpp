/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2014  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "otpch.h"

#include <fstream>
#include "player.h"
#include "talkaction.h"
#include "pugicast.h"
#include "tools.h"

TalkActions::TalkActions()
	: m_scriptInterface("TalkAction Interface")
{
	m_scriptInterface.initState();
}

TalkActions::~TalkActions()
{
	clear();
}

void TalkActions::clear()
{
	for (TalkAction* talkAction : talkActions) {
		delete talkAction;
	}
	talkActions.clear();

	m_scriptInterface.reInitState();
}

LuaScriptInterface& TalkActions::getScriptInterface()
{
	return m_scriptInterface;
}

std::string TalkActions::getScriptBaseName()
{
	return "talkactions";
}

Event* TalkActions::getEvent(const std::string& nodeName)
{
	if (asLowerCaseString(nodeName) == "talkaction") {
		return new TalkAction(&m_scriptInterface);
	}
	return nullptr;
}

bool TalkActions::registerEvent(Event* event, const pugi::xml_node&)
{
	TalkAction* talkAction = dynamic_cast<TalkAction*>(event);
	if (!talkAction) {
		return false;
	}

	talkActions.push_back(talkAction);
	return true;
}

TalkActionResult_t TalkActions::playerSaySpell(Player* player, SpeakClasses type, const std::string& words) const
{
	size_t wordsLength = words.length();
	for (TalkAction* talkAction : talkActions) {
		const std::string& talkactionWords = talkAction->getWords();
		size_t talkactionLength = talkactionWords.length();
		if (wordsLength < talkactionLength || strncasecmp(words.c_str(), talkactionWords.c_str(), talkactionLength) != 0) {
			continue;
		}

		std::string param;
		if (wordsLength != talkactionLength) {
			param = words.substr(talkactionLength);
			if (param.front() != ' ') {
				continue;
			}
			trim_left(param, ' ');

			char separator = talkAction->getSeparator();
			if (separator != ' ') {
				if (!param.empty()) {
					if (param.front() != separator) {
						continue;
					} else {
						param.erase(param.begin());
					}
				}
			}
		}

		if (talkAction->getAccess() > player->getGroup()->id) {
			return TALKACTION_CONTINUE;
		}

		if (talkAction->getAccountType() > player->getAccountType()) {
			return TALKACTION_CONTINUE;
		}

		if (talkAction->getLogged()) {
			player->sendTextMessage(MESSAGE_STATUS_CONSOLE_RED, words);

			std::ostringstream logFile;
			logFile << "data/logs/" << player->getName() << " commands.log";
			std::ofstream out(logFile.str(), std::ios::app);
			if (out.is_open()) {
				time_t ticks = time(nullptr);
				const tm* now = localtime(&ticks);
				char buf[32];
				strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M", now);

				out << '[' << buf << "] " << words << std::endl;
				out.close();
			}
		}

		if (talkAction->executeSay(player, talkactionWords, param, type)) {
			return TALKACTION_CONTINUE;
		} else {
			return TALKACTION_BREAK;
		}
	}
	return TALKACTION_CONTINUE;
}

TalkAction::TalkAction(LuaScriptInterface* _interface) :
	Event(_interface)
{
	separator = '"';
	access = 0;
	logged = false;
	accountType = AccountType_t::ACCOUNT_TYPE_NORMAL;
}

TalkAction::~TalkAction()
{
	//
}

bool TalkAction::configureEvent(const pugi::xml_node& node)
{
	pugi::xml_attribute wordsAttribute = node.attribute("words");
	if (!wordsAttribute) {
		std::cout << "[Error - TalkAction::configureEvent] Missing words for talk action or spell" << std::endl;
		return false;
	}

	pugi::xml_attribute separatorAttribute = node.attribute("separator");
	if (separatorAttribute) {
		separator = pugi::cast<char>(separatorAttribute.value());
	}

	pugi::xml_attribute accessAttribute = node.attribute("groupId");
	if (accessAttribute) {
		access = pugi::cast<uint32_t>(accessAttribute.value());
	}

	pugi::xml_attribute accountTypeAttribute = node.attribute("accountType");
	if (accountTypeAttribute) {
		accountType = (AccountType_t)pugi::cast<uint32_t>(accountTypeAttribute.value());
	}

	pugi::xml_attribute logAttribute = node.attribute("log");
	if (logAttribute) {
		logged = booleanString(logAttribute.as_string());
	}

	words = wordsAttribute.as_string();
	return true;
}

std::string TalkAction::getScriptEventName()
{
	return "onSay";
}

bool TalkAction::executeSay(const Player* player, const std::string& words, const std::string& param, SpeakClasses type) const
{
	//onSay(cid, words, param, type)
	if (!m_scriptInterface->reserveScriptEnv()) {
		std::cout << "[Error - TalkAction::executeSay] Call stack overflow" << std::endl;
		return false;
	}

	ScriptEnvironment* env = m_scriptInterface->getScriptEnv();
	env->setScriptId(m_scriptId, m_scriptInterface);

	lua_State* L = m_scriptInterface->getLuaState();

	m_scriptInterface->pushFunction(m_scriptId);
	lua_pushnumber(L, player->getID());
	LuaScriptInterface::pushString(L, words);
	LuaScriptInterface::pushString(L, param);
	lua_pushnumber(L, type);

	return m_scriptInterface->callFunction(4);
}
